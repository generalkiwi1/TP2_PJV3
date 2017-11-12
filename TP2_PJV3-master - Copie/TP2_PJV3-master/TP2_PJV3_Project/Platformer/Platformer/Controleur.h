#pragma once
#include <string>
#include "Modele.h"

using std::string;
using namespace platformer;

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
		void confirmCreateData(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		bool confirmLoginData(const string pseudo, const string password);

	private:
		Controleur();
		static Controleur *instance;
		Scene::scenes lastScene = Scene::MENU;
		Scene::scenes currentScene = Scene::MENU;
		bool errorCreate = false;
		bool errorLogin = false;

		Controleur(const Controleur&);
		void operator=(const Controleur&);

		bool pseudoExiste(const string pseudo);
		bool correctPassword(const string password);
		bool correctNom(const string nom);
		bool correctPrenom(const string prenom);
		bool correctEmail(const string courriel);

		//Le contr�leur peut instancier les �l�ments de la couche mod�le, puisque c'est le seul qui est sens� y avoir acc�s.
		//S'il ne les instancie pas, alors il aura des pointeurs vers les classes
		Modele modele;
	};
}

