#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "body.h"
#include "utils.h"

void drawBody() {
    double Xmin = -2.00, Xmax =  2.00;
    double Ymin = -0.75, Ymax =  0.75;
    double Zmin = -0.50, Zmax =  0.50;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}
