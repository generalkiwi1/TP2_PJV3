#include "SceneCreer.h"

using namespace platformer;

// Mika - 1640194

SceneCreer::SceneCreer()
{

}


SceneCreer::~SceneCreer()
{

}

Scene::scenes SceneCreer::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneCreer::init(RenderWindow * const window)
{
	if (!ecranMenuT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranMenu.setTexture(ecranMenuT);

	//Les positions sont arbitraires, obtenus par essai et erreur.
	//par rapport au fond d'�cran
	textboxErreur.initInfo(Vector2f(400, 50), font, true);
	textboxErreur.insererTexte("Suit les consignes!");
	for (int i = 0; i< NBBUTTONS; ++i)
	{
		buttons[i].init(480, 24, Vector2f(400, (i * 50) + 100), font);
		if (i == 0)
			buttons[i].insererTexte("Pseudo");
		else if (i == 1)
			buttons[i].insererTexte("Mot de passe");
		else if (i == 2)
			buttons[i].insererTexte("Nom");
		else if (i == 3)
			buttons[i].insererTexte("Pr�nom");
		else if (i == 4)
			buttons[i].insererTexte("Couriel");
		else if (i == 5)
			buttons[i].insererTexte("Valider");
		else if (i == 6)
			buttons[i].insererTexte("Retour");
	}

	this->mainWin = window;
	isRunning = true;

	return true;
}

void SceneCreer::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fen�tre ne mettrait pas n�cessairement 
			//fin � l'application
			isRunning = false;
			transitionVersScene = (scenes)vue.staySameWindow(8);
		}

		//Si on a un �v�nement de click de souris
		if (event.type == Event::MouseButtonPressed)
		{
			for (int i = 0; i < NBBUTTONS; ++i)
			{
				//Si on touche � la textbox avec la souris
				if (buttons[i].touche(Mouse::getPosition(*mainWin)))
				{
					textboxActif = &buttons[i];
					buttons[i].insererTexte(""); // Efface le contenu pour le joueur
					buttons[i].selectionner();  //on l'affiche comme �tant s�lectionn�

					 // + 1 pour dire qu'il y a une incr�mentation de plus, car si c'est �gal � 0, on ne change pas de fen�tre.
					if (i == 5)
					{
						textboxActif = nullptr; // D�sactivation pour �viter les probl�me de collision entre celle active et celle qu'on veut activer
						transitionVersScene = (scenes)vue.staySameWindow(i + 1);
						isRunning = false;
						vue.confirmEnterredDataCreate(buttons[0].getTexte(), buttons[1].getTexte(), buttons[2].getTexte(), buttons[3].getTexte(), buttons[4].getTexte());
					}
					if (i == 6)
					{
						transitionVersScene = (scenes)vue.staySameWindow(i + 1);
						isRunning = false;
					}
				}
				else
				{
					//Ce else devrait �tre dans toutes vos fen�tres o� il n'y a pas de textbox.
					buttons[i].deSelectionner();
				}
			}
		}

		//Un �v�nement de touche de clavier AVEC un textobx actif
		if (event.type == Event::KeyPressed && textboxActif != nullptr)
		{
			if (event.key.code == Keyboard::BackSpace)
			{
				textboxActif->retirerChar();
				backspaceActif = true;  //Pour s'assurer que backspace n'est pas saisie comme caract�re
			}
		}

		//Attention : TextEntered est diff�rent de KeyPressed
		if (!backspaceActif && !enterActif && textboxActif != nullptr && (event.type == Event::TextEntered))
		{
			if (event.text.unicode < 128) //Travailler en unicode n'est pas simple en C++; on peut vivre avec du simple
			{                             //ascii pour ce tp (libre � vous d'aller plus loin si vous voulez)
				textboxActif->ajouterChar((char)event.text.unicode);
			}
		}
	}

	//Dans tous les cas on netoie ces conditions apr�s chaque boucle.
	enterActif = false;
	backspaceActif = false;
}

void SceneCreer::update()
{
}

// Dessin des figures
void SceneCreer::draw()
{
	mainWin->clear();
	mainWin->draw(ecranMenu);
	for (int i = 0; i< NBBUTTONS; ++i)
	{
		buttons[i].dessiner(mainWin);;
	}
	if (vue.lastDataInvalidCreate())
		textboxErreur.dessiner(mainWin);
	else
	{
		textboxErreur.insererTexte("");
		textboxErreur.dessiner(mainWin);
	}

	mainWin->display();
}