/********************************************************************/
/* Game.h                                                           */
/* Author:                                                          */
/*  Derrik Fleming         */
/*  CIS343       */
/********************************************************************/
/* The following methods aid in the game play of ConnectX.          */
/*                                                                  */
/********************************************************************/

#ifndef CONNECTX_GAME_H
#define CONNECTX_GAME_H

#include <stdio.h>
#include <stdlib.h>


int gameState(int *board, int pNum, int index, int w, int h,
               int size, int toWin);
int checkRow(int *board, int pNum, int index, int w,
             int h, int size);
int checkCol(int *board, int pNum, int index, int w, int h,
             int size);
int checkDiag1(int *board, int pNum, int index,
               int w, int h, int size);
int checkDiag2(int *board, int pNum, int index,
               int w, int h, int size);
int createBoard(int **board, int w, int h);
int move(int *board, int pNum, int w, int h, int pCol);
int boardNotFull(int* board, int w, int h, int size);
void printBoard(int *board, int w, int h);
int saveGame(char* fileName, int* board, int w, int h,int size);
int loadGame(char* fileName, int** board, int* w, int* h, int* toWin);


#endif //CONNECTX_GAME_H
