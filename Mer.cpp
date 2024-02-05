/* +++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Mer +++ */
/* +++++++++++++++++++++++++++++++++++ */

#include "Mer.h"
//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

const int Mer::PHASE_0 = 0;
const int Mer::PHASE_1 = 1;
const int Mer::PHASE_2 = 2;
const int Mer::PHASE_3 = 3;
const int Mer::PHASE_4 = 4;
const int Mer::PHASE_5 = 5;

const int Mer::MAJ_MER   = 6;
const int Mer::MAJ_MER_2 = 7;
const int Mer::MAJ_MER_3 = 8;
const int Mer::MAJ_MER_4 = 9;
const int Mer::MAJ_MER_5 = 10;
const int Mer::MAJ_MER_6 = 11;
const int Mer::MAJ_MER_7 = 12;
const int Mer::TROUVE    = 15;

/* ==================== */
/* === Constructeur === */
/* ==================== */
Mer::Mer(int echelle_x, int echelle_y){
	for(int i = 0; i<16; i++){
		this->filet1[i] = new Bouee(0,0);
	}
	for(int i = 0; i<16; i++){
		this->filet2[i] = new Bouee(0,0);
	}
	for(int i = 0; i<9; i++){
		this->filet3[i] = new Bouee(0,0);
	}
	for(int i = 0; i<9; i++){
		this->filet4[i] = new Bouee(0,0);
	}
	for(int i = 0; i<9; i++){
		this->filet5[i] = new Bouee(0,0);
	}
	for(int i = 0; i<9; i++){
		this->filet6[i] = new Bouee(0,0);
	}

	this->nautilus = new Sous_marin(echelle_x, echelle_y);
	this->vitesse_deplacement = 1000;

	this->etat = Mer::MAJ_MER;

}

