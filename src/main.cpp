#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <iostream>

#include "parts/utils.h"
#include "parts/body.h"
#include "parts/propeller.h"
#include "parts/wingsmain.h"
#include "parts/wingstail.h"

using namespace std;

// Global variables
int th;
int ph;
int width = 1000;
int height = 600;
int movex = 0;
int movey = 0;

int moveUpx = 0;
int moveUpy = 0;
int moveUpz = 0;

// Field of view
double fov = 55;
double asp = width / height;
double dist = 8.0;

double angle = 0;

double value[55];

void drawWindow();
void keyboardControl(int key, int x, int y);
void display();
void draw3D();

void draw3D () {
    double Xmin = -2.25, Xmax = -2.50;
    double Ymin = -0.25, Ymax =  0.25;
    double Zmin = -1.00, Zmax =  1.00;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawWindow() {
    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, asp, dist/4, dist*4);
    glTranslatef(-movex, -movey, -movex);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initializeDisplay () {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
}

void setCameraForCirclingObject() {
    double thDegree = getDegreeFromRadian(th);
    double phDegree = getDegreeFromRadian(ph);

    // circling horizontal
    double eyeXcoord = dist * cos(thDegree);
    double eyeYcoord = 0;
    double eyeZcoord = dist * sin(thDegree);

    double originXcoord = 0;
    double originYcoord = 0;
    double originZcoord = 0;

    double upXcoord = 0 + moveUpx;
    double upYcoord = 1 + moveUpy;
    double upZcoord = 0 + moveUpz;

    gluLookAt(eyeXcoord, eyeYcoord, eyeZcoord,
            originXcoord, originYcoord, originZcoord,upXcoord, upYcoord, upZcoord
    );
}

void drawAndFlush() {
    //drawCube3D();
    glRotatef(angle, 1, 0, 0);
    drawBody(value);
    drawPropeller(value);
    drawWingsmain(value);
    drawWingstail(value);
    glFlush();
    glutSwapBuffers();
}


void displayCirclingObject() {
    initializeDisplay();
    setCameraForCirclingObject();
    drawAndFlush();
}

void specialKeyboardControl (int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            th = th + 5;
            break;
        case GLUT_KEY_LEFT:
            th = th - 5;
            break;
        case GLUT_KEY_UP:
            angle = angle - 10;
            break;
        case GLUT_KEY_DOWN:
            angle = angle + 10;
            break;
        case GLUT_KEY_F1:
            exit(0);
            break;
    }
    displayCirclingObject();

    th = th % 360;
    ph = ph % 360;

    drawWindow();
    glutPostRedisplay();
}

void ordinaryKeyboardControl(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':
            fov = fov + 5;
            break;
        case 'z':
            fov = fov - 5;
            break;
        case 'a':
            movex += 1;
            break;
        case 'd':
            movex -= 1;
            break;
        case 'w':
            movey += 1;
            break;
        case 's':
            movey -= 1;
            break;
        case 'i':
            moveUpy += 1;
            break;
        case 'k':
            moveUpy -= 1;
            break;
        case 'j':
            moveUpx -= 1;
            break;
        case 'l':
            moveUpx += 1;
            break;
        case 'm':
            moveUpz -= 1;
            break;
        case 'n':
            moveUpz += 1;
            break;
    }

    drawWindow();
    glutPostRedisplay();
}

void removeDupWord(string str, int i) {
   char word[10];
   int p = 0;
   int j = 0;

   for (char x : str) {
       if (x == ' ') {
            value[i * 6 + j] = atof(word);
            for (int q=0; q<10; q++) {
                word[q] = ' ';
            }
            j = j + 1;
       }
       else {
            word[p] = x;
            p = p + 1;
       }
   }
   value[i * 6 + j] = atof(word);
}

int main(int argc, char **argv) {
    ifstream infile;
    string data;

    infile.open("input.txt");
    for(int i=0; i<9; i++) {
        infile >> data;
        removeDupWord(data,i);
    }
    infile.close();

    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("World War 1 Airplane Showcase");
    glutDisplayFunc(displayCirclingObject);
    glutSpecialFunc(specialKeyboardControl);
    glutKeyboardFunc(ordinaryKeyboardControl);
    glutMainLoop();

    return 0;
}
