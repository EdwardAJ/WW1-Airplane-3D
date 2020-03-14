#include <GLUT/glut.h>
#include <cmath>
#include <iostream>
#include "utils.cpp"

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
            originXcoord, originYcoord, originZcoord,
            upXcoord, upYcoord, upZcoord
    );
}

void drawAndFlush() {
    drawCube3D();
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
            ph = ph + 5;
            break;
        case GLUT_KEY_DOWN:
            ph = ph - 5;
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


int main(int argc, char **argv) {

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