#pragma once
#include <Windows.h>

const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define FOREGROUND_WHITE 0x0007
#define SetErrorColor(x) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);\
	x;\
	SetConsoleTextAttribute(hConsole, FOREGROUND_WHITE | FOREGROUND_INTENSITY)

#define SetOkColor(x) SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);\
	x;\
	SetConsoleTextAttribute(hConsole, FOREGROUND_WHITE | FOREGROUND_INTENSITY)