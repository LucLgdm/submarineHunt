/* +++++++++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Sous_marin +++ */
/* +++++++++++++++++++++++++++++++++++++++++++ */

#ifndef SOUS_MARIN_HH
#define SOUS_MARIN_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>

// #include "Direction.h"
#include "Brique.h"

class Sous_marin {

	/* ======================= */
	/* === Membres publics === */
	/* ======================= */
public:

	/* ----------------------------------- */
	/* --- M�thodes publiques standard --- */
	/* ----------------------------------- */
	Sous_marin(int, int);
	~Sous_marin();

	/* -------------------------------------- */
	/* --- M�thodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	void se_dessine();
	void se_deplace();
	int  demande_position_x();
	int  demande_position_y();
	void cap_suivant();

	/* ====================== */
	/* === Membres priv�s === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Donn�es priv�es --- */
	/* ----------------------- */
	Brique* cap[502];
	Brique* coque[4];
	int position_cap;
	/* ------------------------ */
	/* --- M�thodes cach�es --- */
	/* ------------------------ */
	inline Sous_marin(const Sous_marin&);
	inline Sous_marin& operator = (const Sous_marin&);

	/* --------------------------------- */
	/* --- M�thodes priv�es internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Sous_marin& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif