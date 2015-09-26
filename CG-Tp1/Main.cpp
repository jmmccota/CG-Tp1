#include <gl/glut.h>
#include "Solido.h"

Solido *s = new Solido();

void Desenha(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    s->posX = 0;
    s->posY = 0;
    s->desenha();

    glFlush();
}

int main(int argc, char **argv) {
    char* titulo = "Animação";

	s->carrega("spitfire.txt");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutCreateWindow(titulo);
    glutDisplayFunc(Desenha);
    gluOrtho2D(-500, 500, -500, 500);
    glutMainLoop();
}