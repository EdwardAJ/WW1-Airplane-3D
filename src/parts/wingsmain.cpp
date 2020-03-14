#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingsmain.h"
#include "utils.h"

void drawWingsmain() {
    double Xmin = -1.00, Xmax = 0.00;
    double Ymin = -0.10, Ymax = 0.10;
    double Zmin = -2.00, Zmax = 2.00;

    /* Sayap pertama */
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);

    Xmin = -1.00, Xmax = 0.00;
    Ymin =  0.90, Ymax = 1.10;
    Zmin = -2.00, Zmax = 2.00;

    /* Sayap pertama */
    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}
