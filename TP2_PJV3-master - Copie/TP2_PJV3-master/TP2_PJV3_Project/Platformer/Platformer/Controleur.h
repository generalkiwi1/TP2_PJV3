#pragma once
#include <string>
#include "Modele.h"

using std::string;

namespace MVC
{
	class Controleur
	{
	public:
		static Controleur *getInstance();
		static void release();

		//Pour le contrôleur, on utilise souvent requete (request)
		//et le nom de la méthode qu'on veut utiliser du côté du modèle.
		string requetePolitesse(const string& salutationRecue, int& pointsPolitesse);
		string requeteCalcul(string num1, string num2, string option);

	private:
		Controleur();
		static Controleur *instance;

		Controleur(const Controleur&);
		void operator=(const Controleur&);

		//Le contrôleur peut instancier les éléments de la couche modèle, puisque c'est le seul qui est sensé y avoir accès.
		//S'il ne les instancie pas, alors il aura des pointeurs vers les classes
		Modele modele;
	};
}

