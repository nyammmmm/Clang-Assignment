#include "consoleSet.h"

void CursorView(DWORD size_, BOOL visible_) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = size_;
	cursorInfo.bVisible = visible_;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void MouseInputInit() {
	CursorView(1, FALSE);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
}

void TextInputInit() {
	CursorView(1, TRUE);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT |
		ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS | ENABLE_AUTO_POSITION);
}

void TextColorSet(WORD colorCode_) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode_);
}

void GotoXY(int x_, int y_) {
	COORD Pos;
	Pos.X = x_;
	Pos.Y = y_;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
};