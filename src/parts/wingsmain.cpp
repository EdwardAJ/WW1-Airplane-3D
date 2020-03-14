#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingsmain.h"
#include "utils.h"

void drawSideWings() {
    /*Sayap pertama*/
    double Xmin = -1.00, Xmax = 0.00;
    double Ymin = -0.10, Ymax = 0.10;
    double Zmin = -2.00, Zmax = 2.00;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawUpperWings() {
    /* Sayap kedua */
    double Xmin = -1.00, Xmax = 0.00;
    double Ymin =  0.90, Ymax = 1.10;
    double Zmin = -2.00, Zmax = 2.00;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawUpperWingBrace() {
    /* Konektor */
    double Xmin = -1.00, Xmax = 0.00;
    double Ymin = -0.75, Ymax = 1.00;
    double Zmin = -0.10, Zmax = 0.10;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawWingsmain() {
    drawSideWings();
    drawUpperWings();
    drawUpperWingBrace();
}
