#include<windows.h>
#include <GL/glut.h>
#include <cmath>

void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    glBegin(GL_POINTS);

    while (x <= y) {
        // Draw points for all eight octants
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;

        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glPointSize(2.0);

    int xc = 120;
    int yc = 120;
    int radius = 55;

    drawCircle(xc, yc, radius);

    glColor3f(1.0,0.0,0.0);
    xc=120;
    yc=120;
    radius=45;

    drawCircle(xc,yc,radius);


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Circle with Lines on Circumference");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
