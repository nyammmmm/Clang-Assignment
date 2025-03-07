#pragma once
#ifndef __RECENTRECORD_H__
#define __RECENTRECORD_H__

#include "board.h"

#define LIST_SIZE 10

typedef struct _record {
	int board[MAX_SIZE][MAX_SIZE];
	int answer[MAX_SIZE][MAX_SIZE];
	int xSize;
	int ySize;
}record;

void RecordAdd();
int GetRecordListSize();
int GetRecordBoardXSize(int numOf);
int GetRecordBoardYSize(int numOf);
int GetRecordBoardElement(int numOf, int x, int y);
int GetRecordAnswerElement(int numOf, int x, int y);

#endif