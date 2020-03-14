#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wingsmain.h"

void drawSideWings() {
    /*Sayap pertama*/
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( -1.00, 0.1, -2.0);
    glVertex3f(0.00, 0.1, -2.0);
    glVertex3f(0.00, 0.1,  2.0);
    glVertex3f( -1.00, 0.1, 2.0);

    /* Kotak oren (bawah) */
    glColor3f(1.0, 1.00, 0.0);
    glVertex3f( -1.00, -0.1,  2.0);
    glVertex3f(0.00, -0.1,  2.0);
    glVertex3f(0.00, -0.1, -2.0);
    glVertex3f( -1.00, -0.1, -2.0);

    /* Kotak merah (kiri) */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( -1.00,  0.1, 2.0);
    glVertex3f(0.00,  0.1, 2.0);
    glVertex3f(0.00, -0.1, 2.0);
    glVertex3f( -1.00, -0.1, 2.0);

    /* Kotak kuning (kanan) */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( -1.00, -0.1, -2.0);
    glVertex3f(0.00, -0.1, -2.0);
    glVertex3f(0.00,  0.1, -2.0);
    glVertex3f( -1.00,  0.1, -2.0);

    /* Kotak biru (belakang) */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.00,  0.1,  2.0);
    glVertex3f(0.00,  0.1, -2.0);
    glVertex3f(0.00, -0.1, -2.0);
    glVertex3f(0.00, -0.1,  2.0);

    /* Kotak pink (depan) */
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.00,  0.1, -2.0);
    glVertex3f(-1.00,  0.1,  2.0);
    glVertex3f(-1.00, -0.1,  2.0);
    glVertex3f(-1.00, -0.1, -2.0);

    glEnd();
}

void drawUpperWings() {
    /* Sayap kedua */
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( -1.00, 1.1, -2.0);
    glVertex3f(0.00, 1.1, -2.0);
    glVertex3f(0.00, 1.1,  2.0);
    glVertex3f( -1.00, 1.1, 2.0);

    /* Kotak oren (bawah) */
    glColor3f(1.0, 1.00, 0.0);
    glVertex3f( -1.00, 0.9,  2.0);
    glVertex3f(0.00, 0.9,  2.0);
    glVertex3f(0.00, 0.9, -2.0);
    glVertex3f( -1.00, 0.9, -2.0);

    /* Kotak merah (kiri) */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( -1.00,  1.1, 2.0);
    glVertex3f(0.00,  1.1, 2.0);
    glVertex3f(0.00, 0.9, 2.0);
    glVertex3f( -1.00, 0.9, 2.0);

    /* Kotak kuning (kanan) */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( -1.00, 0.9, -2.0);
    glVertex3f(0.00, 0.9, -2.0);
    glVertex3f(0.00,  1.1, -2.0);
    glVertex3f( -1.00,  1.1, -2.0);

    /* Kotak biru (belakang) */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.00,  1.1,  2.0);
    glVertex3f(0.00,  1.1, -2.0);
    glVertex3f(0.00, 0.9, -2.0);
    glVertex3f(0.00, 0.9,  2.0);

    /* Kotak pink (depan) */
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.00,  1.1, -2.0);
    glVertex3f(-1.00,  1.1,  2.0);
    glVertex3f(-1.00, 0.9,  2.0);
    glVertex3f(-1.00, 0.9, -2.0);

    glEnd();
}

void drawUpperWingBrace() {
    glBegin(GL_QUADS);
    /* Patokan dari kotak warna pink */
    /* x : depan +, belakang - */
    /* y : atas +, bawah - */
    /* z : kiri +, kanan - */

    /* Kotak hijau (atas) */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( -1.0, 1.0, -0.1);
    glVertex3f(0.0, 1.0, -0.1);
    glVertex3f(0.0, 1.0,  0.1);
    glVertex3f(-1.0, 1.0, 0.1);

    /* Kotak oren (bawah) */
    glColor3f(1.0, 0.1, 0.0);
    glVertex3f(-1.0, -0.75,  0.1);
    glVertex3f(0.0, -0.75,  0.1);
    glVertex3f(0.0, -0.75, -0.1);
    glVertex3f(-1.0, -0.75, -0.1);

    /* Kotak merah (kiri) */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0,  1.0, 0.1);
    glVertex3f(0.0,  1.0, 0.1);
    glVertex3f(0.0, -0.75, 0.1);
    glVertex3f(-1.0, -0.75, 0.1);

    /* Kotak kuning (kanan) */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, -0.75, -0.1);
    glVertex3f(0.0, -0.75, -0.1);
    glVertex3f(0.0,  1.0, -0.1);
    glVertex3f(-1.0,  1.0, -0.1);

    /* Kotak biru (belakang) */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0,  1.0,  0.1);
    glVertex3f(0.0,  1.0, -0.1);
    glVertex3f(0.0, -0.75, -0.1);
    glVertex3f(0.0, -0.75,  0.1);

    /* Kotak pink (depan) */
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0,  1.0, -0.1);
    glVertex3f(-1.0,  1.0,  0.1);
    glVertex3f(-1.0, -0.75,  0.1);
    glVertex3f(-1.0, -0.75, -0.1);

    glEnd();
}

void drawWingsmain() {
    drawSideWings();
    drawUpperWings();
    drawUpperWingBrace();
}
