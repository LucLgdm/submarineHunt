/* +++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Bouee +++ */
/* +++++++++++++++++++++++++++++++++++ */

#include "Bouee.h"


/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Bouee::Bouee(int x, int y){
	this->bouee = new Brique( x, y, 1.0, 1.0, 0.0 );
	this->rayon_action = 30;
}

/* =================== */
/* === Destructeur === */
/* =================== */
Bouee::~Bouee() {
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Bouee::selfDisplay(std::ostream& stream) const {
	stream << "Bouee \n";
	stream << "position (x,y) = " << this->bouee->position_x() << ", " << this->bouee->position_y() << "\n";
}

/* =========================== */
/* === Fonction se_dessine === */
/* =========================== */
void Bouee::se_dessine(){
	this->bouee->se_dessine();
}

/* =============================== */
/* === Fonction demande_brique === */
/* =============================== */
Brique* Bouee::demande_brique(){
	return this->bouee;
}

/* ============================== */
/* === Fonction demande_rayon === */
/* ============================== */
int Bouee::demande_rayon(){
	return this->rayon_action;
}

/* =============================== */
/* === Fonction change_couleur === */
/* =============================== */
void Bouee::change_couleur(double r, double v, double b){
	this->bouee->modifie_couleur(r, v, b);
}
/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
