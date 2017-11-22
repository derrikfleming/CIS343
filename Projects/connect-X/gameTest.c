/********************************************************************/
/* GameTest.c                                                       */
/* Author:                                                          */
/*  Derrik Fleming                                                  */
/*  CIS343-01 with Prof Ira Woodring                                */
/********************************************************************/
/* The following methods test the methods used in the game.c, which */
/* are used in ConnectX.c to manage the game board state, and game  */
/* control. Rather than written explanations of each game state     */
/* being tested, each method has included a comment block with a    */
/* visual representation of the game state being tested.            */
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

#include "gametest.h"
#include "cutest.h"

void init(int* board, int w, int h){
    createBoard(&board, w, h);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 1 | 1 | 1 | 1 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckBottomRow1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 0; i < 4; i++) {
        board[i] = pNum;
    }
    assert_eq(4, checkRow(board, pNum, 3, w, h, (w * h)),
              "1: Test: horiz. bottow row left. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 1 | 1 | 1 | 1 | 1 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckBottomRow2(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 1; i < 6; i++) {
        board[i] = pNum;
    }
    assert_eq(5, checkRow(board, pNum, 4, w, h, (w * h)),
              "2: Test: horiz. bottow row center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 1 | 1 | 1 | 1 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckBottomRow3(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 3; i < 7; i++) {
        board[i] = pNum;
    }
    assert_eq(4, checkRow(board, pNum, 4, w, h, (w * h)),
              "3: Test: horiz. bottow row right. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 1 | 1 | 1 | 1 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckTopRow1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 42; i < 46; i++) {
        board[i] = pNum;
    }
    assert_eq(4, checkRow(board, pNum, 42, w, h, (w * h)),
              "4: Test: horiz. top row left. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 1 | 1 | 1 | 1 | 1 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckTopRow2(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 43; i < 48; i++) {
        board[i] = pNum;
    }
    assert_eq(5, checkRow(board, pNum, 45, w, h, (w * h)),
              "5: Test: horiz. top row center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 1 | 1 | 1 | 1 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckTopRow3(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 45; i < 49; i++) {
        board[i] = 1;
    }
    assert_eq(4, checkRow(board, pNum, 47, w, h, (w * h)),
              "6: Test: horiz. top row right. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 1 | 1 | 1 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckCenterRow1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 21; i < 25; i++) {
        board[i] = 1;
    }
    assert_eq(4, checkRow(board, pNum, 21, w, h, (w * h)),
              "7: Test: horiz. center row right. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 1 | 1 | 1 | 1 | 1 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckCenterRow2(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 22; i < 27; i++) {
        board[i] = 1;
    }
    assert_eq(5, checkRow(board, pNum, 24, w, h, (w * h)),
              "8: Test: horiz. center row center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 1 | 1 | 1 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testHorizontalCheckCenterRow3(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 24; i < 28; i++) {
        board[i] = 1;
    }
    assert_eq(4, checkRow(board, pNum, 25, w, h, (w * h)),
              "9: Test: horiz. center row center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckLeftCol1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 0; i <= 21; i + w) {
        board[i] = 1;
    }
    assert_eq(4, checkCol(board, pNum, 21, w, h, (w * h)),
              "10: Test: vert. left col bottom. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckLeftCol2(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 7; i <= 35; i + w) {
        board[i] = 1;
    }
    assert_eq(5, checkCol(board, pNum, 35, w, h, (w * h)),
              "11: Test: vert. left col center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckLeftCol3(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 21; i <= 42; i + w) {
        board[i] = 1;
    }
    assert_eq(4, checkCol(board, pNum, 42, w, h, (w * h)),
              "12: Test: vert. left col top. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckCenterCol1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 3; i <= 24; i + w) {
        board[i] = 1;
    }
    assert_eq(4, checkCol(board, pNum, 24, w, h, (w * h)),
              "13: Test: vert. center col bottom. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckCenterCol2(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 10; i <= 38; i + w) {
        board[i] = 1;
    }
    assert_eq(5, checkCol(board, pNum, 38, w, h, (w * h)),
              "14: Test: vert. center col center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckCenterCol3(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 24; i <= 45; i + w) {
        board[i] = 1;
    }
    assert_eq(4, checkCol(board, pNum, 45, w, h, (w * h)),
              "15: Test: vert. center col top. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckRightCol1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 6; i <= 27; i + w) {
        board[i] = 1;
    }
    assert_eq(4, checkCol(board, pNum, 27, w, h, (w * h)),
              "16: Test: vert. right col bottom. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckRightCol2(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 13; i <= 41; i + w) {
        board[i] = 1;
    }
    assert_eq(5, checkCol(board, pNum, 27, w, h, (w * h)),
              "16: Test: vert. right col center. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testVerticalCheckRightCol3(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 27; i <= 48; i + w) {
        board[i] = 1;
    }
    assert_eq(4, checkCol(board, pNum, 27, w, h, (w * h)),
              "17: Test: vert. right col top. Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 1 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag1LeftCol(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 7; i <= 31; i + (w+1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag1(board, pNum, 7, w, h, (w * h)),
              "18: Test: Diag1. Low left to up right on left side. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 1 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag1LeftCorner(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 0; i <= 24; i + (w+1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag1(board, pNum, 0, w, h, (w * h)),
              "19: Test: Diag1. Low left to up right left corner. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 1 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag1Bottom(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 1; i <= 25; i + (w+1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag1(board, pNum, 1, w, h, (w * h)),
              "20: Test: Diag1. Low left to up right bottom row. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 1 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag1Top(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 23; i <= 47; i + (w+1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag1(board, pNum, 1, w, h, (w * h)),
              "21: Test: Diag1. Low left to up right top row. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 1 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag1RightCorner(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 24; i <= 48; i + (w+1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag1(board, pNum, 1, w, h, (w * h)),
              "22: Test: Diag1. Low left to up right right corner. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 1 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag1RightSide(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 17; i <= 41; i + (w+1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag1(board, pNum, 1, w, h, (w * h)),
              "23: Test: Diag1. Low left to up right right col. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 1 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag2LeftSide(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 17; i <= 35; i + (w-1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag2(board, pNum, 17, w, h, (w * h)),
              "24: Test: Diag1. Low right to up left on left side. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 1 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 1 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag2LeftCorner(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 24; i <= 42; i + (w-1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag2(board, pNum, 24, w, h, (w * h)),
              "25: Test: Diag1. Low right to up left left corner. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 1 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag2Top(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 25; i <= 43; i + (w-1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag2(board, pNum, 25, w, h, (w * h)),
              "26: Test: Diag1. Low right to up left top row. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 1 | 0 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 1 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag2Bottom(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 5; i <= 23; i + (w-1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag2(board, pNum, 5, w, h, (w * h)),
              "27: Test: Diag1. Low left to up right top row. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 1 | 0 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag2RightCorner(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 6; i <= 24; i + (w-1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag2(board, pNum, 6, w, h, (w * h)),
              "28: Test: Diag1. Low left to up right right corner. "
                      "Win Found.\n");
    free(board);
}

