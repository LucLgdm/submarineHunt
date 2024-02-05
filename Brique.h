	/* +++++++++++++++++++++++++++++++++++++++ */
	/* +++ D�claration de la classe Brique +++ */
	/* +++++++++++++++++++++++++++++++++++++++ */

	#ifndef BRIQUE_HH
	#define BRIQUE_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Brique {

	/* ======================= */
	/* === Membres publics === */
	/* ======================= */
public:

	/* ----------------------------------- */
	/* --- M�thodes publiques standard --- */
	/* ----------------------------------- */
	Brique(int, int, double, double, double);
	~Brique();


	/* -------------------------------------- */
	/* --- M�thodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	int position_x();
	int position_y();
	void se_dessine();
	void modifie_position_x(int);
	void modifie_position_y(int);
	void modifie_couleur(double, double, double);

	/* ====================== */
	/* === Membres priv�s === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Donn�es priv�es --- */
	/* ----------------------- */
	int x;
	int y;
	int taille;
	double rouge;
	double vert;
	double bleu;
	/* ------------------------ */
	/* --- M�thodes cach�es --- */
	/* ------------------------ */
	inline Brique(const Brique&);
	inline Brique& operator = (const Brique&);

	/* --------------------------------- */
	/* --- M�thodes priv�es internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Brique& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif