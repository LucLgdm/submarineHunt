// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

// #include <windows.h>
#include <GL\glut.h>
#include <iostream>
#include <stdlib.h>

#include "Brique.h"
#include "Util.h"
#include "Mer.h"

/* ++++++++++++++++++++++++++ */
/* +++ Variables globales +++ */
/* ++++++++++++++++++++++++++ */
GLenum  errCodeOpenGL;              // Code erreur OpenGL
int     width;                      // Largeur de la fen�tre graphique
int     height;                     // Hauteur de la fen�tre graphique
int     mainWindow;                 // Id OpenGL de la fenetre generale de visualisation
int		echelle_x = 502;			// Attention, si on change l'echelle, il faut aussi changer la taille du cap dans Sous_marin.h !
int		echelle_y = 502;
Mer* mer;
void display2D();
void simule2D();
void keyboard2D(unsigned char, int, int);


/* +++++++++++++++++++++++++++ */
/* +++ Fonction principale +++ */
/* +++++++++++++++++++++++++++ */
int main(int argc, char** argv){

/* ===================================== */
/* === Param�tres de rendu graphique === */
/* ===================================== */
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    width = 600;
    height = 600;
    glutInitWindowSize(width,height);
    glutInitWindowPosition(1,1);
    mainWindow = glutCreateWindow("Trouvez le sous-marin !");
    glClearColor(0.0,0.0,1.0,1.0);
	mer = new Mer(echelle_x, echelle_y);
	glutDisplayFunc(display2D);
	glutKeyboardFunc(keyboard2D);
	glutIdleFunc(simule2D);
	glutMainLoop();
/* ======================== */
/* === Fin du programme === */
/* ======================== */
	  return 1;
}

/* ++++++++++++++++++++++++++ */
/* +++ Fonction display2D +++ */
/* ++++++++++++++++++++++++++ */
void display2D(){


/* ==================================== */
/* === Transformation de projection === */
/* ==================================== */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D((GLdouble)0.0,(GLdouble)double(echelle_x),(GLdouble)0.0,(GLdouble)double(echelle_y));
   
/* ==================================================== */
/* === Transformation de mod�lisation/visualisation === */
/* ==================================================== */
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

/* ====================================== */
/* === Activation des fonctionnalit�s === */
/* ====================================== */
      glEnable(GL_DEPTH_TEST);

/* =========================== */
/* === Rectangle de dessin === */
/* =========================== */
      glViewport(0,0,(GLsizei)width,(GLsizei)height);

/* -------------- */
/* --- Dessin --- */
/* -------------- */
		mer->se_dessine();
		if (mer->demande_etat() == 100){
			mer->demande_sous_marin()->se_dessine();
		}

/* ------------------------------------------- */
/* --- Il y a-t-il eu des erreurs OpenGL ? --- */
/* ------------------------------------------- */
            if ((errCodeOpenGL = glGetError()) != GL_NO_ERROR){
                  std::cerr << "ERROR: Probl�me lors du rendu visuel OpenGL : " << (char*)gluErrorString(errCodeOpenGL) << std::endl;
                  exit(0);
            }

/* ----------------------------------- */
/* --- R�clenchement du traitement --- */
/* ----------------------------------- */
            glFlush();
            glutSwapBuffers();

}

/* ++++++++++++++++++++++++++ */
/* +++ Fonction display2D +++ */
/* ++++++++++++++++++++++++++ */

void simule2D(){

/* ------------- */
/* --- Simul --- */
/* ------------- */
	mer->simulation();
	display2D();

}

/* +++++++++++++++++++++++++++ */
/* +++ Fonction keyboard2D +++ */
/* +++++++++++++++++++++++++++ */
void keyboard2D(unsigned char touche, int x, int y){
	glutSetWindow(mainWindow);
	switch (touche){

	case 'q' : 
		delete mer;
		exit(0);
		break;
	case 'a' : 
		mer->modifie_etat(Mer::PHASE_0);
		break;
	case 'z' : 
		mer->modifie_etat(Mer::PHASE_1);
		break;
	case 'e' : 
		mer->modifie_etat(Mer::PHASE_2);
		break;
	case 'r' : 
		mer->modifie_etat(Mer::PHASE_3);
		break;
	case 't' : 
		mer->modifie_etat(Mer::PHASE_4);
		break;
	case 'y' : 
		mer->modifie_etat(Mer::PHASE_5);
		break;


	}
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