/********************************************************************/
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[42] through board[48]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[35] through board[41]        */
/* | 0 | 0 | 0 | 1 | 0 | 0 | 0 | board[28] through board[34]        */
/* | 0 | 0 | 0 | 0 | 1 | 0 | 0 | board[21] through board[27]        */
/* | 0 | 0 | 0 | 0 | 0 | 1 | 0 | board[14] through board[20]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 1 | board[7]  through board[13]        */
/* | 0 | 0 | 0 | 0 | 0 | 0 | 0 | board[0]  through board[6]         */
/*                                                                  */
/********************************************************************/
void testDiag2RightSide(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    for (int i = 13; i <= 31; i + (w-1)) {
        board[i] = 1;
    }
    assert_eq(4, checkDiag2(board, pNum, 13, w, h, (w * h)),
              "29: Test: Diag1. Low left to up right right col. "
                      "Win Found.\n");
    free(board);
}

int testCompleteCheckHorizontal(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    int true = 1;
    int false = 0;
    init(board, w, h);

    for (int i =  1; i < 4; i++) {
        move(board, pNum, w, h, i);
        assert_eq(false, isComplete(board, pNum, i, w, h, (w * h)),
                  "30: Game has not been won yet.\n");
    }

    move(board, pNum, w, h, 4);

    assert_eq(true, isComplete(board, pNum, 3, w, h, (w * h)),
              "31: Game has been won.");
}

