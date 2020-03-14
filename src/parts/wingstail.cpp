#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingstail.h"
#include "utils.h"

void drawWingstail(double value[]) {
    drawWingstailVertical(value);
    drawWingstailHorizontal(value);
}

void drawWingstailVertical(double value[]) {
    int i = 7;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawWingstailHorizontal(double value[]) {
    int i = 8;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}
