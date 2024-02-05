/* +++++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Direction +++ */
/* +++++++++++++++++++++++++++++++++++++++++ */

#include "Direction.h"
#include "Util.h"

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
	Direction::Direction(int echelle_x, int echelle_y) {
		int abs = tirage(echelle_x);
		int ord = tirage(echelle_y);
		this->Chemin[0] = new Brique(abs, ord, 0.0, 0.0, 0.0);
		for (int i = 0; i < echelle_x; i++) {
			if (i % 4 == 0) {
				int j = tirage(3);
				if (j == 0) {
					this->Chemin[i - 3] = new Brique(i - 3, this->Chemin[i - 4]->position_y() - 1, 0.0, 0.0, 0.0);
					this->Chemin[i - 2] = new Brique(i - 2, this->Chemin[i - 4]->position_y() - 1, 0.0, 0.0, 0.0);
					this->Chemin[i - 1] = new Brique(i - 1, this->Chemin[i - 4]->position_y() - 1, 0.0, 0.0, 0.0);
					this->Chemin[i] = new Brique(i , this->Chemin[i - 4]->position_y() - 1, 0.0, 0.0, 0.0);
				}
				if (j == 1) {
					this->Chemin[i - 3] = new Brique(i - 3, this->Chemin[i - 4]->position_y(), 0.0, 0.0, 0.0);
					this->Chemin[i - 2] = new Brique(i - 2, this->Chemin[i - 4]->position_y(), 0.0, 0.0, 0.0);
					this->Chemin[i - 1] = new Brique(i - 1, this->Chemin[i - 4]->position_y(), 0.0, 0.0, 0.0);
					this->Chemin[i] = new Brique(i, this->Chemin[i - 4]->position_y(), 0.0, 0.0, 0.0);
				}
				if (j == 2) {
					this->Chemin[i - 3] = new Brique(i - 3, this->Chemin[i - 4]->position_y() + 1, 0.0, 0.0, 0.0);
					this->Chemin[i - 2] = new Brique(i - 2, this->Chemin[i - 4]->position_y() + 1, 0.0, 0.0, 0.0);
					this->Chemin[i - 1] = new Brique(i - 1, this->Chemin[i - 4]->position_y() + 1, 0.0, 0.0, 0.0);
					this->Chemin[i] = new Brique(i, this->Chemin[i - 4]->position_y() + 1, 0.0, 0.0, 0.0);
				}
			}
		}
	}


	/* =================== */
	/* === Destructeur === */
	/* =================== */
	Direction::~Direction() {
	}

	/////////////////////////////////////////////////////////////////////////////
	///                    Méthodes publiques d'interfaces                    ///
	/////////////////////////////////////////////////////////////////////////////

	/* ============================ */
	/* === Fonction selfDisplay === */
	/* ============================ */
	void Direction::selfDisplay(std::ostream& stream) const {
		stream << "Direction !! \n";
		for (int i = 0; i < sizeof(this->Chemin); i++) {
			stream << *(this->Chemin[i]) << "\n";
		}
	}

	/* =============================== */
	/* === Fonction demande_chemin === */
	/* =============================== */
	Brique* Direction::demande_chemin(int nbre){
		return this->Chemin[nbre];
	}

	/////////////////////////////////////////////////////////////////////////////
	///                       Méthodes privées internes                       ///
	/////////////////////////////////////////////////////////////////////////////
