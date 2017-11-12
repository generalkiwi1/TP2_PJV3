#include "SceneMenu.h"

using namespace platformer;

SceneMenu::SceneMenu()
{
	
}


SceneMenu::~SceneMenu()
{
	
}


Scene::scenes SceneMenu::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneMenu::init(RenderWindow * const window)
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
	for(int i = 0; i< NBBUTTONS; ++i)
	{
		buttons[i].init(480, 24, Vector2f(400,(i*50)+100), font);
		if (i == 0)
			buttons[i].insererTexte("Login");
		else if (i == 1)
			buttons[i].insererTexte("Scores");
		else if (i == 2)
			buttons[i].insererTexte("Gestion des comptes");
	}

	this->mainWin = window;
	isRunning = true;

	return true;
}

void SceneMenu::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fen�tre ne mettrait pas n�cessairement 
			//fin � l'application
			isRunning = false;
			transitionVersScene = Scene::scenes::SORTIE;
		}

		//Si on a un �v�nement de click de souris
		if (event.type == Event::MouseButtonPressed)
		{
			for (int i = 0; i < NBBUTTONS; ++i)
			{
				//Si on touche � la textbox avec la souris
				if (buttons[i].touche(Mouse::getPosition(*mainWin)))
				{
					buttons[i].selectionner();  //on l'affiche comme �tant s�lectionn�
					isRunning = false;
					transitionVersScene = (scenes)vue.staySameWindow(i+1); // + 1 pour dire qu'il y a une incr�mentation de plus, car si c'est �gal � 0, on ne change pas de fen�tre.
				}
				else
				{
					//Sinon aucun textbox actif
					//Ce else devrait �tre dans toutes vos fen�tres o� il n'y a pas de textbox.
					textboxActif = nullptr;
					buttons[i].deSelectionner();
				}
			}
		}
	}
}

void SceneMenu::update()
{
}

void SceneMenu::draw()
{
	mainWin->clear();
	mainWin->draw(ecranMenu);
	for (int i = 0; i< NBBUTTONS; ++i)
	{
		buttons[i].dessiner(mainWin);;
	}
	mainWin->display();
}