#include<windows.h>
#include <GL/glut.h>
#include<iostream>

void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_POINTS);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = std::max(abs(dx), abs(dy));

    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    for (int i = 0; i <= steps; i++) {
        glVertex2i(x1 + i * xIncrement, y1 + i * yIncrement);
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
    glutCreateWindow("DDA Line Drawing Algorithm (Simplified)");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
