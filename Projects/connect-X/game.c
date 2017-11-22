/********************************************************************/
/* Game.c                                                           */
/* Author:                                                          */
/*  Derrik Fleming                                                  */
/*  CIS343-01 with Prof Ira Woodring                                */
/********************************************************************/
/* The following methods aid in the game play of ConnectX. For ref  */
/* the allocated memory is analogous to a Connect 4 game board in   */
/* that: Example: Default Board 7 x 7:                              */
/*                                                                  */
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[42] through board[48]*/
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[35] through board[41]*/
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[28] through board[34]*/
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[21] through board[27]*/
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[14] through board[20]*/
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[7]  through board[13]*/
/* || 0 || 0 || 0 || 0 || 0 || 0 || 0 || board[0]  through board[6] */
/* -------------------------------------                            */
/* || 1 || 2 || 3 || 4 || 5 || 6 || 7 ||                            */
/*                COLUMNS                                           */
/*                                                                  */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "game.h"

/********************************************************************/
/* This method checks if any win conditions have been met. The last */
/* played index is passed in, if it coincides with a series of      */
/* indexes that are also associated with the same player whose sum  */
/* is greater than toWin, isComplete's value is set to 1,           */
/* indicating the game has been one by pNum.                        */
/*                                                                  */
/********************************************************************/
int gameState(int *board, int pNum, int index, int w, int h,
                  int size, int toWin) {
    // isComplete 0 by default
    int isComplete = 0;

    // check for win
    if (checkRow(board, pNum, index, w, h, size) >= toWin ||
            checkCol(board, pNum, index, w, h, size) >= toWin ||
            checkDiag1(board, pNum, index, w, h, size) >= toWin ||
            checkDiag2(board, pNum, index, w, h, size) >= toWin){
        // isComplete TRUE
        isComplete = 1;
    }
    if (boardNotFull(board, w, h, size) == 0)
        isComplete = 2;

    return isComplete;
}

/********************************************************************/
/* This method returns the sum of the row series board[index] is a  */
/* part of.                                                         */
/*                                                                  */
/********************************************************************/
int checkRow(int *board, int pNum, int index, int w,
             int h, int size) {
    int count = 0;
    //printf("CHECK ROW FROM INDEX %i: \n\n", index);
    // look "left"
    // iterates across row of index in "left" direction
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index; i >= 0 ; i--) {
        if (board[i] == pNum) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        if (i % w == 0 || board[i] != pNum) {
            //printf("Exit on: %i\n\n", i);
            break;
        }
    }

    // look "right"
    // iterates across row of index in "right" direction
    // break on perimeter col (index % w == w - 1) or
    // when board[index] != pNum
    for (int i = index; i < size ; i++) {
        if (board[i] == pNum && i != index) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        if (i % w == w - 1 || board[i] != pNum) {
            //printf("Exit on: %i\n\n", i);
            break;
        }
    }
    //printf("Check Row Count: %i\n", count);
    return count;
}

/********************************************************************/
/* This method returns the sum of the col series board[index] is a  */
/* part of.                                                         */
/*                                                                  */
/********************************************************************/
int checkCol(int *board, int pNum, int index, int w, int h, 
             int size) {
    int count = 0;
    //printf("CHECK COL FROM INDEX %i: \n\n", index);
    // look "down"
    // iterates "down" col of index
    // break when board[index] != pNum
    for (int i = index; i >= 0; i -= w) {
        if (board[i] == pNum) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        if(board[i] != pNum) {
            //printf("Exit on: %i\n\n", i);
            break;
        }
    }
    //printf("Check Col Count: %i\n", count);
    return count;
}

/********************************************************************/
/* This method returns the sum of the diagonal series ("lower left  */
/* to upper right") board[index] is a part of.                      */
/*                                                                  */
/********************************************************************/
int checkDiag1(int *board, int pNum, int index, int w, int h,
               int size) {
    int count = 0;
    //printf("CHECK DIAG1 FROM INDEX %i: \n\n", index);
    // look "down" and "left"
    // iterates diagonally "down" and "left" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index; i >= 0; i -= w + 1) {
        if (board[i] == pNum) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        if (i % w == 0 || board[i] != pNum) {
            //printf("Exit on: %i\n\n", i);
            break;
        }
    }

    // look "up" and "right"
    // iterates diagonally "up" and "right" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index; i < size; i += w + 1) {
        if (board[i] == pNum && i != index) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        if (i % w == w - 1 || board[i] != pNum) {
           //printf("Exit on: %i\n\n", i);
            break;
        }
    }
    //printf("Check Diag 1 Count: %i\n", count);
    return count;
}

