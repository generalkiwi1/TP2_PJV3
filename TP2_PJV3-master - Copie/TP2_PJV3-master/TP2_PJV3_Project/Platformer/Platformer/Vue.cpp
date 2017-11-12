#include "Vue.h"
#include <iostream>
#include "Controleur.h"


using namespace std;
using namespace MVC;

Vue::Vue()
{
}

int Vue::staySameWindow(const int buttonValue)
{
	return Controleur::getInstance()->changeCurrentScene(buttonValue);
}

bool Vue::lastDataInvalidCreate()
{
	return Controleur::getInstance()->getErrorCreate();
}


void Vue::confirmEnterredDataCreate(const string pseudo, const string password, const string nom, const string prenom, const string courriel)
{
	Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
}

bool Vue::confirmerEntreeDataLogin(const string pseudo, const string password)
{
	return Controleur::getInstance()->confirmLoginData(pseudo, password);
}

bool Vue::lastDataInvalidLogin()
{
	return Controleur::getInstance()->getErrorLogin();
}



