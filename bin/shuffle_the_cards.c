/**
 * @file shuffle_the_cards.cpp
 *
 * @version 01.01 2020-08-15
 *
 * @brief This is a c code to shuffle the cards "vitually"
 *
 * @ingroup shuffle_the_cards
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// Struct
typedef struct
{
	const char *face;
	const char *suit;
} Card;

// Functions
void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[]);
void shuffle(Card *const wDeck);
void deal(const Card *const wDeck);

int main()
{
	Card deck[CARDS];
	srand(time(NULL));

	const char *face[] = {"Ace", "Deuce", "Tree", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);

	return 0;
}

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[])
{
	for(size_t i = 0; i < CARDS; i++)
	{
		wDeck[i].face = wFace[i % FACES];
		wDeck[i].suit = wSuit[i / FACES];
	}
}

void shuffle(Card *const wDeck)
{
	for(size_t i = 0; i < CARDS; i++)
	{
		int j = rand() % CARDS;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card *const wDeck)
{
	for(size_t i = 0; i < CARDS; i++)
	{
		printf("%2ld) %5s of %-8s\n", i+1, wDeck[i].face, wDeck[i].suit);
	}
}
