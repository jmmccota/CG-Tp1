#include <gl/glut.h>
#include "Solido.h"

Solido *s = new Solido();

void Desenha(){

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    gluOrtho2D(-1000, 1000, -1000, 1000);

    
    s->posX = 0;
    s->posY = 0;
    s->desenha();

    glFlush();
}

int main(int argc, char **argv) {
    char* titulo = "Animação";

	s->carrega("bf109.txt");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("desenha");
    glutDisplayFunc(Desenha);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();

    return 0;
}