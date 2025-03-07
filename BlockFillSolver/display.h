#pragma once
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "consoleSet.h"
#include "board.h"
#include "recentRecord.h"

void MainDisplay();
void DisplayClear();
void BoardDisplay(int x_, int y_);
void DrawMode(int x_, int y_);
void StartPointSetMode(int x_, int y_);
void DisplayAnswer(int x_, int y_);
void RecordBoardDisplay(int numOf, int x_, int y_);
void RecordDisplayAnswer(int numOf, int x_, int y_);

#endif