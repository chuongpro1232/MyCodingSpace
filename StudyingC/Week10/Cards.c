#include <stdio.h>
#include <string.h>

typedef enum
{
    SPADES = 1,
    CLUBS,
    DIAMONDS,
    HEARTS
} suittype;

typedef enum
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} ranktype;

typedef struct
{
    suittype suit; // 1 to 4
    ranktype rank; // 1 to 13
} cardtype;

const int DECK_SIZE = 52; // 52 cards
const int RANK_SIZE = 13;

// Function to init all cards in standard order
void init(cardtype cards[])
{
    for (int i = 0; i < DECK_SIZE; i++)
    {
        cards[i].suit = i / RANK_SIZE + 1; // make 13 cards in the same suit
        cards[i].rank = i % RANK_SIZE + 1;

        /* It will be initialized as below:
         spades: ace - two - three - ... - king,
         clubs: ace - two - three - ... - king
         .....
        */
    }
}

// Function to convert rank number to string
char *ranktostr(ranktype rank, char *str)
{
    const char *ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                           "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    strcpy(str, ranks[rank - 1]);
    return str;
}

// Function to convert suit number to string
char *suittostr(suittype suit, char *str)
{
    const char *suits[] = {"Spades", "Clubs", "Diamonds", "Hearts"};
    strcpy(str, suits[suit - 1]);
    return str;
}

// Function to print out info of all cards
void print(cardtype cards[])
{
    const int RANK_STR_SIZE = 6;
    const int SUIT_STR_SIZE = 9;
    char rankstr[RANK_STR_SIZE], suitstr[SUIT_STR_SIZE];

    for (int i = 0; i < DECK_SIZE; i++)
    {
        printf("%s of %s\n", ranktostr(cards[i].rank, rankstr),
               suittostr(cards[i].suit, suitstr));
    }
}

int main()
{
    cardtype cards[DECK_SIZE];
    init(cards);
    print(cards);

    return 0;
}