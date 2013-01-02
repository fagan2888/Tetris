#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <cstdio>
#include <list>
#include <vector>
#include <iterator>
#include <ctime>

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
const float BLOCK_SIZE = 0.1f;
const int BLOCK_NUM = 4;
const float BOTTOM_BORDER = -1.0f + BLOCK_SIZE * 3 / 2;
const float TOP_BORDER = 1.0f - BLOCK_SIZE / 2;
const float LEFT_BORDER = -1.0f + BLOCK_SIZE * 3 / 2;
const float RIGHT_BORDER = 0.0f + BLOCK_SIZE / 2;
const float FRONT_BORDER = 0.0f - BLOCK_SIZE / 2;
const float BACK_BORDER = -1.0f + BLOCK_SIZE * 3 / 2;
const float BOTTOM_NEXT = 0.55f + BLOCK_SIZE / 2;
const float TOP_NEXT = 0.95f - BLOCK_SIZE / 2;
const float LEFT_NEXT = 0.55f + BLOCK_SIZE / 2;
const float RIGHT_NEXT = 0.95f - BLOCK_SIZE / 2;
const int START_ROW = (int)((TOP_BORDER - BOTTOM_BORDER) / BLOCK_SIZE - 1);
const int START_COLUMN = (int)((RIGHT_BORDER - LEFT_BORDER) / BLOCK_SIZE / 2 - 1);
const int START_DEPTH = (int)((FRONT_BORDER - BACK_BORDER) / BLOCK_SIZE / 2 - 1);
const int NEXT_ROW = (int)((TOP_NEXT - BOTTOM_NEXT) / BLOCK_SIZE - 1);
const int NEXT_COLUMN = (int)((RIGHT_BORDER - LEFT_BORDER) / BLOCK_SIZE / 2 - 1);
const int NEXT_DEPTH = (int)((FRONT_BORDER - BACK_BORDER) / BLOCK_SIZE / 2 - 2);
const int ROW = (int)((TOP_BORDER - BOTTOM_BORDER) / BLOCK_SIZE);
const int COLUMN = (int)((RIGHT_BORDER - LEFT_BORDER) / BLOCK_SIZE);
const int DEPTH = (int)((FRONT_BORDER - BACK_BORDER) / BLOCK_SIZE);

//Basic Parameters
extern int level_fill[ROW + 2];
extern int speed;
extern int dropspeed;
#endif
