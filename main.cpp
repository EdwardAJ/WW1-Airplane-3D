#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "utils.cpp"

using namespace std;
// Global variables
int th;
int ph;
int width = 1000;
int height = 600;
// Field of view
double fov = 55;
double asp = width / height;
double dist = 8.0;

void drawWindow() {
    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, asp, dist/4, dist*4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboardControl (int key, int x, int y) {
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

    th = th % 360;
    ph = ph % 360;

    drawWindow();
    glutPostRedisplay();
}

void display() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    double degree = getDegreeFromRadian(th);
    double eyeXcoord = dist * cos(degree);
    double eyeYcoord = 0;
    double eyeZcoord = dist * sin(degree);

    double originXcoord = -1 * cos(degree);
    double originYcoord = 0;
    double originZcoord = -1 * sin(degree);

    double upXcoord = 0;
    double upYcoord = 1;
    double upZcoord = 0;

    gluLookAt(eyeXcoord, eyeYcoord, eyeZcoord,
            originXcoord, originYcoord, originZcoord,
            upXcoord, upYcoord, upZcoord
    );

    drawCube3D();
    glFlush();
    glutSwapBuffers();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("World War 1 Airplane Showcase");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboardControl);
    glutMainLoop();

    return 0;
}
