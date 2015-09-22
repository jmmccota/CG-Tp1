#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdarg>
#include "SplitString.h"
#include "Circulo.h"
#include <GL/glut.h>

using namespace std;
Ponto** pts;
Ponto** carregar(string filename) {
	string line;
	ifstream poligon(filename);
	Ponto **pontos = NULL;
	if (poligon.is_open()) {
		while (poligon.good()) {

			getline(poligon, line);
			//cout << line << endl;
			SplitString ss(line);
			vector<string> flds = ss.split(' ', 1);
			if (flds.size() > 0) {
				if (flds[0] == "C" || flds[0] == "c") {
					float corR, corG, corB;
					corR = atof(flds[1].c_str());
					corG = atof(flds[2].c_str());
					corB = atof(flds[3].c_str());

					getline(poligon, line);
					SplitString ss(line);
					vector<string> flds = ss.split(' ', 0);
					float centroX, centroY, raio;
					centroX = atof(flds[0].c_str());
					centroY = atof(flds[1].c_str());
					raio = atof(flds[2].c_str());
					Circulo c(centroX, centroY, raio);
					cout << c << endl;
					//cout << "Circulo" << centroX << centroY << raio << endl;
				}
				else if (flds[0] != " ")
				{
					int repeticao = atoi(flds[0].c_str());
					float corR, corG, corB;
					corR = atof(flds[1].c_str());
					corG = atof(flds[2].c_str());
					corB = atof(flds[3].c_str());
					pontos = new Ponto*[repeticao];
					for (int i = 0; i < repeticao; i++) {
						getline(poligon, line);
						SplitString ss(line);
						vector<string> flds = ss.split(' ', 1);
						pontos[i] = new Ponto(atoi(flds[0].c_str()), atoi(flds[1].c_str()));
						cout << *pontos[i] << endl;
					}
				}
			}
		}
	}
	//cout << "terminou?" << endl;
	
	poligon.close();
	return pontos;
	//delete &line;
	//delete writable;
	//delete &poligon;
	//delete sVet;
}

//int main(int argc, char **argv) {
//	//carregar("C:/Users/JMMCC/Documents/Visual Studio 2015/Projects/CG-Tp1/CG-Tp1/splitfire.txt"); //Colocar o caminho do arquivo, ou por ele dentro da pasta bin ou por ele nos resources
//	carregar("splitfire.txt");
//	cin.get();
//}


void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(1.0f, 0.0f, 0.0f);
	gluOrtho2D(-10000, 10000, -10000, 10000);
	glBegin(GL_POLYGON);
	{
		for (int i = 0; i < 4; i++){
			glVertex2i(pts[i]->getX(), pts[i]->getY());
		}
		for (int i = 0; i < 4; i++){
			glVertex2i(-pts[i]->getX(), pts[i]->getY());
		}
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
			for (int i = 4; i < 12; i++){
				glVertex2i(pts[i]->getX(), pts[i]->getY());
			}
			for (int i = 4; i < 12; i++){
				glVertex2i(-pts[i]->getX(), pts[i]->getY());
			}
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		for (int i = 12; i < 19; i++){
			glVertex2i(pts[i]->getX(), pts[i]->getY());
		}
		for (int i = 12; i < 19; i++){
			glVertex2i(-pts[i]->getX(), pts[i]->getY());
		}
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		for (int i = 19; i < 33; i++){
			glVertex2i(pts[i]->getX(), pts[i]->getY());
		}
		for (int i = 19; i < 33; i++){
			glVertex2i(-pts[i]->getX(), pts[i]->getY());
		}
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		for (int i = 33; i < 44; i++){
			glVertex2i(pts[i]->getX(), pts[i]->getY());
		}
		for (int i = 33; i < 44; i++){
			glVertex2i(-pts[i]->getX(), pts[i]->getY());
		}
	}
	glEnd();
	glFlush();
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {

	if (h == 0) h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}
	else {
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}

}

void Inicializa(void) {  
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
int main(int argc, char **argv) {
	char* titulo = "Splitfire";
	pts = carregar("splitfire.txt");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow(titulo);
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	glutMainLoop();

	return 0;
}