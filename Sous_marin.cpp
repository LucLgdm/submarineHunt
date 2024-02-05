/* ++++++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Sous_marin +++ */
/* ++++++++++++++++++++++++++++++++++++++++++ */

#include "Sous_marin.h"
#include "Util.h"
/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Sous_marin::Sous_marin(int echelle_x, int echelle_y) {
	int abs = tirage(echelle_x);
	int ord = tirage(echelle_y);
	for (int i = 0; i < 4; i++) {
		this->coque[i]->modifie_position_x(abs + i);
		this->coque[i]->modifie_position_y(ord);
	}
	this->position_cap = 3;
}

/* =================== */
/* === Destructeur === */
/* =================== */
Sous_marin::~Sous_marin() {
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Sous_marin::selfDisplay(std::ostream& stream) const {
	stream << "Sous marin \n";
	for(int i = 0; i<4; i++){
		stream << *(this->coque[i]) << "\n";
	}
}

/* =========================== */
/* === Fonction se_dessine === */
/* =========================== */
void Sous_marin::se_dessine(){
	for (int i = 0; i<4; i++) this->coque[i]->se_dessine();
}

/* =========================== */
/* === Fonction se_deplace === */
/* =========================== */
void Sous_marin::se_deplace(){
	int j = tirage(3);
	for (int i = 0; i<4; i++){
		if (j == 0) {
			this->coque[i]->modifie_position_x(this->coque[i]->position_x() + 1);
		}
		if (j == 1) {
			this->coque[i]->modifie_position_x(this->coque[i]->position_x() + 1);
			this->coque[i]->modifie_position_y(this->coque[i]->position_y() + 1);
		}
		if (j == 2) {
			this->coque[i]->modifie_position_x(this->coque[i]->position_x() + 1);
			this->coque[i]->modifie_position_y(this->coque[i]->position_y() - 1);
		}
	}
}

/* =================================== */
/* === Fonction demande_position_x === */
/* =================================== */
int Sous_marin::demande_position_x(){
	return this->coque[3]->position_x();
}

/* =================================== */
/* === Fonction demande_position_y === */
/* =================================== */
int Sous_marin::demande_position_y(){
	return this->coque[3]->position_y();
}

/* ============================ */
/* === Fonction cap_suivant === */
/* ============================ */
void Sous_marin::cap_suivant(){
	this->position_cap += 4;
}
/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
