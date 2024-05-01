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

int main()
{
    deckType gameDeck;
    pileType foundationPiles[NUM_PILES];
    pileType wastePiles[NUM_PILES];

    setUpDeck(gameDeck, foundationPiles, NUM_PILES);
    shuffleDeck(gameDeck);
    setUpFirstFoundationCard(gameDeck, foundationPiles, NUM_PILES);
    printGamePlayArea(foundationPiles, wastePiles, NUM_PILES, gameDeck, false);

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
