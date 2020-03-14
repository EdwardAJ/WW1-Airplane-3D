#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "body.h"

void drawBody() {
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 2.0, 0.75, -0.5);
    glVertex3f(-2.0, 0.75, -0.5);
    glVertex3f(-2.0, 0.75,  0.5);
    glVertex3f( 2.0, 0.75, 0.5);

    /* Kotak oren (bawah) */
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f( 2.0, -0.75,  0.5);
    glVertex3f(-2.0, -0.75,  0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f( 2.0, -0.75, -0.5);

    /* Kotak merah (kiri) */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 2.0,  0.75, 0.5);
    glVertex3f(-2.0,  0.75, 0.5);
    glVertex3f(-2.0, -0.75, 0.5);
    glVertex3f( 2.0, -0.75, 0.5);

    /* Kotak kuning (kanan) */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( 2.0, -0.75, -0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f(-2.0,  0.75, -0.5);
    glVertex3f( 2.0,  0.75, -0.5);

    /* Kotak biru (belakang) */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-2.0,  0.75,  0.5);
    glVertex3f(-2.0,  0.75, -0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f(-2.0, -0.75,  0.5);

    /* Kotak pink (depan) */
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(2.0,  0.75, -0.5);
    glVertex3f(2.0,  0.75,  0.5);
    glVertex3f(2.0, -0.75,  0.5);
    glVertex3f(2.0, -0.75, -0.5);

    glEnd();
}