/********************************************************************/
/* This method returns the sum of the diagonal series ("lower right */
/* to upper left") board[index] is a part of.                       */
/*                                                                  */
/********************************************************************/
int checkDiag2(int *board, int pNum, int index, int w, int h,
               int size) {
    int count = 0;
    //printf("CHECK DIAG2 FROM INDEX %i: \n\n", index);
    // look "down" and "right"
    // iterates diagonally "down" and "right" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    
    for (int i = index; i >= 0; i -= w - 1) {
        if (board[i] == pNum) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        if (i % w == w - 1 || board[i] != pNum) {
            //printf("Exit on: %i\n\n", i);
            break;
        }
    }

    // look "up" and "left"
    // iterates diagonally "up" and "left" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index; i < size; i += w - 1) {
        if (board[i] == pNum && i != index) {
            count++;
            //printf("Index: %i, Val at index: %i ,Count: %i\n\n", i, board[i], count);
        }
        else if (i % w == 0 || board[i] != pNum) {
            //printf("Exit on: %i\n\n", i);
            break;
        }
    }
    //printf("Check Diag 2 Count: %i\n", count);
    return count;
}
/********************************************************************/
/* This method allocates memory for the specified width and height  */
/* and initializes the board to all zeroes (unplayed/"empty"        */
/* value).                                                          */
/********************************************************************/
int createBoard(int **board, int w, int h) {
    int size = w * h;

    //allocate board size
    *board = malloc(size * sizeof(int));

    //init board to all zeros (unplayed val)
    for(int i = 0; i < size; i++){
        (*board)[i] = 0;
    }

    return size;
    }

/********************************************************************/
/*                    */
/*                                                                  */
/********************************************************************/
int boardNotFull(int* board, int w, int h, int size){
    int notFull = 0; // board full by default

    for(int i = size - w; i < size; i++) {
        if(board[i] == 0){
            notFull = 1; // board not full
            break;
        }
    }
    return notFull;
}

/********************************************************************/
/* Places the players in the selected column, returns index if      */
/* column not full, if column full returns -1.                      */
/*                                                                  */
/********************************************************************/
int move(int *board, int pNum, int w, int h, int pCol) {
    // default index, returned if column full
    int pIndex = -1;

    // iterating through each row to find the first available index
    //   in the selected column
    for (int i = pCol - 1; i < w * h; i += w) {
        // index is available
        if(board[i] == 0) {
            board[i] = pNum;
            pIndex = i;
            break;
        }
    }
    //printf("Played Index: %i\n\n", pIndex);
    return pIndex;
}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int saveGame(char* fileName, int* board, int w, int h, int toWin){
    FILE* fp = fopen(fileName, "w");

    if(!fp) {
        printf("Write Error!");
    }
    else {
        fprintf(fp, "%d\n", w);
        fprintf(fp, "%d\n", h);
        fprintf(fp, "%d\n", toWin);
        for(int i = 0; i < w * h; i++){
            fprintf(fp, "%d", board[i]);
        }
        fprintf(fp, "\n");
        fclose(fp);
    }
    return 0;
}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int loadGame(char* fileName, int** board, int* w, int* h, int* toWin){
//     attempt open file
    FILE* fp = fopen(fileName, "r");

    // exception: file not open
    if(fp == NULL) {
        // instructor supplied next line
        fprintf(stderr, "Could not open the file: %s\nExiting. . . ", filename);

        exit(EXIT_FAILURE);
     }

    struct stat st;
    stat(fp, &st);
    int size = st.st_size;
    char* buffer = malloc(size * sizeof(char));

    // fgetc found at https://www.tutorialspoint.com/cprogramming/c_file_io.htm
    for(int i = 0; i <= 3; i++) {
        if(i == 0){
            fgets(buffer, size, fp);
            scanf(buffer, "%d", *w);
        }
        else if(i == 1){
            fgets(buffer, size, fp);
            scanf(buffer, "%d", *h);
        }
        else if(i == 2){
            fgets(buffer, size, fp);
            scanf(buffer, "%d", *toWin)
        }
        else{
            *board = malloc((w * h) * sizeof(int));
            fgets(buffer,size,fp);

            for(int i = 0; i < (w * h) - 1; i++) {
                (*board)[i] = buffer[i] - '0';
            }

            }
    }
    fclose(fp);

    return 0;
}