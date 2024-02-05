/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Bouee +++ */
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
	/* --- M�thodes publiques standard --- */
	/* ----------------------------------- */
	Bouee(int, int);
	~Bouee();

	/* -------------------------------------- */
	/* --- M�thodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	void se_dessine();
	Brique* demande_brique();
	int demande_rayon();
	void change_couleur(double, double, double);

	/* ====================== */
	/* === Membres priv�s === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Donn�es priv�es --- */
	/* ----------------------- */
	Brique* bouee;
	int rayon_action;
	/* ------------------------ */
	/* --- M�thodes cach�es --- */
	/* ------------------------ */
	inline Bouee(const Bouee&);
	inline Bouee& operator = (const Bouee&);

	/* --------------------------------- */
	/* --- M�thodes priv�es internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Bouee& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif