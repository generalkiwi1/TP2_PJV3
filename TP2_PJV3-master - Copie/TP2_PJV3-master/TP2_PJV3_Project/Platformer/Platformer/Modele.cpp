#include "Modele.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace MVC;

Modele::Modele()
{
	
}

Scene::scenes Modele::switchScene(const int nextScene)
{

	int nextSceneSwitch = nextScene;
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
		currentScene = Scene::MENU;
		break;
	case 1:
		currentScene = Scene::LOGIN;
		break;
	case 2:
		currentScene = Scene::MEILLEURS_SCORES;
		break;
	case 3:
		currentScene = Scene::GESTION;
		break;
	case 4:
		currentScene = Scene::CREER;
		break;
	case 5:
		currentScene = Scene::MODIFIER;
		break;
	case 6:
		currentScene = Scene::EFFACER;
		break;
	case 7:
		currentScene = Scene::NIVEAU1;
		break;
	case 8:
		currentScene = Scene::SORTIE;
		break;
	default:
		break;
	}
	return currentScene;
}

void Modele::creationCompte(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	{
		ofstream lectureDeFichierCompte("compte.txt", ios::app); // fichier de comptes
		string compte = pseudo + " " + password + " " + nom + " " + prenom + " " + courriel; // Création de l'entrée
		lectureDeFichierCompte << compte << endl; // Implémentation dans le fichier
	}
}

void Modele::sauvegardeJoueur(const string pseudo)
{
	joueurCourant = pseudo;
}









