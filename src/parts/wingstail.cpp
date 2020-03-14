#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingstail.h"
#include "utils.h"

void drawWingstail() {
    drawWingstailVertical();
    drawWingstailHorizontal();
}

void drawWingstailVertical() {
    double Xmin =  1.00, Xmax = 2.00;
    double Ymin =  0.75, Ymax = 1.25;
    double Zmin = -0.25, Zmax = 0.25;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawWingstailHorizontal() {
    double Xmin =  1.00, Xmax =  2.00;
    double Ymin = -0.25, Ymax =  0.25;
    double Zmin = -1.00, Zmax =  1.00;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}
