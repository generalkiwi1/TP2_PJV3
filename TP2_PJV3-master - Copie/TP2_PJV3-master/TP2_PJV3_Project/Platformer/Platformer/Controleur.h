#pragma once
#include <string>
#include "Modele.h"

using std::string;

namespace MVC
{
	class Controleur
	{
	public:
		static Controleur *getInstance();
		static void release();

		int changeCurrentScene(const int nextScene);

		bool getErrorCreate();
		bool getErrorLogin();
		int getErrorModification();
		int getLastEffacerState();

		void confirmCreateData(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		bool confirmLoginData(const string pseudo, const string password);
		bool confirmModificationData(const string pseudo, const string password);
		bool confirmEraseData(const string pseudo, const string password);
		void effacerCompte();
		void testDonneesAModifier(const string pseudo, const string password, const string nom, const string prenom, const string courriel);

	private:
		Controleur();
		static Controleur *instance;
		int currentScene = 0;
		bool errorCreate = false;
		bool errorLogin = false;
		int stateModification = 0;
		int stateEffacer = 0;

		Controleur(const Controleur&);
		void operator=(const Controleur&);

		bool pseudoExiste(const string pseudo);
		bool correctPassword(const string password);
		bool correctNom(const string nom);
		bool correctPrenom(const string prenom);
		bool correctEmail(const string courriel);

		//Le contrôleur peut instancier les éléments de la couche modèle, puisque c'est le seul qui est sensé y avoir accès.
		//S'il ne les instancie pas, alors il aura des pointeurs vers les classes
		Modele modele;
	};
}

