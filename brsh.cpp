#include<windows.h>
#include<iostream>
#include <GL/glut.h>
#include <cmath>
void drawVerticalLine(int x, int y1, int y2) {
  // Calculate the error term.
  int error = 0;

  // Start at the bottom of the line.
  int y = y1;

  // Loop until we reach the top of the line.
  while (y <= y2) {
    // Draw the pixel at the current position.
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    // Increment the error term.
    error += 1;

    // If the error term is greater than or equal to half of the y-step,
    // increment the y-coordinate.
    if (error >= (y2 - y1) / 2) {
      y++;
      error -= (y2 - y1);
    }
  }
}


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

void drawRightAngleTriangle() {
    int x1 = 100;
    int y1 = 100;
    int x2 = 100;
    int y2 = 300;
    int x3 = 300;
    int y3 = 100;

    // Draw the three sides of the triangle
    drawVerticalLine(x1, y1, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glPointSize(2.0);

    drawRightAngleTriangle();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Right-Angled Triangle with Bresenham's Lines");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
