#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>
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

    /* Lightning */
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat ambientLight[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat diffuseLight[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat specularLight[] = {1.0, 1.0, 1.0, 1.0};

    /* Lightning Position */
    GLfloat positionLight[] = {2.5, 2.5, 2.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight);
    GLfloat positionLight2[] = {-2.5, -2.5, -2.0, 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, positionLight2);

    /* Set material */
    GLfloat a[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat d[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat s[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, a);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
    glMaterialfv(GL_FRONT, GL_SPECULAR, s);
    glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

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
    drawBody();
    drawPropeller();
    drawWingstail();
    drawWingsmain();
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
