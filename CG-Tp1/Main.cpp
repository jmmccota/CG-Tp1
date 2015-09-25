//Ciclo principal do jogo (fase.terminou redireciona para ca
//    se a fase tiver acabado (chamada dentro de fase.atualiza))
//switch (faseAtual)
//{
//case 1:
//	fase1.glSetup();
//case 2:
//	fase2.glSetup();
//...
//default:
//	break;
//}

#ifdef _WIN32
#include <Windows.h>
#endif
#include <gl/GL.h>
#include <gl/glut.h>
#include "Solido.h"

void Desenha(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Solido *s = new Solido();
    s->carrega("spitfire.txt");
    s->posX = 0;
    s->posY = 0;
    s->desenha();

    glFlush();
}

int main(int argc, char **argv) {
    char* titulo = "Animação";
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