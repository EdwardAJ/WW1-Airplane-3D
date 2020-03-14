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

#define SPEED_FAST 10
#define SPEED_MEDIUM 5
#define SPEED_SLOW 1

using namespace std;

// Global variables
int th;
int ph;
int width = 1000;
int height = 600;
int moveWorldx = 0;
int moveWorldy = 0;

int moveCameraUpx = 0;
int moveCameraUpy = 0;
int moveCameraUpz = 0;

int angleObjectx = 0;
int angleObjecty = 0;
int angleObjectz = 0;

// Field of view
double fov = 55;
double asp = width / height;
double dist = 8.0;

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
    glTranslatef(-moveWorldx, -moveWorldy, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initializeDisplay () {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    bool isShadingOn = true;
    /* Lightning */
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat ambientLight[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat diffuseLight[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat specularLight[] = {0.0, 1.0, 0.0, 1.0};

    /* Lightning Position */
    GLfloat positionLight[] = {2.5, 2.5, 2.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight);

    /* Set material */
    if (isShadingOn) {
        GLfloat a[] = {0.3, 0.3, 0.3, 1.0};
        GLfloat d[] = {0.7, 0.7, 0.7, 1.0};
        GLfloat s[] = {1.0, 1.0, 1.0, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT, a);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
        glMaterialfv(GL_FRONT, GL_SPECULAR, s);
        glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
    }

}

void setCameraWorld() {
    double thDegree = getDegreeFromRadian(th);
    double phDegree = getDegreeFromRadian(ph);

    // circling horizontal
    double eyeXcoord = dist * cos(thDegree);
    double eyeYcoord = 0;
    double eyeZcoord = dist * sin(thDegree);

    double originXcoord = 0;
    double originYcoord = 0;
    double originZcoord = 0;

    double upXcoord = 0 + moveCameraUpx;
    double upYcoord = 1 + moveCameraUpy;
    double upZcoord = 0 + moveCameraUpz;

    gluLookAt(eyeXcoord, eyeYcoord, eyeZcoord,
            originXcoord, originYcoord, originZcoord,upXcoord, upYcoord, upZcoord
    );
}

void drawAirplane() {
    glRotatef(angleObjectx, 1, 0, 0);
    glRotatef(angleObjecty, 0, 1, 0);
    glRotatef(angleObjectz, 0, 0, 1);
    drawBody();
    drawPropeller();
    drawWingstail();
    drawWingsmain();
}

void drawAndFlush() {
    drawBody();
    drawPropeller();
    drawWingstail();
    drawWingsmain();
    drawAirplane();
    glFlush();
    glutSwapBuffers();
}


void displayWorld() {
    initializeDisplay();
    setCameraWorld();
    drawAndFlush();
}

void resetView() {
    th = 0;
    ph = 0;
    moveWorldx = 0;
    moveWorldy = 0;

    moveCameraUpx = 0;
    moveCameraUpy = 0;
    moveCameraUpz = 0;

    angleObjectx = 0;
    angleObjecty = 0;
    angleObjectz = 0;
}

void specialKeyboardControl (int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            th = th + SPEED_FAST;
            break;
        case GLUT_KEY_LEFT:
            th = th - SPEED_FAST;
            break;
        case GLUT_KEY_UP:
            ph = ph + SPEED_FAST;
            break;
        case GLUT_KEY_DOWN:
            ph = ph - SPEED_FAST;
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

void ordinaryKeyboardControl(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':
            fov = fov + SPEED_MEDIUM;
            break;
        case 'z':
            fov = fov - SPEED_MEDIUM;
            break;
        case 'a':
            moveWorldx -= SPEED_SLOW;
            break;
        case 'd':
            moveWorldx += SPEED_SLOW;
            break;
        case 'w':
            moveWorldy += SPEED_SLOW;
            break;
        case 's':
            moveWorldy -= SPEED_SLOW;
            break;
        case 'i':
            moveCameraUpy += SPEED_MEDIUM;
            break;
        case 'k':
            moveCameraUpy -= SPEED_MEDIUM;
            break;
        case 'j':
            moveCameraUpx -= SPEED_MEDIUM;
            break;
        case 'l':
            moveCameraUpx += SPEED_MEDIUM;
            break;
        case 'm':
            moveCameraUpz -= SPEED_MEDIUM;
            break;
        case 'n':
            moveCameraUpz += SPEED_MEDIUM;
            break;
        case '1':
            angleObjectx += SPEED_FAST;
            break;
        case '2':
            angleObjectx -= SPEED_FAST;
            break;
        case '3':
            angleObjecty += SPEED_FAST;
            break;
        case '4':
            angleObjecty -= SPEED_FAST;
            break;
        case '5':
            angleObjectz += SPEED_FAST;
            break;
        case '6':
            angleObjectz -= SPEED_FAST;
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

void displayPrintMenu() {
    cout << "Selamat datang di Kelompok Grafika Komputer!" << endl;
    cout << "Berikut ini adalah berbagai menu yang tersedia:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "MOVE WORLD: " << endl;
    cout << "Key W, A, S, dan D digunakan untuk menggerakan kamera pada sumbu horizontal dan vertikal." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "ROTATE CAMERA'S VECTOR UP: " << endl;
    cout << "Key J dan L digunakan untuk memutar vector up kamera pada sumbu -X dan X" << endl;
    cout << "Key I dan K digunakan untuk memutar vector up kamera pada sumbu Y dan -Y" << endl;
    cout << "Key M dan N digunakan untuk memutar vector up kamera pada sumbu -Z dan Z" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "CAMERA ZOOM: " << endl;
    cout << "Key X dan Z digunakan untuk menggerakan kamera pada sumbu -Z dan Z" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "ROTATE CAMERA IN CIRCLE PATH: " << endl;
    cout << "Key ArrowLeft dan ArrowRight untuk memutar kamera secara counterclockwise dan clockwise" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "ROTATE OBJECT: " << endl;
    cout << "Key 1 dan 2 digunakan untuk memutar object pada sumbu X dan -X" << endl;
    cout << "Key 3 dan 4 digunakan untuk memutar vector up kamera pada sumbu Y dan -Y" << endl;
    cout << "Key 5 dan 6 digunakan untuk memutar vector up kamera pada sumbu Z dan -Z" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "SHADER: " << endl;
    cout << "Key Enter digunakan untuk memberi atau melepas shader warna" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "MERESET DEFAULT VIEW DAN MENGELUARKAN HELP MENU: " << endl;
    cout << "Tekan tombol klik kiri untuk mereset view ke state semula" << endl;
    cout << "-------------------------------------------------" << endl;
}

void mouseControl(int button, int state, int x, int y) {
    switch(button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                resetView();
                displayPrintMenu();
                drawWindow();
                glutPostRedisplay();
            }
        break;
    }
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
    glutDisplayFunc(displayWorld);
    glutSpecialFunc(specialKeyboardControl);
    glutKeyboardFunc(ordinaryKeyboardControl);
    glutMouseFunc(mouseControl);

    displayPrintMenu();
    glutMainLoop();

    return 0;
}
