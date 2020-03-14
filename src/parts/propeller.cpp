#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "propeller.h"

void drawPropeller() {
    drawPropellerHorizontal();
    drawPropellerVertical();
    drawPropellerConnector();
}

void drawPropellerHorizontal() {
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.5, 1.5, 0.5);
    glVertex3f( -2.25, 0.25, -1);
    glVertex3f( -2.50, 0.25, -1);
    glVertex3f( -2.50, 0.25,  1);
    glVertex3f( -2.25, 0.25,  1);

    /* Kotak oren (bawah) */
    glColor3f(1.5, -2.50, 0.5);
    glVertex3f( -2.25, -0.25,  1);
    glVertex3f( -2.50, -0.25,  1);
    glVertex3f( -2.50, -0.25, -1);
    glVertex3f( -2.25, -0.25, -1);

    /* Kotak merah (kiri) */
    glColor3f(1.5, 0.5, 0.5);
    glVertex3f( -2.25,  0.25, 1);
    glVertex3f( -2.50,  0.25, 1);
    glVertex3f( -2.50, -0.25, 1);
    glVertex3f( -2.25, -0.25, 1);

    /* Kotak kuning (kanan) */
    glColor3f(1.5, 1.5, 0.5);
    glVertex3f( -2.25, -0.25, -1);
    glVertex3f( -2.50, -0.25, -1);
    glVertex3f( -2.50,  0.25, -1);
    glVertex3f( -2.25,  0.25, -1);

    /* Kotak biru (belakang) */
    glColor3f(0.5, 0.5, 1.5);
    glVertex3f( -2.50,  0.25,  1);
    glVertex3f( -2.50,  0.25, -1);
    glVertex3f( -2.50, -0.25, -1);
    glVertex3f( -2.50, -0.25,  1);

    /* Kotak pink (depan) */
    glColor3f(1.5, 0.5, 1.5);
    glVertex3f( -2.25,  0.25, -1);
    glVertex3f( -2.25,  0.25,  1);
    glVertex3f( -2.25, -0.25,  1);
    glVertex3f( -2.25, -0.25, -1);

    glEnd();
}

void drawPropellerVertical() {
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.5, 1.5, 0.5);
    glVertex3f( -2.25, 1.00, -0.25);
    glVertex3f( -2.50, 1.00, -0.25);
    glVertex3f( -2.50, 1.00,  0.25);
    glVertex3f( -2.25, 1.00,  0.25);

    /* Kotak oren (bawah) */
    glColor3f(1.5, -2.50, 0.5);
    glVertex3f( -2.25, -1.00,  0.25);
    glVertex3f( -2.50, -1.00,  0.25);
    glVertex3f( -2.50, -1.00, -0.25);
    glVertex3f( -2.25, -1.00, -0.25);

    /* Kotak merah (kiri) */
    glColor3f(1.5, 0.5, 0.5);
    glVertex3f( -2.25,  1.00, 0.25);
    glVertex3f( -2.50,  1.00, 0.25);
    glVertex3f( -2.50, -1.00, 0.25);
    glVertex3f( -2.25, -1.00, 0.25);

    /* Kotak kuning (kanan) */
    glColor3f(1.5, 1.5, 0.5);
    glVertex3f( -2.25, -1.00, -0.25);
    glVertex3f( -2.50, -1.00, -0.25);
    glVertex3f( -2.50,  1.00, -0.25);
    glVertex3f( -2.25,  1.00, -0.25);

    /* Kotak biru (belakang) */
    glColor3f(0.5, 0.5, 1.5);
    glVertex3f( -2.50,  1.00,  0.25);
    glVertex3f( -2.50,  1.00, -0.25);
    glVertex3f( -2.50, -1.00, -0.25);
    glVertex3f( -2.50, -1.00,  0.25);

    /* Kotak pink (depan) */
    glColor3f(1.5, 0.5, 1.5);
    glVertex3f( -2.25,  1.00, -0.25);
    glVertex3f( -2.25,  1.00,  0.25);
    glVertex3f( -2.25, -1.00,  0.25);
    glVertex3f( -2.25, -1.00, -0.25);

    glEnd();
}

void drawPropellerConnector() {
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.5, 1.5, 0.5);
    glVertex3f( -2.00, 0.25, -0.25);
    glVertex3f( -2.25, 0.25, -0.25);
    glVertex3f( -2.25, 0.25,  0.25);
    glVertex3f( -2.00, 0.25,  0.25);

    /* Kotak oren (bawah) */
    glColor3f(1.5, -2.50, 0.5);
    glVertex3f( -2.00, -0.25,  0.25);
    glVertex3f( -2.25, -0.25,  0.25);
    glVertex3f( -2.25, -0.25, -0.25);
    glVertex3f( -2.00, -0.25, -0.25);

    /* Kotak merah (kiri) */
    glColor3f(1.5, 0.5, 0.5);
    glVertex3f( -2.00,  0.25, 0.25);
    glVertex3f( -2.25,  0.25, 0.25);
    glVertex3f( -2.25, -0.25, 0.25);
    glVertex3f( -2.00, -0.25, 0.25);

    /* Kotak kuning (kanan) */
    glColor3f(1.5, 1.5, 0.5);
    glVertex3f( -2.00, -0.25, -0.25);
    glVertex3f( -2.25, -0.25, -0.25);
    glVertex3f( -2.25,  0.25, -0.25);
    glVertex3f( -2.00,  0.25, -0.25);

    /* Kotak biru (belakang) */
    glColor3f(0.5, 0.5, 1.5);
    glVertex3f( -2.25,  0.25,  0.25);
    glVertex3f( -2.25,  0.25, -0.25);
    glVertex3f( -2.25, -0.25, -0.25);
    glVertex3f( -2.25, -0.25,  0.25);

    /* Kotak pink (depan) */
    glColor3f(1.5, 0.5, 1.5);
    glVertex3f( -2.00,  0.25, -0.25);
    glVertex3f( -2.00,  0.25,  0.25);
    glVertex3f( -2.00, -0.25,  0.25);
    glVertex3f( -2.00, -0.25, -0.25);

    glEnd();
}
