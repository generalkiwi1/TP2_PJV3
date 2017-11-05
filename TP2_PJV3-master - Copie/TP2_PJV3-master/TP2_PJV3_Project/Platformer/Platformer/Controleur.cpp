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

string Controleur::requetePolitesse(const string& salutationRecue, int& pointsPolitesse)
{
	if (salutationRecue.length() < 5 || salutationRecue.length() > 8)
	{
		pointsPolitesse = -1;
		return "Message de salutation entre 5 et 8 caractères; vous savez pas lire?";
	}

	if (salutationRecue[salutationRecue.length()-1] != '!')
	{
		pointsPolitesse = -1;
		return "Votre salutation est plutôt molle; pas vraiment sincère";
	}

	return modele.salutations(salutationRecue, pointsPolitesse);

	
}

string Controleur::requeteCalcul(string number1, string number2, string option)
{
	double num1 = 0;
	double num2 = 0;
	char nextOption = ' ';
	try
	{
		num1 = std::stod(number1);
		num2 = std::stod(number2);
	}
	catch(std::exception &e)
	{
		return "L'opération à été annulé, ce n'est pas un nombre";
	}

	if (option.length() == 1)
		nextOption = option.at(0);
	if (nextOption == '+' || nextOption == '-' || nextOption == '*' || nextOption == '/')
	{
		string resultat = std::to_string(modele.calcul(num1, num2, nextOption));
		return "Le résultat de votre opération est : " + resultat;
	}
	else
		return "L'opération à été annulé, mauvais opérateur";

}
