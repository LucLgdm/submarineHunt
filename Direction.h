/* ++++++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Direction +++ */
/* ++++++++++++++++++++++++++++++++++++++++++ */

#ifndef DIRECTION_HH
#define DIRECTION_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Brique.h"

class Direction {

	/* ======================= */
	/* === Membres publics === */
	/* ======================= */
public:

	/* ----------------------------------- */
	/* --- Méthodes publiques standard --- */
	/* ----------------------------------- */
	Direction(int, int);
	~Direction();

	/* -------------------------------------- */
	/* --- Méthodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	Brique* demande_chemin(int);

	/* ====================== */
	/* === Membres privés === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Données privées --- */
	/* ----------------------- */
	Brique* Chemin[500];
	/* ------------------------ */
	/* --- Méthodes cachées --- */
	/* ------------------------ */
	inline Direction(const Direction&);
	inline Direction& operator = (const Direction&);

	/* --------------------------------- */
	/* --- Méthodes privées internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Direction& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif