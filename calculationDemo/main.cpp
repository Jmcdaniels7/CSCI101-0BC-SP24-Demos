#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>

enum suitType
{
    DIAMOND,
    CLUB,
    HEART,
    SPADE,
    DEFAULTS
};

enum rankType
{
    A,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    J,
    Q,
    K,
    DEFAULTR
};

enum choiceType
{
    DRAW,
    PLAYDRAW,
    FINISH,
    PLAYWASTE,
    DISPLAY
};

const rankType ranks[] = {A,
                          TWO,
                          THREE,
                          FOUR,
                          FIVE,
                          SIX,
                          SEVEN,
                          EIGHT,
                          NINE,
                          TEN,
                          J,
                          Q,
                          K,
                          DEFAULTR};
const suitType suits[] = {DIAMOND,
                          CLUB,
                          HEART,
                          SPADE,
                          DEFAULTS};
const std::string rankStr[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", " "};
const std::string suitStr[] = {"♦", "♣", "♥", "♠", " "};
const int DECK_SIZE = 52;
const int NUM_PILES = 4;
const int NUM_SUITS = 5;
const int NUM_RANKS = 14;

struct cardType
{
    suitType suit = DEFAULTS;
    rankType rank = DEFAULTR;
    bool used = false;
};

struct deckType
{
    cardType cards[DECK_SIZE];
    int next = -1;
    int remain = DECK_SIZE;
};
struct pileType
{
    cardType cards[DECK_SIZE];
    int topCard = -1;
};

void setUpDeck(deckType &theDeck, pileType foundations[], int numFoundations);
void shuffleDeck(deckType &theDeck);
void setUpFirstFoundationCard(deckType &theDeck, pileType foundations[], int numFoundations);
std::string printCard(cardType theCard);
std::string printASCIICard(cardType theCard);
std::string printASCIIPiles(pileType piles[], int numPiles);
void printGamePlayArea(pileType foundations[], pileType wastes[], int numPiles, deckType &theDeck, bool drawnCard);
void resetStream();
choiceType displayMenu(bool drawnCard, bool waste, bool noCards);
void processChoice(bool &drawn, choiceType choice, deckType &theDeck, pileType foundations[], pileType wastes[], int numPiles, bool &finished);
void drawCard(deckType &theDeck);
void playDrawnCard(deckType &theDeck, pileType foundations[], pileType wastes[], int numPiles, bool &drawnCard);
bool playFoundation(cardType card, pileType &foundation);
void playFromWaste(pileType foundations[], pileType wastes[]);
void displayWaste(pileType &wastePile);
int chooseWaste();
int calculateScore(deckType &theDeck, pileType wastes[]);

int main()
{
    // srand(time(0)); //uncomment for not pseudo-random numbers.
    deckType gameDeck;
    pileType foundationPiles[NUM_PILES];
    pileType wastePiles[NUM_PILES];

    setUpDeck(gameDeck, foundationPiles, NUM_PILES);
    shuffleDeck(gameDeck);
    setUpFirstFoundationCard(gameDeck, foundationPiles, NUM_PILES);
    bool finished = false;
    bool drawnCard = false;
    choiceType choice;
    while (!finished)
    {
        printGamePlayArea(foundationPiles, wastePiles, NUM_PILES, gameDeck, drawnCard);
        bool isWaste, noCards;
        isWaste = false;
        for (int i = 0; i < NUM_PILES; i++)
        {
            if (wastePiles[i].topCard > -1)
            {
                isWaste = true;
                break;
            }
        }
        noCards = gameDeck.remain <= 0;
        choice = displayMenu(drawnCard, isWaste, noCards);
        processChoice(drawnCard, choice, gameDeck, foundationPiles, wastePiles, NUM_PILES, finished);
    }
    int score = calculateScore(gameDeck, wastePiles);
    if (score == 0)
    {
        std::cout << "You won! You scored 0 points." << std::endl;
    }
    else
    {
        std::cout << "Game Over! You scored " << score << " points." << std::endl;
    }

    return 0;
}

void setUpDeck(deckType &theDeck, pileType foundations[], int numFoundations)
{
    for (int i = 0; i < NUM_SUITS - 1; i++) // loops through each suit
    {
        for (int j = 0; j < NUM_RANKS - 1; j++) // loops through each rank for each suit
        {
            cardType newCard;
            newCard.suit = suits[i]; // sets the suit of the card to the current suit
            newCard.rank = ranks[j]; // sets the rank to the current rank
            newCard.used = false;
            theDeck.cards[i * (NUM_RANKS - 1) + j] = newCard;                   // takes the card with the current suit and rank and adds it to the next position in the deck
            foundations[i].cards[j].rank = ranks[((i + 1) * (j + 1) - 1) % 13]; // prefills the foundation sequence with the correct ranks
        }
        foundations[i].topCard = -1;
    }
}

void shuffleDeck(deckType &theDeck)
{
    cardType shuffled[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int shuffledCardIndex;
        do
        {
            shuffledCardIndex = rand() % DECK_SIZE;
        } while (theDeck.cards[shuffledCardIndex].used);
        shuffled[i] = theDeck.cards[shuffledCardIndex];
        theDeck.cards[shuffledCardIndex].used = true;
    }
    for (int i = 0; i < DECK_SIZE; i++)
    {
        theDeck.cards[i] = shuffled[i];
        theDeck.cards[i].used = false;
    }
}

void setUpFirstFoundationCard(deckType &theDeck, pileType foundations[], int numFoundations)
{
    for (int i = 0; i < numFoundations; i++)
    {
        for (int j = 0; j < DECK_SIZE; j++)
        {
            if (theDeck.cards[j].rank == foundations[i].cards[0].rank)
            {
                foundations[i].cards[0] = theDeck.cards[j];
                theDeck.cards[j].used = true;
                break;
            }
        }
        foundations[i].topCard++;
        theDeck.remain--;
    }
}

std::string printCard(cardType theCard)
{
    std::string output; // A♥,  ♥A, or Ace of ♥
    output = rankStr[theCard.rank] + suitStr[theCard.suit];
    return output;
}

std::string printASCIICard(cardType theCard)
{
    std::ostringstream output;
    if (theCard.rank != DEFAULTR && theCard.suit != DEFAULTS)
    {
        output << "┌─────────┐ " << std::endl;
        output << std::setfill(' ') << std::left;
        output << "│ " << std::setw(8);
        output << rankStr[theCard.rank];
        output << "│ " << std::endl;
        output << "│" << std::setw(9) << " "
               << "│ " << std::endl;
        output << std::right;
        output << "│" << std::setw(7);
        output << suitStr[theCard.suit];
        output << std::setw(4) << " "
               << "│ " << std::endl;
        output << "│" << std::setw(9) << " "
               << "│ " << std::endl;
        output << "│" << std::setw(8);
        output << rankStr[theCard.rank];
        output << " │ " << std::endl;
        output << "└─────────┘ " << std::endl;
    }
    else
    {
        output << "┌─────────┐" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "└─────────┘" << std::endl;
    }

    return output.str();
}

std::string printASCIIPiles(pileType piles[], int numPiles)
{
    std::ostringstream output;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  ┌─────────┐  ";
    }
    output << std::endl
           << " ";
    for (int i = 0; i < numPiles; i++)
    {
        output << std::setfill(' ') << std::left;
        output << " │ " << std::setw(8);
        if (piles[i].topCard > -1)
        {
            output << rankStr[piles[i].cards[piles[i].topCard].rank];
        }
        else
        {
            output << " ";
        }
        output << "│   ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  │" << std::setw(9) << " "
               << "│  ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << std::right;
        output << "  │";
        if (piles[i].topCard > -1)
        {
            output << std::setw(7);
            output << suitStr[piles[i].cards[piles[i].topCard].suit];
        }
        else
        {
            output << std::setw(5);
            output << " ";
        }
        output << std::setw(4) << " "
               << "│  ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  │" << std::setw(9) << " "
               << "│  ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  │" << std::setw(8);
        if (piles[i].topCard > -1)
        {
            output << rankStr[piles[i].cards[piles[i].topCard].rank];
        }
        else
        {
            output << " ";
        }
        output << " │  ";
    }
    output << std::endl;

    for (int i = 0; i < numPiles; i++)
    {
        output << i + 1 << " └─────────┘  ";
    }
    output << std::endl;
    return output.str();
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printGamePlayArea(pileType foundations[], pileType wastes[], int numPiles, deckType &theDeck, bool drawnCard)
{
    std::cout << "Foundation Piles:" << std::endl;
    std::cout << printASCIIPiles(foundations, numPiles) << std::endl;
    std::cout << "Waste Piles:" << std::endl;
    std::cout << printASCIIPiles(wastes, numPiles) << std::endl;
    if (drawnCard)
    {
        std::cout << "Drawn Card:" << std::endl;
        std::cout << printASCIICard(theDeck.cards[theDeck.next]) << std::endl;
    }
    else
    {
        std::cout << "Remaining Cards (" << theDeck.remain << ")" << std::endl;
        cardType c;
        std::cout << printASCIICard(c);
    }
}

choiceType displayMenu(bool drawnCard, bool waste, bool noCards)
{
    int choice;
    std::cout << "What would you like to do: (Enter -1 to quit)" << std::endl;
    if (!drawnCard && !noCards)
    {
        std::cout << "1. Draw Card" << std::endl;
    }
    else if (drawnCard)
    {
        std::cout << "1. Play Drawn Card" << std::endl;
    }
    else if (noCards)
    {
        std::cout << "1. Finish Game and Calculate Score" << std::endl;
    }
    if (waste)
    {
        std::cout << "2. Play Card from Waste Pile" << std::endl;
        std::cout << "3. Display an Entire Waste Pile" << std::endl;
    }
    std::cin >> choice;
    if (choice == -1)
    {
        return FINISH;
    }
    while (!std::cin || choice < 1 || (waste && choice > 3) || (!waste && choice > 1))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is an invalid choice" << std::endl;
        std::cin >> choice;
    }
    if (choice == 1)
    {
        if (!drawnCard && !noCards)
        {
            return DRAW;
        }
        else if (drawnCard)
        {
            return PLAYDRAW;
        }
        else if (noCards)
        {
            return FINISH;
        }
    }
    else if (choice == 2)
    {
        return PLAYWASTE;
    }
    else if (choice == 3)
    {
        return DISPLAY;
    }
    return FINISH;
}

void processChoice(bool &drawn, choiceType choice, deckType &theDeck, pileType foundations[], pileType wastes[], int numPiles, bool &finished)
{
    switch (choice)
    {
    case DRAW:
        drawCard(theDeck);
        drawn = true;
        break;
    case PLAYDRAW:
        playDrawnCard(theDeck, foundations, wastes, numPiles, drawn);
        break;
    case PLAYWASTE:
    case DISPLAY:
    case FINISH:
        finished = true;
    }
}

void drawCard(deckType &theDeck)
{
    do
    {
        theDeck.next++;
    } while (theDeck.cards[theDeck.next].used);

    theDeck.remain--;
}

void playDrawnCard(deckType &theDeck, pileType foundations[], pileType wastes[], int numPiles, bool &drawnCard)
{
    char typeOfPile;
    int p;
    std::cout << "Do you want to play on a:" << std::endl;
    std::cout << "F. Foundation Pile" << std::endl;
    std::cout << "W. Waste Pile" << std::endl;
    std::cin >> typeOfPile;
    typeOfPile = toupper(typeOfPile);
    while (typeOfPile != 'F' && typeOfPile != 'W')
    {
        std::cout << "I do not understand. I am expecting F or W." << std::endl;
        std::cout << "Do you want to play on a:" << std::endl;
        std::cout << "F. Foundation Pile" << std::endl;
        std::cout << "W. Waste Pile" << std::endl;
        std::cin >> typeOfPile;
        typeOfPile = toupper(typeOfPile);
    }
    std::string pileTypeString; // std::string pileTypeString = typeOfPile == 'F' ? "foundation" : "waste";
    if (typeOfPile == 'F')
    {
        pileTypeString = "foundation";
    }
    else
    {
        pileTypeString = "waste";
    }
    std::cout << "Which " << pileTypeString << " pile (1-4) do you want to play on? ";
    std::cin >> p;
    std::cout << std::endl;
    while (!std::cin || p < 1 || p > 4)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid " << pileTypeString << " pile." << std::endl;
        std::cout << "Which " << pileTypeString << " pile (1-4) do you want to play on? ";
        std::cin >> p;
        std::cout << std::endl;
    }
    if (typeOfPile == 'F')
    {
        if (playFoundation(theDeck.cards[theDeck.next], foundations[p - 1]))
        {
            theDeck.cards[theDeck.next].used = true;
            drawnCard = false;
        }
    }
    else
    {
        wastes[p - 1].cards[wastes[p - 1].topCard + 1] = theDeck.cards[theDeck.next];
        wastes[p - 1].topCard++;
        theDeck.cards[theDeck.next].used = true;
        drawnCard = false;
    }
}

bool playFoundation(cardType card, pileType &foundation)
{
    if (foundation.cards[foundation.topCard + 1].rank == card.rank)
    {
        foundation.cards[foundation.topCard + 1] = card;
        foundation.topCard++;
        return true;
    }
    else
    {
        std::cout << "That is an invalid play. The next card for that pile is a ";
        std::cout << rankStr[foundation.cards[foundation.topCard + 1].rank] << std::endl;
        return false;
    }
}

void playFromWaste(pileType foundations[], pileType wastes[])
{
    int wastePileNum;
    int foundPileNum;
    std::cout << "Which waste pile (1-4) do you want to play from? ";
    std::cin >> wastePileNum;
    while (!std::cin || wastePileNum < 1 || wastePileNum > 4)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid waste pile." << std::endl;
        std::cout << "Which waste pile (1-4) do you want to play from? ";
        std::cin >> wastePileNum;
    }
    std::cout << "Which foundation pile (1-4) do you want to play on? ";
    std::cin >> foundPileNum;
    while (!std::cin || foundPileNum < 1 || foundPileNum > 4)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid foundation pile." << std::endl;
        std::cout << "Which foundation pile (1-4) do you want to play on? ";
        std::cin >> foundPileNum;
    }
    cardType card = wastes[wastePileNum - 1].cards[wastes[wastePileNum - 1].topCard];
    if (playFoundation(card, foundations[foundPileNum - 1]))
    {
        wastes[wastePileNum - 1].topCard--;
    }
}

void displayWaste(pileType &wastePile)
{
    for (int i = wastePile.topCard; i >= 0; i--)
    {
        std::cout << printASCIICard(wastePile.cards[i]) << std::endl;
    }
}

int chooseWaste()
{
    int wastePileNum;
    std::cout << "Which waste pile (1-4) do you want to see? ";
    std::cin >> wastePileNum;
    while (!std::cin || wastePileNum < 1 || wastePileNum > 4)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid waste pile." << std::endl;
        std::cout << "Which waste pile (1-4) do you want to see? ";
        std::cin >> wastePileNum;
    }
    return wastePileNum - 1;
}

int calculateScore(deckType &theDeck, pileType wastes[])
{
    int score = 0;
    for (int i = 0; i < NUM_PILES; i++)
    {
        score += wastes[i].topCard + 1;
    }
    score += theDeck.remain;
    return score;
}
