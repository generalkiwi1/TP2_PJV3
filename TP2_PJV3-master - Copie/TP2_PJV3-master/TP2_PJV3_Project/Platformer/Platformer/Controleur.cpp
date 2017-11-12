#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Controleur.h"


using namespace MVC;

Controleur *Controleur::instance = nullptr;

Controleur::Controleur()
{

}

Controleur* Controleur::getInstance()
{
	if (!instance)
		instance = new Controleur();
	return instance;
}

void Controleur::release()
{
	delete instance;
	instance = nullptr;
}

int Controleur::changeCurrentScene(const int nextScene)
{
	if (currentScene == Scene::MENU && nextScene == 1 ) // Décalage de 1 à partir du menu - Login
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::MENU && nextScene == 2) // Décalage de 2 à partir du menu - Scores
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::MENU && nextScene == 3) // Décalage de 3 à partir du menu - Gestion
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::GESTION && nextScene == 1) // Décalage de 1 à partir de la gestion - Créer
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::GESTION && nextScene == 2) // Décalage de 2 à partir de la gestion - Modifier
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::GESTION && nextScene == 3) // Décalage de 3 à partir de la gestion - Effacer
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::GESTION && nextScene == 4) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::LOGIN && nextScene == 2) // De mauvais paramêtres ont été entrés
	{
		// Appel fonction valider nom et mot de passe
		lastScene = currentScene;
		currentScene = Scene::LOGIN;
		return (int)currentScene;
	}
	else if (currentScene == Scene::LOGIN && nextScene == 3) // De bon paramêtres ont été entrés
	{
		// Appel fonction valider nom et mot de passe
		lastScene = currentScene;
		currentScene = Scene::NIVEAU1;
		return (int)currentScene;
	}
	else if (currentScene == Scene::LOGIN && nextScene == 4) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::MEILLEURS_SCORES && nextScene == 3) // Validation des paramètres entrés
	{
		// Appel fonction valider des paramêtres de recherche
		lastScene = currentScene;
		return (int)currentScene;
	}
	else if (currentScene == Scene::MEILLEURS_SCORES && nextScene == 4) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::CREER && nextScene == 6) // Validation des paramètres entrés
	{
		lastScene = currentScene;
		return (int)currentScene;
	}
	else if (currentScene == Scene::CREER && nextScene == 7) // Retour à la Gestion(3)
	{
		int sceneIncrementation = 3;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::MODIFIER && nextScene == 6) // Validation des paramètres entrés
	{
		// Appel fonction valider des paramêtres de recherche
		lastScene = currentScene;
		return (int)currentScene;
	}
	else if (currentScene == Scene::MODIFIER && nextScene == 7) // Retour à la Gestion(3)
	{
		int sceneIncrementation = 3;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::EFFACER && nextScene == 3) // Validation des paramètres entrés
	{
		// Appel fonction valider des paramêtres de recherche
		lastScene = currentScene;
		return (int)currentScene;
	}
	else if (currentScene == Scene::EFFACER && nextScene == 4) // Retour à la Gestion(3)
	{
		int sceneIncrementation = 3;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == Scene::NIVEAU1 && nextScene == 0) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (nextScene == 8) // Sortie du jeu
	{
		int sceneIncrementation = 8;
		lastScene = currentScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else
	{
		return (int)currentScene;
	}
}

bool Controleur::getErrorCreate()
{
	return errorCreate;
}

void Controleur::confirmCreateData(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	errorCreate = false;
	if (pseudo.length() >= 3 && pseudo.length() <= 25 &&
		password.length() >= 5 && password.length() <= 15 &&
		nom.length() >= 2 && nom.length() <= 25 &&
		prenom.length() >= 2 && prenom.length() <= 25
		)
	{
		errorCreate = pseudoExiste(pseudo); // Vérification pseudo
		if(!errorCreate)
			errorCreate = correctPassword(password); // Vérification mot de passe
		if (!errorCreate)
			errorCreate = correctNom(nom); // Vérification nom
		if (!errorCreate)
			errorCreate = correctPrenom(prenom); // Vérification prenom
		if (!errorCreate)
			errorCreate = correctEmail(courriel); // Vérification email
	}
	else
		errorCreate = true;

	// Si tout marche on l'entre dans la liste de compte
	if (!errorCreate)
		modele.creationCompte(pseudo, password, nom, prenom, courriel);	
}


bool Controleur::pseudoExiste(const string pseudo)
{
	bool pseudoExist = false;
	{
		ifstream lectureDeFichierCompte("compte.txt"); // fichier de comptes
		string line;

		while (getline(lectureDeFichierCompte, line))
		{
			stringstream l(line);
			string fichierPseudo = "";

			l >> fichierPseudo ;
			if (fichierPseudo == pseudo)
				pseudoExist = true;

			cout << fichierPseudo << " " << pseudoExist <<endl;
		}
	}
	return pseudoExist;
}

bool Controleur::correctPassword(const string password)
{
	bool incorrectPassword = true;
	bool lettreMinuscule = false;
	bool lettreMajuscule = false;
	bool estUnChiffre = false;
	bool caractereSpecial = false;
	for (int i = 0; i < password.length(); ++i)
	{
		if ((int)password.at(i) >= 33 && (int)password.at(i) <= 47 ||
			(int)password.at(i) >= 58 && (int)password.at(i) <= 64 ||
			(int)password.at(i) >= 91 && (int)password.at(i) <= 96 ||
			(int)password.at(i) >= 123 && (int)password.at(i) <= 126) // Vérification de lettre spéciale
			caractereSpecial = true;
		else if ((int)password.at(i) >= 48 && (int)password.at(i) <= 57) // Vérification chiffre
			estUnChiffre = true;
		else if ((int)password.at(i) >= 65 && (int)password.at(i) <= 90) // Vérification Majuscule
			lettreMajuscule = true;
		else if ((int)password.at(i) >= 97 && (int)password.at(i) <= 122) // Vérification Minuscule
			lettreMinuscule = true;
	}
	if (lettreMinuscule && lettreMajuscule && estUnChiffre && caractereSpecial)
		incorrectPassword = false;
	return incorrectPassword;
}

bool Controleur::correctNom(const string nom)
{
	bool wrongtName = false;
	for (int i = 0; i < nom.length(); ++i)
	{
		if ((int)nom.at(i) >= 65 && (int)nom.at(i) <= 90 || // Vérification Majuscule
			(int)nom.at(i) >= 97 && (int)nom.at(i) <= 122 || // Vérification Minuscule
			(int)nom.at(i) == 45 || (int)nom.at(i) == 46 ) // Vérification . et -
		{ }
		else
		{
			wrongtName = true;
			break;
		}
		return wrongtName;
	}
}

bool Controleur::correctPrenom(const string prenom)
{
	bool wrongtFirstName = false;
	for (int i = 0; i < prenom.length(); ++i)
	{
		if ((int)prenom.at(i) >= 65 && (int)prenom.at(i) <= 90 || // Vérification Majuscule
			(int)prenom.at(i) >= 97 && (int)prenom.at(i) <= 122 || // Vérification Minuscule
			(int)prenom.at(i) == 45 || (int)prenom.at(i) == 46) // Vérification . et -
		{ }
		else
		{
			wrongtFirstName = true;
			break;
		}
	}
	return wrongtFirstName;
}
bool Controleur::correctEmail(const string courriel)
{
	bool invalidCourriel = false;
	int nbArobas = 0; // Nombre d'arrobas doit être égal à 1
	
	for (int i = 0; i < courriel.length(); ++i)
	{
		if ((int)courriel.at(i) >= 65 && (int)courriel.at(i) <= 90 || // Vérification Majuscule
			(int)courriel.at(i) >= 97 && (int)courriel.at(i) <= 122 || // Vérification Minuscule
			(int)courriel.at(i) == 45 || (int)courriel.at(i) == 46 || (int)courriel.at(i) == 95) // Vérification . et - et _
		{
		}
		else if ((int)courriel.at(i) == 64)
		{
			nbArobas++;
		}
		else
			invalidCourriel = true;
	}

	if (!invalidCourriel && nbArobas == 1)
	{
		int preffixIndex = courriel.find_first_of('@'); // Validation position des caractêres (préfixe)
		int domainIndex = courriel.find_last_of('.'); // Validation position des caractêres (suffixe)

		if (domainIndex == -1)
			invalidCourriel = true;
		else
		{
			string preffix = courriel.substr(0, preffixIndex); // Le préfixe doit être plus grand que 1
			string suffix = courriel.substr(preffixIndex+1, domainIndex); // Le suffixe doit être plus grand que 1 (Le plus 1 sert a éliminer le @)
			string domain = courriel.substr(domainIndex+1); // (Le plus 1 sert a éliminer le .)
			if (preffix.length() <= 0 || suffix.length() <= 0 || domain.length() < 2 || domain.length() > 3)
				invalidCourriel = true;
		}
	}
	else
		invalidCourriel = true; // Si l'arobas existe ou s'il est plus grand que 1

	return invalidCourriel;
}

bool Controleur::confirmLoginData(const string pseudo, const string password)
{
	errorLogin = false;
	bool validAccount = false;
	{
		ifstream lectureDeFichierCompte("compte.txt"); // fichier de comptes
		string line;

		while (getline(lectureDeFichierCompte, line))
		{
			stringstream l(line);
			string fichierPseudo = "", fichierPassword = "";

			l >> fichierPseudo >> fichierPassword;
			if (fichierPseudo == pseudo && fichierPassword == password)
			{
				validAccount = true;	
				modele.sauvegardeJoueur(pseudo);
				break;
			}
		}
	}
	if (!validAccount)
		errorLogin = true;

	return validAccount;
}

bool Controleur::getErrorLogin()
{
	return errorLogin;
}









