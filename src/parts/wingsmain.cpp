#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingsmain.h"
#include "utils.h"

void drawSideWings(double value[]) {
    /*Sayap pertama*/
    int i = 4;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawUpperWings(double value[]) {
    /* Sayap kedua */
    int i = 5;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawUpperWingBrace(double value[]) {
    /* Konektor */
    int i = 6;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawWingsmain(double value[]) {
    drawSideWings(value);
    drawUpperWings(value);
    drawUpperWingBrace(value);
}
