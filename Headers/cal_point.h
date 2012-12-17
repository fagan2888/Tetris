#ifndef CAL_POINT_H_INCLUDED
#define CAL_POINT_H_INCLUDED

#include <iostream>
#include <cmath>
#include <cstdio>

#ifdef _WIN32
#include <glut.h>
#endif

#ifdef __linux
#include <GL/glut.h>
#endif

#ifdef MACRO
#include <GL/glut.h>
#endif

//Basic Settings
const float BLOCK_SIZE = 0.2f;
const int BLOCK_NUM = 4;

struct Point
{
    double x;
    double y;
    double z;

    Point(double xx = 0, double yy = 0, double zz = 0) : x(xx), y(yy), z(zz){}
};

class Block
{
public:
    Block(){}
    Point points[BLOCK_NUM];
    void down();
};

class S_Block: public Block
{
public:
    S_Block()
    {
        points[0] = Point();
        points[1] = Point(-BLOCK_SIZE);
        points[2] = Point(0,BLOCK_SIZE);
        points[3] = Point(BLOCK_SIZE,BLOCK_SIZE);
    }
};

class Z_Block: public Block
{
public:
    Z_Block()
    {
        points[0] = Point();
        points[1] = Point(BLOCK_SIZE);
        points[2] = Point(0,BLOCK_SIZE);
        points[3] = Point(-BLOCK_SIZE,BLOCK_SIZE);
    }
};

class L_Block: public Block
{
public:
    L_Block()
    {
        points[0] = Point();
        points[1] = Point(BLOCK_SIZE);
        points[2] = Point(0,BLOCK_SIZE);
        points[3] = Point(0,BLOCK_SIZE * 2);
    }
};

class J_Block: public Block
{
public:
    J_Block()
    {
        points[0] = Point();
        points[1] = Point(-BLOCK_SIZE);
        points[2] = Point(0,BLOCK_SIZE);
        points[3] = Point(0,BLOCK_SIZE * 2);
    }
};

class I_Block: public Block
{
public:
    I_Block()
    {
        points[0] = Point();
        points[1] = Point(0,BLOCK_SIZE);
        points[2] = Point(0,BLOCK_SIZE * 2);
        points[3] = Point(0,BLOCK_SIZE * 3);
    }
};

class O_Block: public Block
{
public:
    O_Block()
    {
        points[0] = Point();
        points[1] = Point(0,BLOCK_SIZE);
        points[2] = Point(BLOCK_SIZE,0);
        points[3] = Point(BLOCK_SIZE,BLOCK_SIZE);
    }
};

class T_Block: public Block
{
public:
    T_Block()
    {
        points[0] = Point();
        points[1] = Point(-BLOCK_SIZE);
        points[2] = Point(BLOCK_SIZE);
        points[3] = Point(0,BLOCK_SIZE);
    }
};

#endif 
