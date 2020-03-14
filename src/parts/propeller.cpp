#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "propeller.h"
#include "utils.h"

void drawPropeller(double value[]) {
    drawPropellerHorizontal(value);
    drawPropellerVertical(value);
    drawPropellerConnector(value);
}

void drawPropellerHorizontal(double value[]) {
    int i = 1;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawPropellerVertical(double value[]) {
    int i = 2;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawPropellerConnector(double value[]) {
    int i = 3;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}
