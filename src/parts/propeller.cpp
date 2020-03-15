#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "propeller.h"
#include "utils.h"

void drawPropeller(double value[], double colorValues[]) {
    drawPropellerHorizontal(value, colorValues);
    drawPropellerVertical(value, colorValues);
    drawPropellerConnector(value, colorValues);
}

void drawPropellerHorizontal(double value[], double colorValues[]) {
    int i = 1;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}

void drawPropellerVertical(double value[], double colorValues[]) {
    int i = 2;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

   double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
   drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}

void drawPropellerConnector(double value[], double colorValues[]) {
    int i = 3;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}
