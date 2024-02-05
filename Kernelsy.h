/* +++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++ Declaration de la classe KernelSynchronizer +++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++ */

#ifndef KERNELSYNCHRONIZER_HH
#define KERNELSYNCHRONIZER_HH

/////////////////////////////////////////////////////////////////////////////

#include <sys/timeb.h>

class KernelSynchronizer {

	/* ======================= */
	/* === Membres publics === */
	/* ======================= */
public:

	/* ----------------------------------- */
	/* --- Methodes publiques standard --- */
	/* ----------------------------------- */
	KernelSynchronizer();
	~KernelSynchronizer();

	/* -------------------------------------- */
	/* --- Methodes publiques d'interface --- */
	/* -------------------------------------- */
	void initialize();
	void synchronize(int);
	bool temps_ecoule(int);

	/* ====================== */
	/* === Membres prives === */
	/* ====================== */
private:

	/* ----------------------- */
	/* --- Donnees privees --- */
	/* ----------------------- */
	struct timeb      realInitialTime;           // Heure physique au demarrage de la simulation
	struct timeb      realCurrentTime;           // Heure physique courante en cours de simulation

/* ------------------------ */
/* --- Methodes cachees --- */
/* ------------------------ */
	inline KernelSynchronizer(const KernelSynchronizer&);
	inline KernelSynchronizer& operator = (const KernelSynchronizer&);

	/* --------------------------------- */
	/* --- Methodes privees internes --- */
	/* --------------------------------- */
	void initialize_basic();
	void synchronize_basic(int);
};


/////////////////////////////////////////////////////////////////////////////

#endif
