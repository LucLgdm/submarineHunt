/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Bouee +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#ifndef BOUEE_HH
#define BOUEE_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Brique.h"

class Bouee {

	/* ======================= */
	/* === Membres publics === */
	/* ======================= */
public:

	/* ----------------------------------- */
	/* --- Méthodes publiques standard --- */
	/* ----------------------------------- */
	Bouee(int, int);
	~Bouee();

	/* -------------------------------------- */
	/* --- Méthodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	void se_dessine();
	Brique* demande_brique();
	int demande_rayon();
	void change_couleur(double, double, double);

	/* ====================== */
	/* === Membres privés === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Données privées --- */
	/* ----------------------- */
	Brique* bouee;
	int rayon_action;
	/* ------------------------ */
	/* --- Méthodes cachées --- */
	/* ------------------------ */
	inline Bouee(const Bouee&);
	inline Bouee& operator = (const Bouee&);

	/* --------------------------------- */
	/* --- Méthodes privées internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Bouee& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif