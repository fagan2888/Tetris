#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <cstdio>
#include <list>
#include <iterator>

#ifdef _WIN32
#include <windows.h>
#include <GL\glut.h>
#endif

#ifdef __linux
#include <GL/glut.h>
#endif

#ifdef MACRO
#include <GL/glut.h>
#endif
using namespace std;

//Basic Settings
const float BLOCK_SIZE = 0.05f;
const int BLOCK_NUM = 4;
const float BOTTOM_BORDER = -1.0f + BLOCK_SIZE / 2;
const float TOP_BORDER = 1.0f - BLOCK_SIZE / 2;
const float LEFT_BORDER = -1.0f + BLOCK_SIZE / 2;
const float RIGHT_BORDER = 0.5f - BLOCK_SIZE / 2;
const int START_X = (int)((LEFT_BORDER + RIGHT_BORDER) / BLOCK_SIZE / 2);
const int START_Y = (int)(TOP_BORDER / BLOCK_SIZE - 1);
const int ROW = (int)((TOP_BORDER - BOTTOM_BORDER) / BLOCK_SIZE);
const int COLUMN = (int)((RIGHT_BORDER - LEFT_BORDER) / BLOCK_SIZE);
const int MAP[ROW][COLUMN] = {0};
#endif