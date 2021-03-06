#ifndef CHESS_H
#define CHESS_H

#include <stdGraphics.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <timer.h>
#include <colors.h>

void chess();

#define SQUAREDIM 64
#define SQUARES 8 
#define BOARDDIM SQUAREDIM * SQUARES

#define KING 1
#define QUEEN 2
#define BISHOP 3
#define KNIGHT 4
#define ROOK 5
#define PAWN 6
#define EMPTY 0

#define PIECES_SIZE 8
#define PIECES_AMOUNT 6

#define BACKGROUND MAROON

#define CONSOLE_LIMIT_X (SCREEN_WIDTH/2+BOARDDIM/2+SQUAREDIM/2)
#define CONSOLE_LIMIT_Y SQUAREDIM
#define CONSOLE_SIZE_Y BOARDDIM
#define CONSOLE_SIZE_X (SQUAREDIM*3+BASE_CHAR_WIDTH)
#define TOTAL_LINES_CHESS 210
#define MAX_LENGTH 16

#define PLAYER_12_PLACE_X (SCREEN_WIDTH/2-BOARDDIM/2-BASE_CHAR_WIDTH*(9 + 15))
#define PLAYER_1_PLACE_Y (SQUAREDIM+BOARDDIM/2)
#define PLAYER_2_PLACE_Y SQUAREDIM

#define PROMOTE_LOGS (CONSOLE_LIMIT_Y+CONSOLE_SIZE_Y+SQUAREDIM/2-BASE_CHAR_HEIGHT)
#define MOVEMENT (PROMOTE_LOGS+8*BASE_CHAR_HEIGHT)

#endif