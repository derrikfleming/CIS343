/********************************************************************/
/* Connect-X                                                        */
/*    connectx.c                                                    */
/* Author                                                           */
/*  Derrik Fleming                                                  */
/*  CIS343-01 with Prof Ira Woodring                                */
/********************************************************************/
/* ConnectX.c runs the game loop for the Connect-X game. It prints  */
/* pre-game welcome message, and game play commences as the game    */
/* loop is entered. When the gameComplete flag is set the loop      */
/* exits and a post game message is printed to the console          */
/* alerting the player's the game has been won, and provides them   */
/* with post game options.                                          */
/*                                                                  */
/********************************************************************/


#include <string.h>
#include "handler.h"
#include "game.h"

/********************************************************************/
/* Prints a representation of the current board to the console.     */
/*                                                                  */
/********************************************************************/
void printBoard(int *board, int w, int h) {
    for (int i = h - 1; i >= 0; i--) {
        printf("|");
        for (int j = 0; j < w; j++) {
            printf("| %d |", board[i * w + j]);
        }
        printf("|\n");
    }
    printf("\n\n");
}

int main(int argc, char** argv) {
    int* board;
    int bHeight = 7;
    int bWidth = 7;
    int toWin = 4;
    int pNum = 1;
    int isComplete = 0;
    struct arguments args;
    int index=0;


    setup(argc, argv, &args);
    bWidth = args.width;
    bHeight = args.height;
    toWin = args.connect;

    if((toWin > bWidth && toWin > bHeight) || bHeight < 2 || bWidth < 2 || toWin < 2){
        printf("Invalid game settings detected.\n");
        printf("Reverting to default game type.\n");
        bHeight = 7;
        bWidth = 7;
        toWin = 4;
    }

    createBoard(&board, bWidth, bHeight);
    int size = bHeight * bWidth;

    while(isComplete == 0) {
        int pCol = -1;
        char input[30];
        printBoard(board, bWidth, bHeight);
        do {

            printf("Player %i, select a column (1-%i): ", pNum, bWidth);

            scanf("%s", input);
            if(strcmp("s", input) == 0 || strcmp("-s", input) == 0){
                printf("Please enter a filename: ");
                scanf("%s", input);
                if(saveGame(input, board, bWidth, bHeight, toWin) == 0){
                    printf("Game Saved\n\n");
                }
            }
            if(strcmp("l", input) == 0 || strcmp("-l", input) == 0){
               // printf("Functionality not yet implemented.\n\n");

                printf("Please enter a filename: ");
                scanf("%s", input);
                if(loadGame(input, &board, &bWidth, &bHeight, &toWin) == 0){
                    printf("Game loaded!\n\n");
                    pNum = 2;
                }

            }
            pCol = atoi(input);
            if (pCol > bWidth){
                printf("Invalid column choice. Column choice"
                    " made by column of index entered.\n");
                pCol = (pCol % bWidth) + 1;
                break;
            }

        } while(pCol == -1);
        
        // stores value of the index the player played at
        index = move(board, pNum, bWidth, bHeight, pCol);


        // check if last played piece caused end-game state
        // passing the last played index in to check
        // if in coincides with a series larger than toWin 
        isComplete = gameState(board, pNum, index, bWidth,
                                bHeight, size, toWin);
        // End Game prompt
        if(isComplete != 0){
            printf("************************************\n");
            if(isComplete == 1)
                printf("*  Congrats Player %i, you've won!  *\n", pNum);
            if(isComplete == 2)
                printf("*        Draw! Board is full       *\n");
            printf("************************************\n\n\n");
            printBoard(board, bWidth, bHeight);
            char playAgain[30];
            while(isComplete == 1){
                printf("Play again (y/n)? ");
                scanf("%s", playAgain);
                if(strcmp("y", playAgain) == 0 || strcmp("yes", playAgain) == 0){
                    isComplete = 0;
                    pNum = 2;
                    createBoard(&board, bWidth, bHeight);
                }
                if(strcmp("n", playAgain) == 0 || strcmp("no", playAgain) == 0){
                    printf("Exiting!\n\n");
                    exit(0);
                }
            }
        }
        

        // player's turn over
        pNum = pNum == 1 ? 2 : 1;

    }
    free(board);
    return 0;
}