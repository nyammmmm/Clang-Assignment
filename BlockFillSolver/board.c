#include "board.h"

static int board[MAX_SIZE][MAX_SIZE] = { 0, };
static int answer[MAX_SIZE][MAX_SIZE] = { 0, };
static int isVisited[MAX_SIZE][MAX_SIZE] = { 0, };
static int xSize, ySize, areaSize;

static time_t timeout;

void SetBoardSize(int x_, int y_) {
	xSize = x_;
	ySize = y_;
}

int GetBoardXSize() {
	return xSize;
}

int GetBoardYSize() {
	return ySize;
}

void SetBoardElement(int x_, int y_, int value_) {
	board[y_][x_] = value_;
}

int GetBoardElement(int x_, int y_) {
	return board[y_][x_];
}

int GetAnswerElement(int x_, int y_) {
	return answer[y_][x_];
}

void BoardClear() {
	int i, j;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			board[i][j] = 0;
		}
	}
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			answer[i][j] = 0;
		}
	}
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			isVisited[i][j] = 0;
		}
	}
}

int GetBoardAreaSize() {
	int i, j;
	int blankCount = 0;

	for (i = 0; i < ySize; i++) {
		for (j = 0; j < xSize; j++) {
			if (board[i][j] == 0) blankCount++;
		}
	}

	return (xSize * ySize) - blankCount;
}

int inRange(x_, y_) {
	return (0 <= x_ && x_ < xSize && 0 <= y_ && y_ < ySize);
}

int SolveAnswer(int x_, int y_, int fill_, int prevTurn) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	int curve[4][4] =
	{ {UP_TO_UP, UP_TO_RIGHT, 0, UP_TO_LEFT},
		{RIGHT_TO_UP, RIGHT_TO_RIGHT, RIGHT_TO_DOWN, 0},
		{0, DOWN_TO_RIGHT, DOWN_TO_DOWN, DOWN_TO_LEFT},
		{LEFT_TO_UP, 0, LEFT_TO_DOWN, LEFT_TO_LEFT}
	};
	int i;
	int ret;

	if (time(0) - timeout >= 5) return -1;

	if (!inRange(x_, y_) || board[y_][x_] == 0 || isVisited[y_][x_] == 1) return 0;
	if (fill_ == GetBoardAreaSize()) {
		answer[y_][x_] = -2;
		return 1;
	}

	isVisited[y_][x_] = 1;
	for (i = 0; i < 4; i++) {
		ret = SolveAnswer(x_ + dx[i], y_ + dy[i], fill_ + 1, i);
		if (ret == 1) {
			if (fill_ == 1) answer[y_][x_] = -1;
			else answer[y_][x_] = curve[prevTurn][i];
			return 1;
		}
		else if (ret == -1) {
			return -1;
		}
	}
	isVisited[y_][x_] = 0;

	return 0;
}

void ProcessAnswer(int x_, int y_) {
	timeout = time(0);
	switch (SolveAnswer(x_, y_, 1, 0)) {
		case -1:
			answer[0][0] = -4;
			break;
		case 0:
			answer[0][0] = -3;
			break;
		default:
			break;
	}
	RecordAdd();
	SaveRecordList();
}