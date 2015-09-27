#include <gl/glut.h>
#include "Solido.h"

Solido *s = new Solido();
Solido *s2 = new Solido();

void DesenhaAviao(){

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    gluOrtho2D(-1000, 1000, -1000, 1000);

    s->posX = 0;
    s->posY = -500;
    s->desenha();
    s2->posX = 0;
    s2->posY = 500;
    s2->desenha();

    glFlush();
}

int main(int argc, char **argv) {
    char* titulo = "Animação";

    s->carrega("spitfire.txt");
    s2->carrega("bf109.txt");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("desenha");
    glutDisplayFunc(DesenhaAviao);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();

    return 0;
}