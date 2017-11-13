#pragma once
#include <string>

using std::string;

namespace MVC
{
	class Modele
	{
	public:
		Modele();
		int switchScene(const int nextScene);
		int getScene();

		void creationCompte(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		void modificationCompte (const string pseudo, const string password, const string nom, const string prenom, const string courriel);

		void sauvegardeJoueur(const string pseudo);
		string getJoueur();


	private:
		int currentScene = 0;
		string joueurCourant = "";
	};
}
