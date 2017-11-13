#include "Modele.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using namespace MVC;

Modele::Modele()
{
	
}

// Changement de scene
int Modele::switchScene(const int nextScene)
{
	const int nextSceneSwitch = nextScene;
	switch (nextSceneSwitch)
		// 0 = MENU
		// 1 = LOGIN
		// 2 = MEILLEURS_SCORES
		// 3 = GESTION 
		// 4 = CREER
		// 5 = MODIFIER
		// 6 = EFFACER
		// 7 = NIVEAU1
		// 8 = SORTIE
	{
	case 0:
		currentScene = 0; // La scene courante
		break;
	case 1:
		currentScene = 1;
		break;
	case 2:
		currentScene = 2;
		break;
	case 3:
		currentScene = 3;
		break;
	case 4:
		currentScene = 4;
		break;
	case 5:
		currentScene = 5;
		break;
	case 6:
		currentScene = 6;
		break;
	case 7:
		currentScene = 7;
		break;
	case 8:
		currentScene = 8;
		break;
	}
	return currentScene;
}

/// Ajoute un compte valide à la fin du fichier
void Modele::creationCompte(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	{
		ofstream lectureDeFichierCompte("compte.txt", ios::app); // fichier de comptes
		string compte = pseudo + " " + password + " " + nom + " " + prenom + " " + courriel; // Création de l'entrée
		lectureDeFichierCompte << compte << endl; // Implémentation dans le fichier
	}
}

/// Ajoute un compte valide à la fin du fichier
void Modele::modificationCompte(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	{
		ofstream lectureDeFichierCompte("compte.txt", ios::app); // fichier de comptes
		string compte = pseudo + " " + password + " " + nom + " " + prenom + " " + courriel; // Création de l'entrée
		lectureDeFichierCompte << compte << endl; // Implémentation dans le fichier
	}
}

///Sauvegarde du joueur courant
void Modele::sauvegardeJoueur(const string pseudo)
{
	joueurCourant = pseudo;
}

/// Retourne le joueur courant
string Modele::getJoueur()
{
	return joueurCourant;
}

/// Retourne la scene courante
int Modele::getScene()
{
	return currentScene;
}











