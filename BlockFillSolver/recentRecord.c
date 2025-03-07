#include "recentRecord.h"

record recordList[LIST_SIZE];
int numOfRecord = 0;

void RecordAdd() {
	int i, j;

	for (i = numOfRecord - 2; i >= 0; i--) {
		recordList[i + 1] = recordList[i];
	}
	if (numOfRecord != LIST_SIZE) {
		numOfRecord++;
	}

	recordList[0].xSize = GetBoardXSize();
	recordList[0].ySize = GetBoardYSize();
	for (i = 0; i < recordList[0].ySize; i++) {
		for (j = 0; j < recordList[0].xSize; j++) {
			recordList[0].board[i][j] = GetBoardElement(j, i);
		}
	}

	for (i = 0; i < recordList[0].ySize; i++) {
		for (j = 0; j < recordList[0].xSize; j++) {
			recordList[0].answer[i][j] = GetAnswerElement(j, i);
		}
	}
}

int GetRecordListSize() {
	return numOfRecord;
}

int GetRecordBoardXSize(int numOf) {
	return recordList[numOf].xSize;
}

int GetRecordBoardYSize(int numOf) {
	return recordList[numOf].ySize;
}

int GetRecordBoardElement(int numOf, int x, int y) {
	return recordList[numOf].board[y][x];
}

int GetRecordAnswerElement(int numOf, int x, int y) {
	return recordList[numOf].answer[y][x];
}