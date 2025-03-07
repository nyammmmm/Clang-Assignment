#include "display.h"

enum {START, RECORD, DESC, CREDIT, EXIT};

void MainDisplay() {
	INPUT_RECORD inputRecord;
	DWORD events;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	COORD clickPos;
	MOUSE_EVENT_RECORD mouseEvent;

	int sizeX, sizeY;
	int i, j = 0;

	int clickFormatX[5] = { 16, 14, 16, 15, 16 };
	int clickFormatY[5] = { 4, 6, 8, 10, 12 };
	int lengthFormat[5] = { 3, 7, 3, 5, 3 };

	DisplayClear();

	GotoXY(10, 1);
	printf("BLOCK FILL SOLVER");
	GotoXY(16, 4);
	printf("����");
	GotoXY(14, 6);
	printf("�ֱٱ��");
	GotoXY(16, 8);
	printf("����");
	GotoXY(15, 10);
	printf("ũ����");
	GotoXY(16, 12);
	printf("����");

	int isLeftButtonDown = 0;
	int isLeftButtonDown2 = 0;

	while (1) {
		MouseInputInit();
		ReadConsoleInput(hInput, &inputRecord, 1, &events);
		if (inputRecord.EventType & MOUSE_EVENT) {
			mouseEvent = inputRecord.Event.MouseEvent;
			clickPos = mouseEvent.dwMousePosition;
			if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
				if (isLeftButtonDown) {
					for (i = 0; i < 5; i++) {
						if (clickFormatX[i] <= clickPos.X && clickPos.X <= clickFormatX[i] + lengthFormat[i] &&
							clickPos.Y == clickFormatY[i]) {
							if (i == START) {
								DisplayClear();
								while (1) {
									TextInputInit();
									TextColorSet(15);
									printf("������ ���λ����� : ");
									scanf("%d", &sizeX);
									printf("������ ���λ����� : ");
									scanf("%d", &sizeY);
									DisplayClear();
									if (1 <= sizeX && sizeX <= MAX_SIZE && 1<= sizeY && sizeY <= MAX_SIZE) break;
									TextColorSet(6);
									printf("������� 1 �̻�, %d ���Ϸ� �Է����ּ���.\n", MAX_SIZE);
								}

								SetBoardSize(sizeX, sizeY);
								BoardClear();
							
								DrawMode(1, 2);
								DisplayClear();
								GotoXY(2, 0);
								TextColorSet(2);
								printf("����");
								return DisplayAnswer(1, 2);
							}
							if (i == RECORD) {
								while (1) {
									DisplayClear();
									if (GetRecordListSize() == 0) {
										TextColorSet(6);
										printf("����� �����ϴ�.");
										Sleep(2000);
										return;
									}
									TextColorSet(15);
									GotoXY(2, 0);
									TextColorSet(15);
									printf("����");
									RecordBoardDisplay(j, 1, 2);
									GotoXY((GetRecordBoardXSize(j) + 1 + 2) * 2, 0);
									TextColorSet(2);
									printf("����");
									RecordDisplayAnswer(j, GetRecordBoardXSize(j) + 1 + 2, 2);

									TextColorSet(15);
									GotoXY(2, MAX_SIZE + 3);
									printf("��    ��");
									GotoXY(2, MAX_SIZE + 5);
									TextColorSet(1);
									printf("�ڷΰ���");

									int flag = 0;
									isLeftButtonDown2 = 0;

									while (1) {
										MouseInputInit();
										ReadConsoleInput(hInput, &inputRecord, 1, &events);
										mouseEvent = inputRecord.Event.MouseEvent;
										clickPos = mouseEvent.dwMousePosition;
										if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
											if (isLeftButtonDown2) {
												if (clickPos.X >= 2 && clickPos.X <= 9 && clickPos.Y == MAX_SIZE + 5) {
													return;
												}
												if (clickPos.X == 2 && clickPos.Y == MAX_SIZE + 3) {
													flag = 1;
													j--;
												}
												if (clickPos.X == 7 && clickPos.Y == MAX_SIZE + 3) {
													flag = 1;
													j++;
												}
											}
										}
										else {
											isLeftButtonDown2 = 1;
										}

										if (flag == 1) {
											if (j > GetRecordListSize() - 1) {
												j = GetRecordListSize() - 1;
											}
											if (j < 0) {
												j = 0;
											}
											break;
										}
									}
								}
							}
							if (i == DESC) {
								DisplayClear();
								GotoXY(10, 1);
								printf("����ϰ��� Offline Games�� �̴ϰ��� ��");
								GotoXY(10, 2);
								printf("BLOCK FILL������ �ش��� �����ִ� ���α׷��Դϴ�.");
								GotoXY(10, 4);
								printf("���� : ���콺");
								GotoXY(10, 6);
								printf("����");
								GotoXY(12, 7);
								printf("Google Play ���� App Store���� Offline Games�� ��ġ�ϰ�");
								GotoXY(12, 8);
								printf("BLOCK FILL�� ���ּ���.");
								GotoXY(12, 10);
								printf("���α׷��� ���� �� ������ �ִ� ���� ���̿� �ִ� ���� ���̸� �Է����ּ���.");
								GotoXY(12, 11);
								printf("���忡�� �̵����� �� ��θ� �׷��ּ���.");
								GotoXY(12, 12);
								printf("�׸��⸦ Ŭ���ϸ� ��θ� �׸� �� �ְ� ����⸦ Ŭ���ϸ� ��θ� ���� �� �ֽ��ϴ�.");
								GotoXY(12, 13);
								printf("�������� ��� Ȯ���� ������ ������ Ȯ���� �� �ֽ��ϴ�.");
								GotoXY(12, 15);
								printf("�ֱٱ�Ͽ��� �ֱ� ����� 10���� ����� �����ݴϴ�.");

								GotoXY(10, 17);
								TextColorSet(1);
								printf("�ڷΰ���");
								while (1) {
									while (1) {
										MouseInputInit();
										ReadConsoleInput(hInput, &inputRecord, 1, &events);
										mouseEvent = inputRecord.Event.MouseEvent;
										clickPos = mouseEvent.dwMousePosition;
										if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
											if (isLeftButtonDown2) {
												if (clickPos.X >= 10 && clickPos.X <= 17 && clickPos.Y == 17) {
													return;
												}
											}
										}
										else {
											isLeftButtonDown2 = 1;
										}
									}
								}
							}
							if (i == CREDIT) {
								DisplayClear();
								GotoXY(10, 1);
								printf("����");
								GotoXY(12, 2);
								printf("�й� : 2024111498");
								GotoXY(12, 3);
								printf("�̸� : ������");

								GotoXY(10, 5);
								TextColorSet(1);
								printf("�ڷΰ���");

								while (1) {
									while (1) {
										MouseInputInit();
										ReadConsoleInput(hInput, &inputRecord, 1, &events);
										mouseEvent = inputRecord.Event.MouseEvent;
										clickPos = mouseEvent.dwMousePosition;
										if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
											if (isLeftButtonDown2) {
												if (clickPos.X >= 10 && clickPos.X <= 17 && clickPos.Y == 5) {
													return;
												}
											}
										}
										else {
											isLeftButtonDown2 = 1;
										}
									}
								}
							}
							if (i == EXIT) {
								exit(0);
							}
						}
					}
				}
			}
			else {
				isLeftButtonDown = 1;
			}
		}
	}

	
}

enum {
	DRAW, ERASE
};

void DrawMode(int x_, int y_) {
	INPUT_RECORD inputRecord;
	DWORD events;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	COORD clickPos;

	int mode = DRAW;

	DisplayClear();

	TextColorSet(15);

	GotoXY(2, 0);
	TextColorSet(6);
	printf("�̵������� ��θ� ������ ĥ���ּ���.");

	TextColorSet(15);
	GotoXY(((GetBoardXSize() + x_) * 2) + 3, 0 + y_);
	printf("�׸���");
	GotoXY(((GetBoardXSize() + x_) * 2) + 3, 2 + y_);
	printf("�����");
	GotoXY(((GetBoardXSize() + x_) * 2) + 3, 4 + y_);
	TextColorSet(2);
	printf("�Ϸ�");

	BoardDisplay(x_, y_);

	int isLeftButtonDown = 0;

	while (1) {
		MouseInputInit();
		ReadConsoleInput(hInput, &inputRecord, 1, &events);

		if (inputRecord.EventType & MOUSE_EVENT) {
			MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;
			clickPos = mouseEvent.dwMousePosition;
			if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
				if (isLeftButtonDown) {
					if (clickPos.X >= ((GetBoardXSize() + x_) * 2) + 3 && clickPos.X <= ((GetBoardXSize() + x_) * 2) + 8) {
						if (clickPos.Y == (0 + y_)) mode = DRAW;
						if (clickPos.Y == (2 + y_)) mode = ERASE;
						if (clickPos.Y == (4 + y_)) return StartPointSetMode(x_, y_);
					}
					if (x_ <= clickPos.X / 2 && clickPos.X / 2 < (GetBoardXSize() + x_) 
						&& y_ <= clickPos.Y && clickPos.Y < (GetBoardYSize() + y_)) {
						if (mode == DRAW)
							SetBoardElement(clickPos.X / 2 - x_, clickPos.Y - y_, 1);
						else
							SetBoardElement(clickPos.X / 2 - x_, clickPos.Y - y_, 0);
						BoardDisplay(x_, y_);
					}
				}
			}
			else {
				isLeftButtonDown = 1;
			}
		}
	}
}

void StartPointSetMode(int x_, int y_) {
	INPUT_RECORD inputRecord;
	DWORD events;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	COORD clickPos;
	MOUSE_EVENT_RECORD mouseEvent;

	DisplayClear();

	TextColorSet(15);

	int startPx = -1, startPy = -1;

	GotoXY(2, 0);
	TextColorSet(6);
	printf("�������� ����ּ���.");

	GotoXY(((GetBoardXSize() + x_) * 2) + 3, 0 + y_);
	TextColorSet(2);
	printf("�Ϸ�");

	BoardDisplay(x_, y_);

	int isLeftButtonDown = 0;

	while (1) {
		MouseInputInit();
		ReadConsoleInput(hInput, &inputRecord, 1, &events);

		if (inputRecord.EventType & MOUSE_EVENT) {
			mouseEvent = inputRecord.Event.MouseEvent;
			clickPos = mouseEvent.dwMousePosition;
			if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
				if (isLeftButtonDown) {
					if (clickPos.X >= ((GetBoardXSize() + x_) * 2) + 3 && clickPos.X <= ((GetBoardXSize() + x_) * 2) + 8) {
						if (clickPos.Y == 0 + y_) break;
					}
					if (x_ <= clickPos.X / 2 && clickPos.X / 2 < GetBoardXSize() + x_ &&
						y_ <= clickPos.Y && clickPos.Y < GetBoardYSize() + y_) {
						startPx = clickPos.X / 2;
						startPy = clickPos.Y;

						BoardDisplay(x_, y_);
						GotoXY(startPx * 2, startPy);
						TextColorSet((1 << 4) + 15);
						printf("�� ");
					}
				}
			}
			else {
				isLeftButtonDown = 1;
			}
		}
	}
	SetBoardElement(startPx - x_, startPy - y_, 2);
	ProcessAnswer(startPx - x_, startPy - y_);
}

void DisplayClear() {
	TextColorSet(15);
	system("cls");
}

void BoardDisplay(int x_, int y_) {
	int x, y;

	for (y = y_; y < GetBoardYSize() + y_; y++) {
		for (x = x_; x < GetBoardXSize() + x_; x++) {
			if (GetBoardElement(x - x_, y - y_) == 1) {
				GotoXY(x * 2, y);
				TextColorSet(4 << 4);
				printf("  ");
			}
			else {
				GotoXY(x * 2, y);
				TextColorSet(15 << 4);
				printf("  ");
			}
		}
	}
}

void DisplayAnswer(int x_, int y_) {
	INPUT_RECORD inputRecord;
	DWORD events;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	COORD clickPos;
	MOUSE_EVENT_RECORD mouseEvent;

	if (GetAnswerElement(0, 0) == -3) {
		GotoXY(x_ * 2, y_ - 2);
		TextColorSet(4);
		printf("������ �����ϴ�.");
	}
	else if (GetAnswerElement(0, 0) == -4) {
		GotoXY(x_ * 2, y_ - 2);
		TextColorSet(4);
		printf("�ð� �ʰ��Դϴ�.");
	}
	else {
		for (int y = y_; y < GetBoardYSize() + y_; y++) {
			for (int x = x_; x < GetBoardXSize() + x_; x++) {
				TextColorSet(1);
				GotoXY(x * 2, y);
				switch (GetAnswerElement(x - x_, y - y_)) {
				case -1:
					TextColorSet(15);
					printf("�� ");
					break;
				case -2:
					TextColorSet(6);
					printf("�� ");
					break;
				case 0:
					printf("  ");
					break;
				case UP_TO_UP:
				case DOWN_TO_DOWN:
					printf("�� ");
					break;
				case LEFT_TO_LEFT:
				case RIGHT_TO_RIGHT:
					printf("�� ");
					break;
				case UP_TO_LEFT:
				case RIGHT_TO_DOWN:
					printf("�� ");
					break;
				case DOWN_TO_LEFT:
				case RIGHT_TO_UP:
					printf("�� ");
					break;
				case DOWN_TO_RIGHT:
				case LEFT_TO_UP:
					printf("�� ");
					break;
				case UP_TO_RIGHT:
				case LEFT_TO_DOWN:
					printf("�� ");
					break;
				}
			}
		}
	}

	TextColorSet(1);
	GotoXY(((GetBoardXSize() + x_) * 2) + 3, 0 + y_);
	printf("Ȯ��");

	int isLeftButtonDown = 0;

	while (1) {
		MouseInputInit();
		ReadConsoleInput(hInput, &inputRecord, 1, &events);
		if (inputRecord.EventType & MOUSE_EVENT) {
			mouseEvent = inputRecord.Event.MouseEvent;
			clickPos = mouseEvent.dwMousePosition;
			if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
				if (isLeftButtonDown) {
					if (((GetBoardXSize() + x_) * 2) + 3 <= clickPos.X && clickPos.X <= ((GetBoardXSize() + x_) * 2) + 7 &&
						clickPos.Y == 0 + y_) {
						return;
					}
				}
			}
			else {
				isLeftButtonDown = 1;
			}
		}
	}
}

void RecordBoardDisplay(int numOf, int x_, int y_) {
	int x, y;
	int element;

	for (y = y_; y < GetRecordBoardYSize(numOf) + y_; y++) {
		for (x = x_; x < GetRecordBoardXSize(numOf) + x_; x++) {
			element = GetRecordBoardElement(numOf, x - x_, y - y_);
			GotoXY(x * 2, y);
			if (element == 1) {
				TextColorSet(4 << 4);
				printf("  ");
			}
			else if (element == 2) {
				TextColorSet((1 << 4) + 15);
				printf("�� ");
			}
			else {
				TextColorSet(15 << 4);
				printf("  ");
			}
		}
	}
}

void RecordDisplayAnswer(int numOf, int x_, int y_) {
	INPUT_RECORD inputRecord;
	DWORD events;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	COORD clickPos;
	MOUSE_EVENT_RECORD mouseEvent;

	if (GetRecordAnswerElement(numOf, 0, 0) == -3) {
		GotoXY(x_ * 2, y_ - 2);
		TextColorSet(4);
		printf("������ �����ϴ�.");
	}
	else if (GetRecordAnswerElement(numOf, 0, 0) == -4) {
		GotoXY(x_ * 2, y_ - 2);
		TextColorSet(4);
		printf("�ð� �ʰ��Դϴ�.");
	}
	else {
		for (int y = y_; y < GetRecordBoardYSize(numOf) + y_; y++) {
			for (int x = x_; x < GetRecordBoardXSize(numOf) + x_; x++) {
				TextColorSet(1);
				GotoXY(x * 2, y);
				switch (GetRecordAnswerElement(numOf, x - x_, y - y_)) {
				case -1:
					TextColorSet(15);
					printf("�� ");
					break;
				case -2:
					TextColorSet(6);
					printf("�� ");
					break;
				case 0:
					printf("  ");
					break;
				case UP_TO_UP:
				case DOWN_TO_DOWN:
					printf("�� ");
					break;
				case LEFT_TO_LEFT:
				case RIGHT_TO_RIGHT:
					printf("�� ");
					break;
				case UP_TO_LEFT:
				case RIGHT_TO_DOWN:
					printf("�� ");
					break;
				case DOWN_TO_LEFT:
				case RIGHT_TO_UP:
					printf("�� ");
					break;
				case DOWN_TO_RIGHT:
				case LEFT_TO_UP:
					printf("�� ");
					break;
				case UP_TO_RIGHT:
				case LEFT_TO_DOWN:
					printf("�� ");
					break;
				}
			}
		}
	}
}