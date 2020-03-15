#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingstail.h"
#include "utils.h"

void drawWingstail(double value[], double colorValues[]) {
    drawWingstailVertical(value, colorValues);
    drawWingstailHorizontal(value, colorValues);
}

void drawWingstailVertical(double value[], double colorValues[]) {
    int i = 7;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}

void drawWingstailHorizontal(double value[], double colorValues[]) {
    int i = 8;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}
