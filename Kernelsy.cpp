/* ++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++ Definition de la classe KernelSynchronizer +++ */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++ */

#include "kernelsy.h"
#include <iostream>


/////////////////////////////////////////////////////////////////////////////
///                      Methodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
KernelSynchronizer::KernelSynchronizer() {

	/* --------------------------------------------------------- */
	/* --- Initialisations de securite (inutile en principe) --- */
	/* --------------------------------------------------------- */
	realInitialTime.time = 0;     // relatif a la methode utilisant ftime()
	realInitialTime.millitm = 0;     // relatif a la methode utilisant ftime()
	realCurrentTime.time = 0;     // relatif a la methode utilisant ftime()
	realCurrentTime.millitm = 0;     // relatif a la methode utilisant ftime()
}

/* =================== */
/* === Destructeur === */
/* =================== */
KernelSynchronizer::~KernelSynchronizer() {
}

/////////////////////////////////////////////////////////////////////////////
///                    Methodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* =========================== */
/* === Fonction initialize === */
/* =========================== */
void KernelSynchronizer::initialize() {
	this->initialize_basic();
}

/* ============================================================ */
/* ===                 Fonction synchronize                 === */
/* ===                                                      === */
/* === Cette fonction permet de realiser la synchronisation === */
/* === du noyau de simulation suivant le mode temps réel    === */
/* ===                                                      === */
/* === La fonction met a jour les donnees membres relatives === */
/* === au temps reel courant.                               === */
/* ============================================================ */
void KernelSynchronizer::synchronize(int dureeMS) {
	this->synchronize_basic(dureeMS);
}


/////////////////////////////////////////////////////////////////////////////
///                       Methodes privees internes                       ///
/////////////////////////////////////////////////////////////////////////////


/* ================================= */
/* === Fonction initialize_basic === */
/* ================================= */
void KernelSynchronizer::initialize_basic() {
	ftime(&realInitialTime);
}

/* ================================== */
/* === Fonction synchronize_basic === */
/* ================================== */
void KernelSynchronizer::synchronize_basic(int dureeMS) {

 /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
 /* ~~~ Mise a jour des donnees membres relatives au temps reel courant ~~~ */
 /* ~~~ et au temps virtuel courant (temps de simulation effectue)      ~~~ */
 /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
	ftime(&realCurrentTime);
	int tempsReelEcouleMS = 1000 * ( (unsigned long int)realCurrentTime.time -
		                              (unsigned long int)realInitialTime.time) +
        		               (realCurrentTime.millitm - realInitialTime.millitm);

	/* ----------------------------------------------------------------- */
	/* --- Si la simulation a moins de 10 millisecondes d'avance sur --- */
	/* --- le temps physique on considere qu'elle est en retard      --- */
	/* ----------------------------------------------------------------- */
	if (dureeMS < tempsReelEcouleMS + 10) {
		return;
	}

	/* ------------------------------------------------------------------------------------ */
	/* --- Sinon, on considere qu'on est en avance, on attend donc pour se synchroniser --- */
	/* ------------------------------------------------------------------------------------ */
	while (dureeMS >= tempsReelEcouleMS + 10) {
		ftime(&realCurrentTime);
		tempsReelEcouleMS = 1000 * ((unsigned long int)realCurrentTime.time -
			                         (unsigned long int)realInitialTime.time) +
			                 (realCurrentTime.millitm - realInitialTime.millitm);
	}
}

/* ============================= */
/* === Fonction temps_ecoule === */
/* ============================= */
bool KernelSynchronizer :: temps_ecoule(int dt){
	ftime(&realCurrentTime);
	int tempsReelEcouleMS = 1000 * ( (unsigned long int)realCurrentTime.time -
		                              (unsigned long int)realInitialTime.time) +
        		               (realCurrentTime.millitm - realInitialTime.millitm);
	return (tempsReelEcouleMS >= dt-10);
}

