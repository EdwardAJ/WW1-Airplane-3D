#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "body.h"
#include "utils.h"

void drawBody(double value[], double colorValues[]) {
    double Xmin = value[0], Xmax = value[1];
    double Ymin = value[2], Ymax = value[3];
    double Zmin = value[4], Zmax = value[5];

    double red = colorValues[0], green = colorValues[1], blue = colorValues[2];
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax, red, green, blue);
}