/* =================== */
/* === Destructeur === */
/* =================== */
Mer::~Mer(){

	for(int i = 0; i<16; i++){
		delete this->filet1[i];
		delete this->filet2[i];
	}
	for(int i = 0; i<9; i++){
		delete this->filet3[i];
		delete this->filet4[i];
	}
	for(int i = 0; i<10; i++){
		delete this->filet5[i];
		delete this->filet6[i];
	}
	delete this->nautilus;
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Mer::selfDisplay(std::ostream& stream) const {
   stream << "Dans la mer il y a : \n";
   stream << "un " << *(this->nautilus) << "\n";
   stream << "Filet 1 \n"; 
   for (int i = 0; i<16; i++){
	   if(this->filet1[i] != NULL){
		   stream << *(this->filet1[i]);
	   }
   }
   stream << "Filet 2 \n";
   for (int i = 0; i<16; i++){
	   if(this->filet2[i] != NULL){
		   stream << *(this->filet1[i]);
	   }
   }
   stream << "Filet 3 \n";
   for (int i = 0; i<9; i++){
	   if(this->filet3[i] != NULL){
		   stream << *(this->filet1[i]);
	   }
   }
   stream << "Filet 4 \n";
   for (int i = 0; i<9; i++){
	   if(this->filet4[i] != NULL){
		   stream << *(this->filet1[i]);
	   }
   }
   stream << "Filet 5 \n";
   for (int i = 0; i<10; i++){
	   if(this->filet5[i] != NULL){
		   stream << *(this->filet1[i]);
	   }
   }
   stream << "Filet 6 \n";
   for (int i = 0; i<10; i++){
	   if(this->filet6[i] != NULL){
		   stream << *(this->filet1[i]);
	   }
   }
}

/* =========================== */
/* === Fonction se_dessine === */
/* =========================== */

void Mer::se_dessine(){
/* ----------- */
/* --- RAZ --- */
/* ----------- */
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

/* ----------------------------------- */
/* --- Dessin du liseret de la mer --- */
/* ----------------------------------- */
	glBegin(GL_LINE_LOOP);
	glColor3d ( 1.0, 1.0, 1.0 ); 
   	glVertex2d( 0.8   , 0.8   );
    glVertex2d( 501.2 , 0.8   );
    glVertex2d( 501.2 , 501.2 );
    glVertex2d( 0.8   , 501.2 );
	glEnd();

/* ------------------------- */
/* --- Dessin des bouees --- */
/* ------------------------- */
	for(int i = 0; i<16; i++) this->filet1[i]->se_dessine();
	for(int i = 0; i<16; i++) this->filet2[i]->se_dessine();
	for(int i = 0; i<9 ; i++) this->filet3[i]->se_dessine();
	for(int i = 0; i<9 ; i++) this->filet4[i]->se_dessine();
	for(int i = 0; i<9 ; i++) this->filet5[i]->se_dessine();
	for(int i = 0; i<9 ; i++) this->filet6[i]->se_dessine();

	this->nautilus->se_dessine();
}

/* ============================= */
/* === Fonction demande_etat === */
/* ============================= */
int Mer::demande_etat(){
	return this->etat;
}

/* ============================= */
/* === Fonction demande_etat === */
/* ============================= */
void Mer::modifie_etat(int nouveau){
	this->etat = nouveau;
}

/* ========================= */
/* === Fonction distance === */
/* ========================= */
double Mer::distance(Sous_marin* nautilus, Bouee* bouee){
	// renvoie la distance entre un sous-marin et une bouee //
		double d;
		double a;
		double b;
		a = nautilus->demande_position_x() - bouee->demande_brique()->position_x();
		b = nautilus->demande_position_y() - bouee->demande_brique()->position_y();
		d = sqrt( a*a + b*b);
		return d;
}

/* =================================== */
/* === Fonction demande_sous_marin === */
/* =================================== */
Sous_marin* Mer::demande_sous_marin(){
	return this->nautilus;
}

/* =========================== */
/* === Fonction simulation === */
/* =========================== */
void Mer::simulation(){
	switch(this->etat){

/* -------------------- */
/* --- Etat PHASE_0 --- */
/* -------------------- */

	case Mer::PHASE_0:

/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		std::cout << "Larguage du filet 1 : 16 bouees \n";
		std::cout << "Quelle forme voulez-vous utilisez pour le premier larguage de bouees ? \n";
		std::cout << "ligne : 1, carre : 2  \n";
		int type;
		std::cin >> type;

		switch(type){
			/* ----------------- */
			/* --- Cas ligne --- */
			/* ----------------- */
		case 1:
			// On rentre les coordonnées de la première et dernière bouee //
			std::cout << "Vous allez choisir les 2 bouees aux extrémites de la ligne. \n";
			std::cout << "Choisissez la position de la première : \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_1_debut;
			std::cin >> xnew_ligne_1_debut;
			this->filet1[0]->demande_brique()->modifie_position_x(xnew_ligne_1_debut); 

			std::cout << "ordonnee ? \n";
			int ynew_ligne_1_debut;
			std::cin >> ynew_ligne_1_debut;
			this->filet1[0]->demande_brique()->modifie_position_y(ynew_ligne_1_debut);

			std::cout << "Choisissez la position de la derniere \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_1_fin;
			std::cin >> xnew_ligne_1_fin;
			this->filet1[15]->demande_brique()->modifie_position_x(xnew_ligne_1_fin);
			
			std::cout << "ordonnee ? \n";
			int ynew_ligne_1_fin;
			std::cin >> ynew_ligne_1_fin;
			this->filet1[15]->demande_brique()->modifie_position_y(ynew_ligne_1_fin);

			// On modifie les coordonnees des autres bouees du filet //

			int ecart_x;
			ecart_x = int(( this->filet1[15]->demande_brique()->position_x() - this->filet1[0]->demande_brique()->position_x() )/16) ;
			for(int i = 1; i<15; i++){
				this->filet1[i]->demande_brique()->modifie_position_x( this->filet1[i-1]->demande_brique()->position_x() + ecart_x );
			}

			int ecart_y;
			ecart_y = int(( this->filet1[15]->demande_brique()->position_y() - this->filet1[0]->demande_brique()->position_y() )/16) ;
			for(int i = 1; i<15; i++){
				this->filet1[i]->demande_brique()->modifie_position_y( this->filet1[i-1]->demande_brique()->position_y() + ecart_y );
			}
			this->etat = Mer::MAJ_MER;
//			this->etat_ancien = Mer::MAJ_MER_2;
			break;

			/* ----------------- */
			/* --- Cas carre --- */
			/* ----------------- */
		case 2: 
			// On choisit 2 bouees aux coins du carre //

			std::cout << "Vous allez choisir 2 bouees correspondants à deux coins opposes du carre. \n";
			std::cout << "Choisissez la position de la premiere : \n";
			
			std::cout << "abscisse ? \n";
			int xnew_carre_1_debut;
			std::cin >> xnew_carre_1_debut;
			this->filet1[0]->demande_brique()->modifie_position_x(xnew_carre_1_debut);

			std::cout << "ordonnee ? \n";
			int ynew_carre_1_debut;
			std::cin >> ynew_carre_1_debut;
			this->filet1[0]->demande_brique()->modifie_position_y(ynew_carre_1_debut);

			std::cout << "Choisissez l'écart en abscisse entre deux bouees \n";
			int ecart_x_carre_1;
			std::cin >> ecart_x_carre_1;

			std::cout << "Choisissez l'ecart en ordonnee entre deux bouees \n";
			int ecart_y_carre_1;
			std::cin >> ecart_y_carre_1;

			// On modifie les coordonnees des autres bouees du filet //

			for(int i = 0; i<4; i++){
				if(i == 0){
					for(int j = 1; j<4; j++){
						this->filet1[4*i + j]->demande_brique()->modifie_position_x(this->filet1[4*i]->demande_brique()->position_x());
						this->filet1[4*i + j]->demande_brique()->modifie_position_y(this->filet1[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_1);
					}

				}else{
					this->filet1[4*i]->demande_brique()->modifie_position_x(this->filet1[4*(i-1)]->demande_brique()->position_x() + ecart_x_carre_1);
					this->filet1[4*i]->demande_brique()->modifie_position_y(this->filet1[4*(i-1)]->demande_brique()->position_y());
					for(int j = 1; j<4; j++){
						this->filet1[4*i + j]->demande_brique()->modifie_position_x(this->filet1[4*i]->demande_brique()->position_x());
						this->filet1[4*i + j]->demande_brique()->modifie_position_y(this->filet1[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_1);
					}
				}
			}

			this->etat = Mer::MAJ_MER;
			break;
		}
		break;

	case Mer::PHASE_1:

/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		std::cout << "Larguage du filet 2 : 16 bouees \n";
		std::cout << "Quelle forme voulez-vous utilisez pour le deuxieme larguage de bouees ? \n";
		std::cout << "ligne : 1, carre : 2  \n";
		int type_2;
		std::cin >> type_2;

		switch(type_2){
			/* ----------------- */
			/* --- Cas ligne --- */
			/* ----------------- */
		case 1:

			// On rentre les coordonnées de la première et dernière bouee //
			std::cout << "Vous allez choisir les 2 bouees aux extremites de la ligne. \n";
			std::cout << "Choisissez la position de la premiere : \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_2_debut;
			std::cin >> xnew_ligne_2_debut;
			this->filet2[0]->demande_brique()->modifie_position_x(xnew_ligne_2_debut);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_2_debut;
			std::cin >> ynew_ligne_2_debut;
			this->filet2[0]->demande_brique()->modifie_position_y(ynew_ligne_2_debut);

			std::cout << "Choisissez la position de la derniere \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_2_fin;
			std::cin >> xnew_ligne_2_fin;
			this->filet2[15]->demande_brique()->modifie_position_x(xnew_ligne_2_fin);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_2_fin;
			std::cin >> ynew_ligne_2_fin;
			this->filet2[15]->demande_brique()->modifie_position_y(ynew_ligne_2_fin);

			// On modifie les coordonnees des autres bouees du filet //

			int ecart_x;
			ecart_x = int(( this->filet2[15]->demande_brique()->position_x() - this->filet2[0]->demande_brique()->position_x() )/16) ;
			std::cout << "ecart x = " << ecart_x << "\n";
			for(int i = 1; i<15; i++){
				this->filet2[i]->demande_brique()->modifie_position_x( this->filet2[i-1]->demande_brique()->position_x() + ecart_x );
			}

			int ecart_y;
			ecart_y = int(( this->filet2[15]->demande_brique()->position_y() - this->filet2[0]->demande_brique()->position_y() )/16) ;
			std::cout << "ecart y = " << ecart_y << "\n";
			for(int i = 1; i<15; i++){
				this->filet2[i]->demande_brique()->modifie_position_y( this->filet2[i-1]->demande_brique()->position_y() + ecart_y );
			}
			this->etat = Mer::MAJ_MER;
			break;

			/* ----------------- */
			/* --- Cas carre --- */
			/* ----------------- */
		case 2: 
			// On choisit 2 bouees aux coins du carre //

			std::cout << "Vous allez choisir 2 bouées correspondants à deux coins opposés du carré. \n";
			std::cout << "Choisissez la position de la première : \n";
			std::cout << "abscisse ? \n";
			int xnew_carre_2_debut;
			std::cin >> xnew_carre_2_debut;
			this->filet2[0]->demande_brique()->modifie_position_x(xnew_carre_2_debut);

			std::cout << "ordonnee ? \n";
			int ynew_carre_2_debut;
			std::cin >> ynew_carre_2_debut;
			this->filet2[0]->demande_brique()->modifie_position_y(ynew_carre_2_debut);

			std::cout << "Choisissez l'ecart en abscisse entre deux bouees \n";
			int ecart_x_carre_2;
			std::cin >> ecart_x_carre_2;

			std::cout << "Choisissez l'ecart en ordonnée entre deux bouees \n";
			int ecart_y_carre_2;
			std::cin >> ecart_y_carre_2;

			// On modifie les coordonnees des autres bouees du filet //

			for(int i = 0; i<4; i++){
				if(i == 0){
					for(int j = 1; j<4; j++){
						this->filet2[4*i + j]->demande_brique()->modifie_position_x(this->filet2[4*i]->demande_brique()->position_x());
						this->filet2[4*i + j]->demande_brique()->modifie_position_y(this->filet2[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_2);
					}

				}else{
					this->filet2[4*i]->demande_brique()->modifie_position_x(this->filet2[4*(i-1)]->demande_brique()->position_x() + ecart_x_carre_2);
					this->filet2[4*i]->demande_brique()->modifie_position_y(this->filet2[4*(i-1)]->demande_brique()->position_y());
					for(int j = 1; j<4; j++){
						this->filet2[4*i + j]->demande_brique()->modifie_position_x(this->filet2[4*i]->demande_brique()->position_x());
						this->filet2[4*i + j]->demande_brique()->modifie_position_y(this->filet2[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_2);
					}
				}
			}
			this->etat = Mer::MAJ_MER;
			break;
		}
		break;

	case Mer::PHASE_2:

/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		std::cout << "Larguage du filet 3 : 9 bouees \n";
		std::cout << "Quelle forme voulez-vous utilisez pour le deuxieme larguage de bouees ? \n";
		std::cout << "ligne : 1, carre : 2  \n";
		int type_3;
		std::cin >> type_3;

		switch(type_3){
			/* ----------------- */
			/* --- Cas ligne --- */
			/* ----------------- */
		case 1:

			// On rentre les coordonnées de la première et dernière bouee //
			std::cout << "Vous allez choisir les 2 bouées aux extrémités de la ligne. \n";
			std::cout << "Choisissez la position de la première : \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_3_debut;
			std::cin >> xnew_ligne_3_debut;
			this->filet3[0]->demande_brique()->modifie_position_x(xnew_ligne_3_debut);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_3_debut;
			std::cin >> ynew_ligne_3_debut;
			this->filet3[0]->demande_brique()->modifie_position_y(ynew_ligne_3_debut);

			std::cout << "Choisissez la position de la derniere \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_3_fin;
			std::cin >> xnew_ligne_3_fin;
			this->filet3[8]->demande_brique()->modifie_position_x(xnew_ligne_3_fin);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_3_fin;
			std::cin >> ynew_ligne_3_fin;
			this->filet3[8]->demande_brique()->modifie_position_y(ynew_ligne_3_fin);

			// On modifie les coordonnees des autres bouees du filet //

			int ecart_x;
			ecart_x = int(( this->filet3[8]->demande_brique()->position_x() - this->filet3[0]->demande_brique()->position_x() )/9) ;
			std::cout << "ecart x = " << ecart_x << "\n";
			for(int i = 1; i<8; i++){
				this->filet3[i]->demande_brique()->modifie_position_x( this->filet3[i-1]->demande_brique()->position_x() + ecart_x );
			}

			int ecart_y;
			ecart_y = int(( this->filet3[8]->demande_brique()->position_y() - this->filet3[0]->demande_brique()->position_y() )/9) ;
			std::cout << "ecart y = " << ecart_y << "\n";
			for(int i = 1; i<8; i++){
				this->filet3[i]->demande_brique()->modifie_position_y( this->filet3[i-1]->demande_brique()->position_y() + ecart_y );
			}
			this->etat = Mer::MAJ_MER;
			break;

			/* ----------------- */
			/* --- Cas carre --- */
			/* ----------------- */
		case 2: 
			// On choisit 2 bouees aux coins du carre //

			std::cout << "Vous allez choisir 2 bouees correspondants à deux coins opposes du carre. \n";
			std::cout << "Choisissez la position de la premiere : \n";
			std::cout << "abscisse ? \n";
			int xnew_carre_3_debut;
			std::cin >> xnew_carre_3_debut;
			this->filet3[0]->demande_brique()->modifie_position_x(xnew_carre_3_debut);

			std::cout << "ordonnee ? \n";
			int ynew_carre_3_debut;
			std::cin >> ynew_carre_3_debut;
			this->filet3[0]->demande_brique()->modifie_position_y(ynew_carre_3_debut);

			std::cout << "Choisissez l'ecart en abscisse entre deux bouees \n";
			int ecart_x_carre_3;
			std::cin >> ecart_x_carre_3;

			std::cout << "Choisissez l'ecart en ordonnee entre deux bouees \n";
			int ecart_y_carre_3;
			std::cin >> ecart_y_carre_3;

			// On modifie les coordonnees des autres bouees du filet //

			for(int i = 0; i<4; i++){
				if(i == 0){
					for(int j = 1; j<4; j++){
						this->filet3[4*i + j]->demande_brique()->modifie_position_x(this->filet3[4*i]->demande_brique()->position_x());
						this->filet3[4*i + j]->demande_brique()->modifie_position_y(this->filet3[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_3);
					}

				}else{
					this->filet3[4*i]->demande_brique()->modifie_position_x(this->filet3[4*(i-1)]->demande_brique()->position_x() + ecart_x_carre_3);
					this->filet3[4*i]->demande_brique()->modifie_position_y(this->filet3[4*(i-1)]->demande_brique()->position_y());
					for(int j = 1; j<4; j++){
						this->filet3[4*i + j]->demande_brique()->modifie_position_x(this->filet3[4*i]->demande_brique()->position_x());
						this->filet3[4*i + j]->demande_brique()->modifie_position_y(this->filet3[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_3);
					}
				}
			}
			this->etat = Mer::MAJ_MER;
			break;
		}
		break;

	case Mer::PHASE_3:

/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		std::cout << "Larguage du filet 4 : 9 bouees \n";
		std::cout << "Quelle forme voulez-vous utilisez pour le deuxieme larguage de bouees ? \n";
		std::cout << "ligne : 1, carre : 2  \n";
		int type_4;
		std::cin >> type_4;

		switch(type_4){
			/* ----------------- */
			/* --- Cas ligne --- */
			/* ----------------- */
		case 1:

			// On rentre les coordonnées de la première et dernière bouee //
			std::cout << "Vous allez choisir les 2 bouees aux extrémites de la ligne. \n";
			std::cout << "Choisissez la position de la premiere : \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_4_debut;
			std::cin >> xnew_ligne_4_debut;
			this->filet4[0]->demande_brique()->modifie_position_x(xnew_ligne_4_debut);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_4_debut;
			std::cin >> ynew_ligne_4_debut;
			this->filet4[0]->demande_brique()->modifie_position_y(ynew_ligne_4_debut);

			std::cout << "Choisissez la position de la derniere \n";
			std::cout << "abscisse ? \n";
			int xnew_ligne_4_fin;
			std::cin >> xnew_ligne_4_fin;
			this->filet4[8]->demande_brique()->modifie_position_x(xnew_ligne_4_fin);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_4_fin;
			std::cin >> ynew_ligne_4_fin;
			this->filet4[8]->demande_brique()->modifie_position_y(ynew_ligne_4_fin);

			// On modifie les coordonnees des autres bouees du filet //

			int ecart_x;
			ecart_x = int(( this->filet4[8]->demande_brique()->position_x() - this->filet1[0]->demande_brique()->position_x() )/9) ;
			std::cout << "ecart x = " << ecart_x << "\n";
			for(int i = 1; i<8; i++){
				this->filet4[i]->demande_brique()->modifie_position_x( this->filet4[i-1]->demande_brique()->position_x() + ecart_x );
			}

			int ecart_y;
			ecart_y = int(( this->filet4[8]->demande_brique()->position_y() - this->filet4[0]->demande_brique()->position_y() )/9) ;
			std::cout << "ecart y = " << ecart_y << "\n";
			for(int i = 1; i<8; i++){
				this->filet4[i]->demande_brique()->modifie_position_y( this->filet4[i-1]->demande_brique()->position_y() + ecart_y );
			}
			this->etat = Mer::MAJ_MER;
			break;

			/* ----------------- */
			/* --- Cas carre --- */
			/* ----------------- */
		case 2: 
			// On choisit 2 bouees aux coins du carre //

			std::cout << "Vous allez choisir 2 bouees correspondants a deux coins opposes du carre. \n";
			std::cout << "Choisissez la position de la premiere : \n";
			std::cout << "abscisse ? \n";
			int xnew_carre_4_debut;
			std::cin >> xnew_carre_4_debut;
			this->filet4[0]->demande_brique()->modifie_position_x(xnew_carre_4_debut);

			std::cout << "ordonnee ? \n";
			int ynew_carre_4_debut;
			std::cin >> ynew_carre_4_debut;
			this->filet4[0]->demande_brique()->modifie_position_y(ynew_carre_4_debut);

			std::cout << "Choisissez l'ecart en abscisse entre deux bouees \n";
			int ecart_x_carre_4;
			std::cin >> ecart_x_carre_4;

			std::cout << "Choisissez l'ecart en ordonnee entre deux bouees \n";
			int ecart_y_carre_4;
			std::cin >> ecart_y_carre_4;

			// On modifie les coordonnees des autres bouees du filet //

			for(int i = 0; i<4; i++){
				if(i == 0){
					for(int j = 1; j<4; j++){
						this->filet4[4*i + j]->demande_brique()->modifie_position_x(this->filet4[4*i]->demande_brique()->position_x());
						this->filet4[4*i + j]->demande_brique()->modifie_position_y(this->filet4[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_4);
					}

				}else{
					this->filet4[4*i]->demande_brique()->modifie_position_x(this->filet4[4*(i-1)]->demande_brique()->position_x() + ecart_x_carre_4);
					this->filet4[4*i]->demande_brique()->modifie_position_y(this->filet4[4*(i-1)]->demande_brique()->position_y());
					for(int j = 1; j<4; j++){
						this->filet4[4*i + j]->demande_brique()->modifie_position_x(this->filet4[4*i]->demande_brique()->position_x());
						this->filet4[4*i + j]->demande_brique()->modifie_position_y(this->filet4[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_4);
					}
				}
			}
			this->etat = Mer::MAJ_MER;
			break;
		}

		break;

	case Mer::PHASE_4:

/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		std::cout << "Larguage du filet 5 : 9 bouees \n";
		std::cout << "Quelle forme voulez-vous utilisez pour le deuxieme larguage de bouees ? \n";
		std::cout << "ligne : 1, carre : 2  \n";
		int type_5;
		std::cin >> type_5;

		switch(type_5){
			/* ----------------- */
			/* --- Cas ligne --- */
			/* ----------------- */
		case 1:

			// On rentre les coordonnées de la première et dernière bouee //
			std::cout << "Vous allez choisir les 2 bouees aux extremites de la ligne. \n";
			std::cout << "Choisissez la position de la premiere : \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_5_debut;
			std::cin >> xnew_ligne_5_debut;
			this->filet5[0]->demande_brique()->modifie_position_x(xnew_ligne_5_debut);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_5_debut;
			std::cin >> ynew_ligne_5_debut;
			this->filet5[0]->demande_brique()->modifie_position_y(ynew_ligne_5_debut);

			std::cout << "Choisissez la position de la derniere \n";
			std::cout << "abscisse ? \n";
			int xnew_ligne_5_fin;
			std::cin >> xnew_ligne_5_fin;
			this->filet5[8]->demande_brique()->modifie_position_x(xnew_ligne_5_fin);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_5_fin;
			std::cin >> ynew_ligne_5_fin;
			this->filet5[8]->demande_brique()->modifie_position_y(ynew_ligne_5_fin);

			// On modifie les coordonnees des autres bouees du filet //

			int ecart_x;
			ecart_x = int(( this->filet5[8]->demande_brique()->position_x() - this->filet5[0]->demande_brique()->position_x() )/9) ;
			std::cout << "ecart x = " << ecart_x << "\n";
			for(int i = 1; i<8; i++){
				this->filet5[i]->demande_brique()->modifie_position_x( this->filet5[i-1]->demande_brique()->position_x() + ecart_x );
			}

			int ecart_y;
			ecart_y = int(( this->filet5[8]->demande_brique()->position_y() - this->filet5[0]->demande_brique()->position_y() )/9) ;
			std::cout << "ecart y = " << ecart_y << "\n";
			for(int i = 1; i<8; i++){
				this->filet5[i]->demande_brique()->modifie_position_y( this->filet5[i-1]->demande_brique()->position_y() + ecart_y );
			}
			this->etat = Mer::MAJ_MER;
			break;

			/* ----------------- */
			/* --- Cas carre --- */
			/* ----------------- */
		case 2: 
			// On choisit 2 bouees aux coins du carre //

			std::cout << "Vous allez choisir 2 bouees correspondants a deux coins opposes du carre. \n";
			std::cout << "Choisissez la position de la premiere : \n";
			std::cout << "abscisse ? \n";
			int xnew_carre_5_debut;
			std::cin >> xnew_carre_5_debut;
			this->filet5[0]->demande_brique()->modifie_position_x(xnew_carre_5_debut);

			std::cout << "ordonnee ? \n";
			int ynew_carre_5_debut;
			std::cin >> ynew_carre_5_debut;
			this->filet5[0]->demande_brique()->modifie_position_y(ynew_carre_5_debut);

			std::cout << "Choisissez l'ecart en abscisse entre deux bouees \n";
			int ecart_x_carre_5;
			std::cin >> ecart_x_carre_5;

			std::cout << "Choisissez l'ecart en ordonnee entre deux bouees \n";
			int ecart_y_carre_5;
			std::cin >> ecart_y_carre_5;

			// On modifie les coordonnees des autres bouees du filet //

			for(int i = 0; i<4; i++){
				if(i == 0){
					for(int j = 1; j<4; j++){
						this->filet5[4*i + j]->demande_brique()->modifie_position_x(this->filet5[4*i]->demande_brique()->position_x());
						this->filet5[4*i + j]->demande_brique()->modifie_position_y(this->filet5[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_5);
					}

				}else{
					this->filet5[4*i]->demande_brique()->modifie_position_x(this->filet5[4*(i-1)]->demande_brique()->position_x() + ecart_x_carre_5);
					this->filet5[4*i]->demande_brique()->modifie_position_y(this->filet5[4*(i-1)]->demande_brique()->position_y());
					for(int j = 1; j<4; j++){
						this->filet5[4*i + j]->demande_brique()->modifie_position_x(this->filet5[4*i]->demande_brique()->position_x());
						this->filet5[4*i + j]->demande_brique()->modifie_position_y(this->filet5[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_5);
					}
				}
			}
			this->etat = Mer::MAJ_MER;
			break;
		}
		break;

	case Mer::PHASE_5:

/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		std::cout << "Larguage du filet 6 : 9 bouees \n";
		std::cout << "Quelle forme voulez-vous utilisez pour le deuxieme larguage de bouees ? \n";
		std::cout << "ligne : 1, carre : 2  \n";
		int type_6;
		std::cin >> type_6;

		switch(type_6){
			/* ----------------- */
			/* --- Cas ligne --- */
			/* ----------------- */
		case 1:

			// On rentre les coordonnées de la première et dernière bouee //
			std::cout << "Vous allez choisir les 2 bouees aux extrémites de la ligne. \n";
			std::cout << "Choisissez la position de la premiere : \n";

			std::cout << "abscisse ? \n";
			int xnew_ligne_6_debut;
			std::cin >> xnew_ligne_6_debut;
			this->filet6[0]->demande_brique()->modifie_position_x(xnew_ligne_6_debut);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_6_debut;
			std::cin >> ynew_ligne_6_debut;
			this->filet6[0]->demande_brique()->modifie_position_y(ynew_ligne_6_debut);

			std::cout << "Choisissez la position de la derniere \n";
			std::cout << "abscisse ? \n";
			int xnew_ligne_6_fin;
			std::cin >> xnew_ligne_6_fin;
			this->filet6[8]->demande_brique()->modifie_position_x(xnew_ligne_6_fin);

			std::cout << "ordonnee ? \n";
			int ynew_ligne_6_fin;
			std::cin >> ynew_ligne_6_fin;
			this->filet6[8]->demande_brique()->modifie_position_y(ynew_ligne_6_fin);

			// On modifie les coordonnees des autres bouees du filet //

			int ecart_x;
			ecart_x = int(( this->filet6[8]->demande_brique()->position_x() - this->filet6[0]->demande_brique()->position_x() )/9) ;
			std::cout << "ecart x = " << ecart_x << "\n";
			for(int i = 1; i<8; i++){
				this->filet6[i]->demande_brique()->modifie_position_x( this->filet6[i-1]->demande_brique()->position_x() + ecart_x );
			}

			int ecart_y;
			ecart_y = int(( this->filet6[8]->demande_brique()->position_y() - this->filet6[0]->demande_brique()->position_y() )/9) ;
			std::cout << "ecart y = " << ecart_y << "\n";
			for(int i = 1; i<8; i++){
				this->filet6[i]->demande_brique()->modifie_position_y( this->filet6[i-1]->demande_brique()->position_y() + ecart_y );
			}
			this->etat = Mer::MAJ_MER;
			break;

			/* ----------------- */
			/* --- Cas carre --- */
			/* ----------------- */
		case 2: 
			// On choisit 2 bouees aux coins du carre //

			std::cout << "Vous allez choisir 2 bouees correspondants a deux coins opposes du carre. \n";
			std::cout << "Choisissez la position de la premiere : \n";
			std::cout << "abscisse ? \n";
			int xnew_carre_6_debut;
			std::cin >> xnew_carre_6_debut;
			this->filet6[0]->demande_brique()->modifie_position_x(xnew_carre_6_debut);

			std::cout << "ordonnee ? \n";
			int ynew_carre_6_debut;
			std::cin >> ynew_carre_6_debut;
			this->filet6[0]->demande_brique()->modifie_position_y(ynew_carre_6_debut);

			std::cout << "Choisissez l'ecart en abscisse entre deux bouees \n";
			int ecart_x_carre_6;
			std::cin >> ecart_x_carre_6;

			std::cout << "Choisissez l'ecart en ordonnee entre deux bouees \n";
			int ecart_y_carre_6;
			std::cin >> ecart_y_carre_6;

			// On modifie les coordonnees des autres bouees du filet //

			for(int i = 0; i<4; i++){
				if(i == 0){
					for(int j = 1; j<4; j++){
						this->filet6[4*i + j]->demande_brique()->modifie_position_x(this->filet6[4*i]->demande_brique()->position_x());
						this->filet6[4*i + j]->demande_brique()->modifie_position_y(this->filet6[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_6);
					}

				}else{
					this->filet6[4*i]->demande_brique()->modifie_position_x(this->filet6[4*(i-1)]->demande_brique()->position_x() + ecart_x_carre_6);
					this->filet6[4*i]->demande_brique()->modifie_position_y(this->filet6[4*(i-1)]->demande_brique()->position_y());
					for(int j = 1; j<4; j++){
						this->filet6[4*i + j]->demande_brique()->modifie_position_x(this->filet6[4*i]->demande_brique()->position_x());
						this->filet6[4*i + j]->demande_brique()->modifie_position_y(this->filet6[4*i+j-1]->demande_brique()->position_y() + ecart_y_carre_6);
					}
				}
			}
			this->etat = Mer::MAJ_MER;
			break;
		}
		break;

	case Mer::TROUVE:
/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */
		bool trouve;
		std::cout << "Avez-vous trouve le sous-marin ? \n";
		std::cout << "oui = 1, non = 0 \n";
		std::cin  >> trouve;
		if (trouve){
			std::cout << "Bravo !!! \n";
		}else{
			std::cout << "Perdu \n";
		}
		this->noyau.initialize();
		std::cout << "3 \n";
		this->noyau.synchronize(1000);
		std::cout << "2 \n";
		this->noyau.synchronize(1000);
		std::cout << "1 \n";
		this->noyau.synchronize(1000);
		this->nautilus->se_dessine();
		break;
/* -------------------- */
/* --- Etat MAJ_MER --- */
/* -------------------- */

	case Mer::MAJ_MER:

			this->noyau.initialize();
			// Le sous-marin se deplace un déplacement par seconde, ici 5 secondes //
			this->nautilus->cap_suivant();
			this->nautilus->se_deplace();
			this->noyau.synchronize(this->vitesse_deplacement);

			// Les bouees ecoutent et changent de couleur si elles détectent le sous-marin //

			//On regarde pour chaque filet //
			for (int i = 0; i< 16; i++){
				if ( distance(this->nautilus, this->filet1[i]) <= this->filet1[i]->demande_rayon() ){
					this->filet1[i]->change_couleur(1.0,0.0,0.0);
				}else{
					this->filet1[i]->change_couleur(1.0,1.0,0.0);
				}
			}
			for (int i = 0; i< 16; i++){
				if ( distance(this->nautilus, this->filet2[i]) <= this->filet2[i]->demande_rayon() ){
					this->filet2[i]->change_couleur(1.0,0.0,0.0);
				}else{
					this->filet2[i]->change_couleur(1.0,1.0,0.0);
				}
			}
			for (int i = 0; i< 9; i++){
				if ( distance(this->nautilus, this->filet3[i]) <= this->filet3[i]->demande_rayon() ){
					this->filet3[i]->change_couleur(1.0,0.0,0.0);
				}else{
					this->filet3[i]->change_couleur(1.0,1.0,0.0);
				}
			}
			for (int i = 0; i< 9; i++){
				if ( distance(this->nautilus, this->filet4[i]) <= this->filet4[i]->demande_rayon() ){
					this->filet4[i]->change_couleur(1.0,0.0,0.0);
				}else{
					this->filet4[i]->change_couleur(1.0,1.0,0.0);
				}
			}
			for (int i = 0; i< 9; i++){
				if ( distance(this->nautilus, this->filet5[i]) <= this->filet5[i]->demande_rayon() ){
					this->filet5[i]->change_couleur(1.0,0.0,0.0);
				}else{
					this->filet5[i]->change_couleur(1.0,1.0,0.0);
				}
			}
			for (int i = 0; i< 9; i++){
				if ( distance(this->nautilus, this->filet6[i]) <= this->filet6[i]->demande_rayon() ){
					this->filet6[i]->change_couleur(1.0,0.0,0.0);
				}else{
					this->filet6[i]->change_couleur(1.0,1.0,0.0);
				}
			}
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
