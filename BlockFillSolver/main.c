#include <stdio.h>
#include <Windows.h>
#include "display.h"
#include "recordSaveLoad.h" 

int main() {
	system("title BLOCK FILL SOLVER");
	LoadRecordList();
	while (1) {
		MainDisplay();
	}

	return 0;
}