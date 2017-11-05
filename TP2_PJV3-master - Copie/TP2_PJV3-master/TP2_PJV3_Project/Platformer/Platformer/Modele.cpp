#include "Modele.h"

using namespace MVC;

Modele::Modele()
{
	politesses[0] = "Salut!";
	politesses[1] = "Allo!";
	politesses[2] = "Bonjour!";
}

string Modele::salutations(const string& salutationRecue, int& pointsPolitesse)
{
	for (int i = 0; i < 3; i++)
	{
		if (salutationRecue == politesses[i])
		{			
			pointsPolitesse = rand() % 10 + 1;
			return "Salutations! Vous êtes quelqu'un de très poli!";
		}
	}

	pointsPolitesse = -1;
	return "ceci n'est pas très convenable!";
}

float Modele::calcul(float num1, float num2, char option)
{
	float somme = 0;
	switch(option)
	{
	case '+':
		somme = num1 + num2;
		break;
	case '-':
		somme = num1 - num2;
		break;
	case '*':
		somme = num1 * num2;
		break;
	case '/':
		somme = num1 / num2;
		break;
	}
	return somme;
}




