/* ++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Mer +++ */
/* ++++++++++++++++++++++++++++++++++++ */

#ifndef MER_HH
#define MER_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Sous_marin.h"
#include "Bouee.h"
#include "kernelsy.h"

class Mer {

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:
/* ------------------------- */
/* --- Donn�es publiques --- */
/* ------------------------- */
	   static const int PHASE_0;
	   static const int PHASE_1;
	   static const int PHASE_2;
	   static const int PHASE_3;
	   static const int PHASE_4;
	   static const int PHASE_5;

	   static const int MAJ_MER;
	   static const int MAJ_MER_2;
	   static const int MAJ_MER_3;
	   static const int MAJ_MER_4;
	   static const int MAJ_MER_5;
	   static const int MAJ_MER_6;
	   static const int MAJ_MER_7;
	   static const int TROUVE;

/* ----------------------------------- */
/* --- M�thodes publiques standard --- */
/* ----------------------------------- */
      Mer(int, int);
      ~Mer();

/* -------------------------------------- */
/* --- M�thodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
	  void se_dessine();
	  int demande_etat();
	  void modifie_etat(int);
	  void simulation();
	  double distance(Sous_marin*, Bouee*);
	  Sous_marin* demande_sous_marin();
	  

/* ====================== */
/* === Membres priv�s === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Donn�es priv�es --- */
/* ----------------------- */
		Sous_marin* nautilus;
		Bouee* filet1[16];			// Paquet de bou�es � larguer
		Bouee* filet2[16];			// Il faut des carr�s de nombre
		Bouee* filet3[9];
		Bouee* filet4[9];
		Bouee* filet5[9];
		Bouee* filet6[9];
		int etat;
		KernelSynchronizer noyau;
		int vitesse_deplacement;

/* ------------------------ */
/* --- M�thodes cach�es --- */
/* ------------------------ */
      inline Mer(const Mer&);
      inline Mer& operator = (const Mer&);

/* --------------------------------- */
/* --- M�thodes priv�es internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Mer& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif