#pragma once
#ifndef __CONSOLESET_H__
#define __CONSOLESET_H__

#include "common.h"

void CursorView(DWORD size_, BOOL visible_);
void MouseInputInit();
void TextInputInit();
void TextColorSet(WORD colorCode_);
void GotoXY(int x_, int y_);

#endif