	/* +++++++++++++++++++++++++++++++++++++++ */
	/* +++ Déclaration de la classe Brique +++ */
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
	/* --- Méthodes publiques standard --- */
	/* ----------------------------------- */
	Brique(int, int, double, double, double);
	~Brique();


	/* -------------------------------------- */
	/* --- Méthodes publiques d'interface --- */
	/* -------------------------------------- */
	void selfDisplay(std::ostream&) const;
	int position_x();
	int position_y();
	void se_dessine();
	void modifie_position_x(int);
	void modifie_position_y(int);
	void modifie_couleur(double, double, double);

	/* ====================== */
	/* === Membres privés === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Données privées --- */
	/* ----------------------- */
	int x;
	int y;
	int taille;
	double rouge;
	double vert;
	double bleu;
	/* ------------------------ */
	/* --- Méthodes cachées --- */
	/* ------------------------ */
	inline Brique(const Brique&);
	inline Brique& operator = (const Brique&);

	/* --------------------------------- */
	/* --- Méthodes privées internes --- */
	/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Brique& objet) {
	objet.selfDisplay(stream);
	return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif