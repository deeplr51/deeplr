#include<windows.h>
#include <GL/glut.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dxSign = (dx >= 0) ? 1 : -1;
    int dySign = (dy >= 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);

    int x = x1;
    int y = y1;
    int p = 2 * dy - dx;

    glBegin(GL_POINTS);

    while (x != x2) {
        glVertex2i(x, y);
        x += dxSign;
        if (p >= 0) {
            y += dySign;
            p -= 2 * dx;
        }
        p += 2 * dy;
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glPointSize(2.0);

    int x1 = 100;
    int y1 = 100;
    int x2 = 300;
    int y2 = 300;

    drawLine(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