/********************************************************************/
/* Test move from empty column to full column.                      */
/*                                                                  */
/********************************************************************/
void testMove1(){
    int* board;
    int w = 7;
    int h = 7;
    int pNum = 1;
    int toWin = 4;
    init(board, w, h);

    assert_eq(0, move(board, pNum, 0, w, h, 1),
              "30: Test: Move, empty col");
    assert_eq(7, move(board, pNum, 0, w, h, 1),
              "31: Test: Move, 1 in col");
    assert_eq(14, move(board, pNum, 0, w, h, 1),
              "32: Test: Move, 2 in col");
    assert_eq(21, move(board, pNum, 0, w, h, 1),
              "33: Test: Move, 3 in col");
    assert_eq(28, move(board, pNum, 0, w, h, 1),
              "34: Test: Move, 4 in col");
    assert_eq(35, move(board, pNum, 0, w, h, 1),
              "35: Test: Move, 5 in col");
    assert_eq(42, move(board, pNum, 0, w, h, 1),
              "36: Test: Move, 5 in col");
    assert_eq(-1, move(board, pNum, 0, w, h, 1),
              "37: Test: Move, 5 in col");
}



/********************************************************************/
/* Build CuSuite.                                                   */
/*                                                                  */
/********************************************************************/
CuSuite* connectXSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, testHorizontalCheckBottomRow1);
    SUITE_ADD_TEST(suite, testHorizontalCheckBottomRow2);
    SUITE_ADD_TEST(suite, testHorizontalCheckBottomRow3);
    SUITE_ADD_TEST(suite, testHorizontalCheckTopRow1);
    SUITE_ADD_TEST(suite, testHorizontalCheckTopRow2);
    SUITE_ADD_TEST(suite, testHorizontalCheckTopRow3);
    SUITE_ADD_TEST(suite, testHorizontalCheckCenterRow1);
    SUITE_ADD_TEST(suite, testHorizontalCheckCenterRow2);
    SUITE_ADD_TEST(suite, testHorizontalCheckCenterRow3);
    SUITE_ADD_TEST(suite, testVerticalCheckLeftCol1);
    SUITE_ADD_TEST(suite, testVerticalCheckLeftCol2);
    SUITE_ADD_TEST(suite, testVerticalCheckLeftCol3);
    SUITE_ADD_TEST(suite, testVerticalCheckCenterCol1);
    SUITE_ADD_TEST(suite, testVerticalCheckCenterCol2);
    SUITE_ADD_TEST(suite, testVerticalCheckCenterCol3);
    SUITE_ADD_TEST(suite, testVerticalCheckRightCol1);
    SUITE_ADD_TEST(suite, testVerticalCheckRightCol2);
    SUITE_ADD_TEST(suite, testVerticalCheckRightCol3);
    SUITE_ADD_TEST(suite, testDiag1LeftCol);
    SUITE_ADD_TEST(suite, testDiag1LeftCorner);
    SUITE_ADD_TEST(suite, testDiag1Bottom);
    SUITE_ADD_TEST(suite, testDiag1Top);
    SUITE_ADD_TEST(suite, testDiag1RightCorner);
    SUITE_ADD_TEST(suite, testDiag1RightSide);
    SUITE_ADD_TEST(suite, testDiag2LeftSide);
    SUITE_ADD_TEST(suite, testDiag2LeftCorner);
    SUITE_ADD_TEST(suite, testDiag2Top);
    SUITE_ADD_TEST(suite, testDiag2Bottom);
    SUITE_ADD_TEST(suite, testDiag2RightCorner);
    SUITE_ADD_TEST(suite, testDiag2RightSide);
    SUITE_ADD_TEST(suite, testMove1);
    SUITE_ADD_TEST(suite, testCompleteCheckHorizontal);
}

/********************************************************************/
/* Run CuSuite.                                                     */
/*                                                                  */
/********************************************************************/
void testConnectX(void) {
    CuString* results = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, connectXSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", results->buffer);
}

/********************************************************************/
/*                                                                  */
/*                                                                  */
/********************************************************************/
int main(void) {
    testConnectX();
    return 0;
}