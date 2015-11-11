/*
  main.c
  suit

 This program simulates a card game with a deck of 52 cards and 4 suits.
 User input is accepted via the terminal with two arguments. Argument 1 
 determines the number of cards to deal per hand/player and the Argument 2
 determines the number of players. Reasonable computation is performed so
 the values do not violate the deck size. For example max number of cards 
 per 4 players is 13 since the product of the two is 52 (the size of the deck).
 But the product of 14 cards per hand/player and 4 players is not permitted. 
 In that case the program will terminate with an error message. Other attributes
 include shuffling and dealing the deck and displaying both deck and hands.
 
  Created by Paola Jiron on 10/20/15.
  Copyright © 2015 Paola Jiron. All rights reserved.

*/
#include "suit.h"

int main(int argc, const char * argv[]) {
    
    /* local variables used here */
    
    int max, numCardsPerHand, numOfPlayers, i, cardsPtr = 0, *ptr = &cardsPtr;
    struct deck thedeck, *pointer = &thedeck;
    thedeck = createDeck();
    struct players gamer [MAX_NUM_PLAYERS];
    
    /* validation of user input. No more than 3 args. */
    
    if( argc == ARGNUM ){
        
        /* parse the arguments to integer values 
           and compute maximum legal values allowed
           for game */
        
        numCardsPerHand = atoi(argv[CARD_INPUT]);
        numOfPlayers = atoi(argv[PLAYER_INPUT]);
        max = (numCardsPerHand * numOfPlayers);
        
        if((max > DECK_SIZE) || (max == 0) || (numOfPlayers < PLAYER_MIN) ||
           (numOfPlayers > MAX_NUM_PLAYERS) || (numCardsPerHand < MIN_CARDS_PER_HAND) || numCardsPerHand > MAX_CARDS_PER_HAND){
 
            printf("Your values are not correct. Try again.\n");
            
        }else{
            /* create and display deck, shuffle the deck,
                deal and display hands */
            
            thedeck = createDeck();
            printf("\nThe standard deck:\n\n");
            printDeck(pointer);
            printf("\nThe shuffled deck:\n\n");
            shuffle(pointer);
            printDeck(pointer);
            
            for (i = 0; i < numCardsPerHand; i++) {
                gamer[i] =  getHand(numCardsPerHand, pointer, ptr);
            }
            
            deal(pointer, numCardsPerHand, numOfPlayers);
   
            
        }
    }else{
        /* here as specified, display error and terminate due to incorrect number of args entered by user */
        
        printf("Sorry that is incorrect. You must enter the number of cards per hand\n");
        printf("followed by the number of players separated by a space.\n\n");
    }
    
    return 0;
}
