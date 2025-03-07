#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__

#define MAX_SIZE 10

#include "common.h"
#include "recordSaveLoad.h"

enum {
	UP_TO_UP = 1, UP_TO_RIGHT, UP_TO_LEFT,
	RIGHT_TO_UP, RIGHT_TO_RIGHT, RIGHT_TO_DOWN,
	DOWN_TO_RIGHT, DOWN_TO_DOWN, DOWN_TO_LEFT,
	LEFT_TO_UP, LEFT_TO_DOWN, LEFT_TO_LEFT,
};

void SetBoardSize(int x_, int y_);
int GetBoardXSize();
int GetBoardYSize();
void SetBoardElement(int x_, int y_, int value_);
int GetBoardElement(int x_, int y_);
int GetAnswerElement(int x_, int y_);
void BoardClear();
int GetBoardAreaSize();
int inRange(x_, y_);
int SolveAnswer(int x_, int y_, int fill_, int prevTurn);
void ProcessAnswer(int x_, int y_);

#endif