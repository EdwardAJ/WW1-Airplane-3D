#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "utils.h"

double red1 = 1.0, green1 = 0.0, blue1 = 0.0;
double red2 = 0.0, green2 = 1.0, blue2 = 0.0;
double red3 = 0.0, green3 = 0.0, blue3 = 1.0;
double red4 = 0.9, green4 = 0.8, blue4 = 0.0;
double red5 = 1.0, green5 = 0.0, blue5 = 1.0;
double red6 = 0.0, green6 = 1.0, blue6 = 1.0;

double getDegreeFromRadian(double degree) {
    return degree * 3.141592653589793 / 180.0;
}

void drawCube3D () {
    double Xmin = -1.00, Xmax = 1.00;
    double Ymin = -1.00, Ymax = 1.00;
    double Zmin = -1.00, Zmax = 1.00;

    drawShape(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax);
}

void drawShape(double Xmin, double Xmax, double Ymin, double Ymax, double Zmin, double Zmax) {
    glBegin(GL_QUADS);

    glColor3f( red1, green1, blue1);
    glVertex3f( Xmin, Ymax, Zmin);
    glVertex3f( Xmax, Ymax, Zmin);
    glVertex3f( Xmax, Ymax, Zmax);
    glVertex3f( Xmin, Ymax, Zmax);

    glColor3f( red2, green2, blue2);
    glVertex3f( Xmin, Ymin, Zmax);
    glVertex3f( Xmax, Ymin, Zmax);
    glVertex3f( Xmax, Ymin, Zmin);
    glVertex3f( Xmin, Ymin, Zmin);

    glColor3f( red3, green3, blue3);
    glVertex3f( Xmin, Ymax, Zmax);
    glVertex3f( Xmax, Ymax, Zmax);
    glVertex3f( Xmax, Ymin, Zmax);
    glVertex3f( Xmin, Ymin, Zmax);

    glColor3f( red4, green4, blue4);
    glVertex3f( Xmin, Ymin, Zmin);
    glVertex3f( Xmax, Ymin, Zmin);
    glVertex3f( Xmax, Ymax, Zmin);
    glVertex3f( Xmin, Ymax, Zmin);

    glColor3f( red5, green5, blue5);
    glVertex3f( Xmax, Ymax, Zmax);
    glVertex3f( Xmax, Ymax, Zmin);
    glVertex3f( Xmax, Ymin, Zmin);
    glVertex3f( Xmax, Ymin, Zmax);

    glColor3f( red6, green6, blue6);
    glVertex3f( Xmin, Ymax, Zmin);
    glVertex3f( Xmin, Ymax, Zmax);
    glVertex3f( Xmin, Ymin, Zmax);
    glVertex3f( Xmin, Ymin, Zmin);

    glEnd();
}
