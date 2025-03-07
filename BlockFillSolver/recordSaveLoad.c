#include "recordSaveLoad.h"

extern record recordList[LIST_SIZE];
extern numOfRecord;

void SaveRecordList() {
	FILE* fp = fopen("recordList.dat", "wb");
	if (fp == NULL) return;

	fwrite(&numOfRecord, sizeof(int), 1, fp);
	fwrite(recordList, sizeof(record), numOfRecord, fp);

	fclose(fp);
}

void LoadRecordList() {
	FILE* fp = fopen("recordList.dat", "rb");
	if (fp == NULL) return;

	fread(&numOfRecord, sizeof(int), 1, fp);
	fread(recordList, sizeof(record), numOfRecord, fp);

	fclose(fp);
}