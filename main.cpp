#include<windows.h>
#include<iostream>
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
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);


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



    int x2=300;
    int y2=300;

    int x4=300;
    int y4=200;

    int x5=300;
    int y5=250;

    int x6=360;
    int y6=200;

    int x7=330;
    int y7=250;

    int x8=330;
    int y8=300;

    int xc=(x7+x8)/2;
    int yc=(y7+y8)/2;
    int radius=(y8-y7)/2;

    drawVerticalLine(x4,y4,y2);
    drawLine(x5,y5,x6,y6);
    drawLine(x5,y5,x7,y7);
    drawLine(x2,y2,x8,y8);
    drawCircle(xc,yc,radius);


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
    glutInitWindowSize(600, 600);
    glutCreateWindow("Right-Angled Triangle with Bresenham's Lines");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
