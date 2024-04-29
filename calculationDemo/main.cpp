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

int main()
{
    deckType gameDeck;
    pileType foundationPiles[NUM_PILES];
    pileType wastePiles[NUM_PILES];

    setUpDeck(gameDeck, foundationPiles, NUM_PILES);
    shuffleDeck(gameDeck);

    return 0;
}

void setUpDeck(deckType &theDeck, pileType foundations[], int numFoundations)
{
    for (int i = 0; i < NUM_SUITS - 1; i++)
    {
        for (int j = 0; j < NUM_RANKS - 1; j++)
        {
            cardType newCard;
            newCard.suit = suits[i];
            newCard.rank = ranks[j];
            newCard.used = false;
            theDeck.cards[i * (NUM_RANKS - 1) + j] = newCard;
            foundations[i].cards[j].rank = ranks[((i + 1) * (j + 1) - 1) % 13];
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