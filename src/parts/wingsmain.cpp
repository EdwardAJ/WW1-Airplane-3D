#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingsmain.h"
#include "utils.h"

void drawSideWings(double value[], double colorValues[]) {
    /*Sayap pertama*/
    int i = 4;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}

void drawUpperWings(double value[], double colorValues[]) {
    /* Sayap kedua */
    int i = 5;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}

void drawUpperWingBrace(double value[], double colorValues[]) {
    /* Konektor */
    int i = 6;
    double Xmin = value[i * 6 + 0], Xmax = value[i * 6 + 1];
    double Ymin = value[i * 6 + 2], Ymax = value[i * 6 + 3];
    double Zmin = value[i * 6 + 4], Zmax = value[i * 6 + 5];

    double red = colorValues[i * 3 + 0], green = colorValues[i * 3 + 1], blue = colorValues[i * 3 + 2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}

void drawWingsmain(double value[], double colorValues[]) {
    drawSideWings(value, colorValues);
    drawUpperWings(value, colorValues);
    drawUpperWingBrace(value, colorValues);
}
