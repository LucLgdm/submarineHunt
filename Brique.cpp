/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Brique +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#include "Brique.h"

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Brique::Brique(int x, int y, double r, double v, double b) {
	this->x = x;
	this->y = y;
	this->taille = 5;
	this->rouge = r;
	this->vert = v;
	this->bleu = b;
}

/* =================== */
/* === Destructeur === */
/* =================== */
Brique::~Brique() {
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Brique::selfDisplay(std::ostream& stream) const {
	stream << "Brique \n";
	stream << "position (x,y) = " << this->x << ", " << this->y << "\n";
}

/* ============================ */
/* === Fonction position_x  === */
/* ============================ */
int Brique::position_x() {
	return this->x;
}

/* ============================ */
/* === Fonction position_x  === */
/* ============================ */
int Brique::position_y() {
	return this->y;
}

/* ==================================== */
/* === Fonction modifie_position_x  === */
/* ==================================== */
void Brique::modifie_position_x(int x_nouveau){
	this->x = x_nouveau;
}

/* ==================================== */
/* === Fonction modifie_position_y  === */
/* ==================================== */
void Brique::modifie_position_y(int y_nouveau){
	this->y = y_nouveau;
}

/* ================================= */
/* === Fonction modifie_couleur  === */
/* ================================= */
void Brique::modifie_couleur(double r, double v, double b){
	this->rouge = r;
	this->vert  = v;
	this->bleu  = b;
}

/* ============================ */
/* === Fonction se_dessine  === */
/* ============================ */
void Brique::se_dessine(){
	glBegin(GL_QUADS);
   	glColor3d(this->rouge, this->vert, this->bleu); 
      glVertex2d( this->x                , this->y                      );
      glVertex2d( this->x + 2*this->taille , this->y                );
      glVertex2d( this->x + 2*this->taille , this->y + this->taille );
      glVertex2d( this->x                , this->y + this->taille       );
   glEnd();
}

/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
