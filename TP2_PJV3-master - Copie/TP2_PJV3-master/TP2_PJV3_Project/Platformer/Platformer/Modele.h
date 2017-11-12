#pragma once
#include <string>
#include "Scene.h"

using std::string;
using namespace platformer;

namespace MVC
{
	class Modele
	{
	public:
		Modele();
		Scene::scenes switchScene(const int nextScene);

		void creationCompte(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		void sauvegardeJoueur(const string pseudo);
	private:
		Scene::scenes currentScene = Scene::MENU; // Scene courante
		string joueurCourant = "";
	};
}
