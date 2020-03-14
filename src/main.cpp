#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>
#include <iostream>
#include "utils.cpp"

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
// Field of view
double fov = 55;
double asp = width / height;
double dist = 8.0;

void drawWindow();
void keyboardControl(int key, int x, int y);
void keyboardBasicControl(unsigned char key, int x, int y);
void display();
void draw3D();

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
        case GLUT_KEY_F1:
            exit(0);
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

    double thDegree = getDegreeFromRadian(th);
    double phDegree = getDegreeFromRadian(ph);

    // double eyeXcoord = dist * cos(thDegree) * cos(phDegree);
    // double eyeYcoord = 0;
    // double eyeZcoord = dist * sin(thDegree) * cos(phDegree);

    double eyeXcoord = dist * sin(thDegree) * cos(phDegree);
    double eyeYcoord = dist * cos(thDegree) * sin(phDegree);
    double eyeZcoord = dist * cos(thDegree) * cos(phDegree);

    // double originXcoord = -1 * cos(thDegree);
    // double originXcoord = -1 * sin(thDegree) * cos(phDegree);
    double originXcoord = sin(thDegree) * cos(phDegree);
    double originYcoord = cos(thDegree) * sin(phDegree);
    double originZcoord = cos(thDegree) * cos(phDegree);
    // double originZcoord = -1 * sin(thDegree);
    // double originZcoord = -1 * cos(thDegree) * cos(phDegree);

    double upXcoord = 0;
    double upYcoord = cos(phDegree);
    double upZcoord = 0;

    gluLookAt(eyeXcoord, eyeYcoord, eyeZcoord,
            originXcoord, originYcoord, originZcoord,
            upXcoord, upYcoord, upZcoord
    );

    drawBody();
    //draw3D();
    //drawPropeller();
    drawWingsmain();
    //drawWingstail();

    glFlush();
    glutSwapBuffers();
}

void draw3D () {
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 2.0, 0.75, -0.5);
    glVertex3f(-2.0, 0.75, -0.5);
    glVertex3f(-2.0, 0.75,  0.5);
    glVertex3f( 2.0, 0.75, 0.5);

    /* Kotak oren (bawah) */
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f( 2.0, -0.75,  0.5);
    glVertex3f(-2.0, -0.75,  0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f( 2.0, -0.75, -0.5);

    /* Kotak merah (kiri) */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 2.0,  0.75, 0.5);
    glVertex3f(-2.0,  0.75, 0.5);
    glVertex3f(-2.0, -0.75, 0.5);
    glVertex3f( 2.0, -0.75, 0.5);

    /* Kotak kuning (kanan) */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( 2.0, -0.75, -0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f(-2.0,  0.75, -0.5);
    glVertex3f( 2.0,  0.75, -0.5);

    /* Kotak biru (belakang) */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-2.0,  0.75,  0.5);
    glVertex3f(-2.0,  0.75, -0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f(-2.0, -0.75,  0.5);

    /* Kotak pink (depan) */
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(2.0,  0.75, -0.5);
    glVertex3f(2.0,  0.75,  0.5);
    glVertex3f(2.0, -0.75,  0.5);
    glVertex3f(2.0, -0.75, -0.5);

    glEnd();
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
