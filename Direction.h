/* ++++++++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Direction +++ */
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
	/* --- M�thodes publiques standard --- */
	/* ----------------------------------- */
	Direction(int, int);
	~Direction();

	/* -------------------------------------- */
	/* --- M�thodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	Brique* demande_chemin(int);

	/* ====================== */
	/* === Membres priv�s === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Donn�es priv�es --- */
	/* ----------------------- */
	Brique* Chemin[500];
	/* ------------------------ */
	/* --- M�thodes cach�es --- */
	/* ------------------------ */
	inline Direction(const Direction&);
	inline Direction& operator = (const Direction&);

	/* --------------------------------- */
	/* --- M�thodes priv�es internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Direction& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif