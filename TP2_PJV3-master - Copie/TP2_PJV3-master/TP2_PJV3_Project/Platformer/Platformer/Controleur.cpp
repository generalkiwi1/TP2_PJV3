#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Controleur.h"

// Mika - 1640194

using namespace std;
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
	if (currentScene == 0 && nextScene == 1 ) // Décalage de 1 à partir du menu - Login
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 0 && nextScene == 2) // Décalage de 2 à partir du menu - Scores
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 0 && nextScene == 3) // Décalage de 3 à partir du menu - Gestion
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 3 && nextScene == 1) // Décalage de 1 à partir de la gestion - Créer
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 3 && nextScene == 2) // Décalage de 2 à partir de la gestion - Modifier
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 3 && nextScene == 3) // Décalage de 3 à partir de la gestion - Effacer
	{
		int sceneIncrementation = (int)currentScene + nextScene;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 3 && nextScene == 4) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene ==1 && nextScene == 2) // De mauvais paramêtres ont été entrés
	{
		// Appel fonction valider nom et mot de passe
		currentScene = 1;
		return (int)currentScene;
	}
	else if (currentScene ==1 && nextScene == 3) // De bon paramêtres ont été entrés
	{
		// Appel fonction valider nom et mot de passe
		currentScene = 7;
		return (int)currentScene;
	}
	else if (currentScene == 1 && nextScene == 4) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 2 && nextScene == 3) // Validation des paramètres entrés
	{
		// Appel fonction valider des paramêtres de recherche
		return (int)currentScene;
	}
	else if (currentScene == 2 && nextScene == 4) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 4 && nextScene == 6) // Validation des paramètres entrés
	{
		return (int)currentScene;
	}
	else if (currentScene == 4 && nextScene == 7) // Retour à la Gestion(3)
	{
		int sceneIncrementation = 3;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 5 && nextScene == 6) // Validation des paramètres entrés
	{
		// Appel fonction valider des paramêtres de recherche
		if (stateModification == 2)
		{
			int sceneIncrementation = 0; // Retour au menu
			currentScene = modele.switchScene(sceneIncrementation);
			stateModification = 0; // Remise à zéro pour de nouvelle modification
			modele.sauvegardeJoueur(""); // On enlève le joueur courrant utiliser pour garder l'utilisateur à sauvegarder
		}
		return (int)currentScene;
	}
	else if (currentScene == 5 && nextScene == 7) // Retour à la Gestion(3)
	{
		int sceneIncrementation = 3;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 6 && nextScene == 3) // Validation des paramètres entrés
	{
		// Appel fonction valider des paramêtres de recherche
		if (stateEffacer == 2)
		{
			int sceneIncrementation = 0; // Retour au menu
			currentScene = modele.switchScene(sceneIncrementation);
			stateEffacer = 0; // Remise à zéro pour de nouvelle modification
			modele.sauvegardeJoueur(""); // On enlève le joueur courrant utiliser pour garder l'utilisateur à sauvegarder
		}
		return (int)currentScene;
	}
	else if (currentScene == 6 && nextScene == 4) // Retour à la Gestion(3)
	{
		int sceneIncrementation = 3;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (currentScene == 7 && nextScene == 0) // Retour au Menu(0)
	{
		int sceneIncrementation = 0;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else if (nextScene == 8) // Sortie du jeu
	{
		int sceneIncrementation = 8;
		currentScene = modele.switchScene(sceneIncrementation);
		return (int)currentScene;
	}
	else
	{
		return (int)currentScene;
	}
}

// Erreur de création (état)
bool Controleur::getErrorCreate()
{
	return errorCreate;
}

// Validation du compte à créer
void Controleur::confirmCreateData(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	errorCreate = false;
	if (pseudo.length() >= 3 && pseudo.length() <= 25 &&
		password.length() >= 5 && password.length() <= 15 &&
		nom.length() >= 2 && nom.length() <= 25 &&
		prenom.length() >= 2 && prenom.length() <= 25
		)
	{
		// Les fonctions ci-dessous retourne faux s'il ni a pas d'erreur d'entées pour le compte
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
	else
		errorCreate = true;
}

// On vérifi si le joueur existe
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
		}
	}
	return pseudoExist;
}

// On vérifie le mot de passe
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

// On vérifie le nom
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
	}
	return wrongtName;
}

// On vérifie le prenom
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

// On vérifie l'email
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
			string suffix = courriel.substr(preffixIndex+1, domainIndex-preffixIndex-1); // Le suffixe doit être plus grand que 1 (Le plus 1 sert a éliminer le @)
			string domain = courriel.substr(domainIndex+1); // (Le plus 1 sert a éliminer le .)
			if (preffix.length() <= 0 || suffix.length() <= 0 || domain.length() < 2 || domain.length() > 3)
				invalidCourriel = true;
		}
	}
	else
		invalidCourriel = true; // Si l'arobas existe ou s'il est plus grand que 1

	return invalidCourriel;
}

// Vérification du login
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
	else
		errorLogin = false;
	return validAccount; // False s'il n'y a pas de problème
}

// Vérification des modifications (du compte voulant être modifier)
bool Controleur::confirmModificationData(const string pseudo, const string password)
{
	stateModification = 0; // État de base
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
				break;
			}
		}
	}
	if (validAccount) // Si c'est un compte valide
	{
		stateModification = 1;
		modele.sauvegardeJoueur(pseudo);
	}

	return validAccount; // True si tout est bon
}

// Vérification des données à effacer
bool Controleur::confirmEraseData(const string pseudo, const string password)
{
	stateEffacer = 0;
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
				break;
			}
		}
	}
	if (validAccount) // Si tout est bon on change l'état à 1 pour valide
	{
		stateEffacer = 1;
		modele.sauvegardeJoueur(pseudo);
	}

	return validAccount;
}

/// Test des données avant de les écrire 
void Controleur::testDonneesAModifier(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	bool validData = false;
	if (pseudo == modele.getJoueur())
	{
		if (pseudo.length() >= 3 && pseudo.length() <= 25 &&
			password.length() >= 5 && password.length() <= 15 &&
			nom.length() >= 2 && nom.length() <= 25 &&
			prenom.length() >= 2 && prenom.length() <= 25
			)
		{
			validData = correctPassword(password); // Vérification mot de passe
			if (!validData)
				validData = correctNom(nom); // Vérification nom
			if (!validData)
				validData = correctPrenom(prenom); // Vérification prenom
			if (!validData)
				validData = correctEmail(courriel); // Vérification email
		}
		else
			validData = true;
		// Si tout marche on l'entre dans la liste de compte
		if (!validData)
		{
			{ // Delete le compte et on le remplace
				ifstream lectureDeFichierCompte("compte.txt");
				ofstream output("temp.txt");
				
				string line;

				while (getline(lectureDeFichierCompte, line)) // On efface le compte
				{
					stringstream l(line);
					string fichierPseudo = "", fichierMotDePasse = "", fichierNom = "", fichiePrenom = "", fichieCouriel = "";

					l >> fichierPseudo >> fichierMotDePasse >> fichierNom >> fichiePrenom >> fichieCouriel;

					string currentAccount = fichierPseudo + " " + fichierMotDePasse + " " + fichierNom + " " + fichiePrenom + " " + fichieCouriel;

					if (pseudo == fichierPseudo)
					{
					} // on ne copie pas la ligne
					else // on copie la ligne
						output << currentAccount << endl;
				}
			}
			std::remove("compte.txt");
			std::rename("temp.txt", "compte.txt");
			stateModification = 2;
			modele.modificationCompte(pseudo, password, nom, prenom, courriel);
		}
	}
}

// On efface le compte s'il est valide
void Controleur::effacerCompte()
{
	{ // Delete le compte et on le remplace
		ifstream lectureDeFichierCompte("compte.txt");
		ofstream output("temp.txt");

		string line;

		while (getline(lectureDeFichierCompte, line)) // On efface le compte
		{
			stringstream l(line);
			string fichierPseudo = "", fichierMotDePasse = "", fichierNom = "", fichiePrenom = "", fichieCouriel = "";

			l >> fichierPseudo >> fichierMotDePasse >> fichierNom >> fichiePrenom >> fichieCouriel;

			string currentAccount = fichierPseudo + " " + fichierMotDePasse + " " + fichierNom + " " + fichiePrenom + " " + fichieCouriel;

			if (modele.getJoueur() == fichierPseudo)
			{
			} // on ne copie pas la ligne
			else // on copie la ligne
				output << currentAccount << endl;
		}
	}
	std::remove("compte.txt");
	std::rename("temp.txt", "compte.txt");
	stateModification = 2;
	modele.sauvegardeJoueur("");
}

// retourne l'état de la scene login
bool Controleur::getErrorLogin()
{
	return errorLogin;
}

// retourne l'état de la scene modifier
int Controleur::getErrorModification()
{
	return stateModification;
}

// retourne l'état de la scene effacer
int Controleur::getLastEffacerState()
{
	return stateEffacer;
}














