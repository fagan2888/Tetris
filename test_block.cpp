#ifdef _WIN32
#include "Headers\components.h"
#define GLUT_DISABLE_ATEXIT_HACK
#define DELAY 12
#endif

#ifdef __linux
#include "Headers/components.h"
#define DELAY 1
#endif

#ifdef MACRO
#include "Headers/components.h"
#define DELAY 12
#endif

//Components
Block current_block,next_block;
int block_map[ROW + 2][COLUMN + 2];
int row_fill[ROW + 2];

//View Parameters
clock_t previous,current;
int speed = 90000;
int dropspeed = 200;
vector<Block> block_list;

void getNextBlock()
{
    int block_type = rand() % 7;
    switch (block_type)
    {
        case 0:
            next_block = S_Block(START_ROW,START_COLUMN);
            break;
        case 1:
            next_block = Z_Block(START_ROW,START_COLUMN);
            break;
        case 2:
            next_block = L_Block(START_ROW,START_COLUMN);
            break;
        case 3:
            next_block = J_Block(START_ROW,START_COLUMN);
            break;
        case 4:
            next_block = I_Block(START_ROW,START_COLUMN);
            break;
        case 5:
            next_block = O_Block(START_ROW,START_COLUMN);
            break;
        case 6:
            next_block = T_Block(START_ROW,START_COLUMN);
            break;
    }
}

void init()
{
	glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    for (int i = 0;i <= ROW + 1;i++)
    {
        for (int j = 0;j <= COLUMN + 1;j++)
        {
            if (i == 0 || i == ROW + 1 || j == 0 || j == COLUMN + 1)
                block_map[i][j] = 1;
            else block_map[i][j] = 0;
        }
        row_fill[i] = 0;
    }
    previous = clock();
    srand(time(0));
    getNextBlock();
    current_block = next_block;
    getNextBlock();
}

void drawBlock(Block block){
    list<Point>::iterator p;
    for (p = block.points.begin();p != block.points.end();p++)
    {
        double x = (*p).column * BLOCK_SIZE, y = (*p).row * BLOCK_SIZE, z = (*p).depth * BLOCK_SIZE;
        glColor3f(block.color[0],block.color[1],block.color[2]);
        glBegin(GL_QUADS);
            glVertex3f(x + BLOCK_SIZE / 2, y + BLOCK_SIZE / 2, z + 0.0f);
            glVertex3f(x - BLOCK_SIZE / 2, y + BLOCK_SIZE / 2, z + 0.0f);
            glVertex3f(x - BLOCK_SIZE / 2, y - BLOCK_SIZE / 2, z + 0.0f);
            glVertex3f(x + BLOCK_SIZE / 2, y - BLOCK_SIZE / 2, z + 0.0f);
        glEnd();

        glColor3f(0.4f,0.4f,0.4f);
        glBegin(GL_LINE_LOOP);
            glVertex3f(x + BLOCK_SIZE / 2, y + BLOCK_SIZE / 2, z - 0.2f);
            glVertex3f(x - BLOCK_SIZE / 2, y + BLOCK_SIZE / 2, z - 0.2f);
            glVertex3f(x - BLOCK_SIZE / 2, y - BLOCK_SIZE / 2, z - 0.2f);
            glVertex3f(x + BLOCK_SIZE / 2, y - BLOCK_SIZE / 2, z - 0.2f);
        glEnd();
    }
	return;
}

void drawContainer()
{
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex3f(LEFT_BORDER,TOP_BORDER,-1.0f);
        glVertex3f(LEFT_BORDER,BOTTOM_BORDER,-1.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(RIGHT_BORDER,TOP_BORDER,-1.0f);
        glVertex3f(RIGHT_BORDER,BOTTOM_BORDER,-1.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(LEFT_BORDER,BOTTOM_BORDER,-1.0f);
        glVertex3f(RIGHT_BORDER,BOTTOM_BORDER,-1.0f);
    glEnd();

    glColor3f(0.1f,0.1f,0.1f);
    for (int i = 1;i <= ROW;i++)
    {
        glBegin(GL_LINES);
            glVertex3f(LEFT_BORDER,BOTTOM_BORDER + i * BLOCK_SIZE,0.1f);
            glVertex3f(RIGHT_BORDER,BOTTOM_BORDER + i * BLOCK_SIZE,0.1f);
        glEnd();
    }
    for (int i = 1;i <= COLUMN;i++)
    {
        glBegin(GL_LINES);
            glVertex3f(LEFT_BORDER + i * BLOCK_SIZE,TOP_BORDER,0.1f);
            glVertex3f(LEFT_BORDER + i * BLOCK_SIZE,BOTTOM_BORDER,0.1f);
        glEnd();
    }
}

void drawTetris()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

    drawContainer();
    glPushMatrix();
        glTranslatef(BLOCK_SIZE - 1.0f,BLOCK_SIZE - 1.0f,0.0f);
        if (!current_block.isStop)
            drawBlock(current_block);
        else
        {
            current_block.occupy();
            block_list.push_back(current_block);
            current_block = next_block;
            getNextBlock();
        }
        for (int i = 0;i < block_list.size();i++)
            drawBlock(block_list[i]);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(BLOCK_SIZE + 0.1f,BLOCK_SIZE - 1.05f,0.0f);
        drawBlock(next_block);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void refreshTetris(int c)
{
    current = clock();
    if (current - previous >= speed)
    {
        if (!current_block.isBottom())
            current_block.down();
        previous = clock();
    }

    glutPostRedisplay();
    glutTimerFunc(DELAY,refreshTetris,0);
}

void keyboardSpecial(int key,int x,int y)
{
    glutSetKeyRepeat(0);
    switch (key)
    {
        case GLUT_KEY_LEFT:
            if (!current_block.isLeft() && !current_block.isBottom())
                current_block.left();
            break;
        case GLUT_KEY_RIGHT:
            if (!current_block.isRight() && !current_block.isBottom())
                current_block.right();
            break;
        case GLUT_KEY_UP:
            if (!current_block.isBottom())
                current_block.rotate();
            break;
        case GLUT_KEY_DOWN:
            if (!current_block.isBottom())
                current_block.drop();
            break;
    }
}

void keyboardControl(unsigned char key,int x,int y)
{
    switch (key)
    {
		case 27:
			exit(0);
        default:
            break;
    }
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Tetris");
    init();
    glutSpecialFunc(keyboardSpecial);
    glutKeyboardFunc(keyboardControl);
    glutDisplayFunc(drawTetris);
    refreshTetris(0);
    glutMainLoop();
    return 0;
}