#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "propeller.h"
#include "utils.h"

void drawPropeller() {
    drawPropellerHorizontal();
    drawPropellerVertical();
    drawPropellerConnector();
}

void drawPropellerHorizontal() {
    double Xmin = -2.25, Xmax = -2.50;
    double Ymin = -0.25, Ymax =  0.25;
    double Zmin = -1.00, Zmax =  1.00;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawPropellerVertical() {
    double Xmin = -2.25, Xmax = -2.50;
    double Ymin = -1.00, Ymax =  1.00;
    double Zmin = -0.25, Zmax =  0.25;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawPropellerConnector() {
    double Xmin = -2.25, Xmax = -2.00;
    double Ymin = -0.25, Ymax =  0.25;
    double Zmin = -0.25, Zmax =  0.25;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}
