#include "SceneEffacer.h"

using namespace platformer;


SceneEffacer::SceneEffacer()
{

}


SceneEffacer::~SceneEffacer()
{

}

Scene::scenes SceneEffacer::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneEffacer::init(RenderWindow * const window)
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
	//par rapport au fond d'écran
	for (int i = 0; i< NBBUTTONS; ++i)
	{
		buttons[i].init(480, 24, Vector2f(400, (i * 50) + 100), font);
		if (i == 0)
			buttons[i].insererTexte("Pseudo");
		else if (i == 1)
			buttons[i].insererTexte("Mot de passe");
		else if (i == 2)
			buttons[i].insererTexte("Valider");
		else if (i == 3)
			buttons[i].insererTexte("Retour");
	}

	this->mainWin = window;
	isRunning = true;

	return true;
}

void SceneEffacer::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fenêtre ne mettrait pas nécessairement 
			//fin à l'application
			isRunning = false;
			transitionVersScene = (scenes)vue.staySameWindow(8);
		}

		//Si on a un événement de click de souris
		if (event.type == Event::MouseButtonPressed)
		{
			for (int i = 0; i < NBBUTTONS; ++i)
			{
				//Si on touche à la textbox avec la souris
				if (buttons[i].touche(Mouse::getPosition(*mainWin)))
				{
					buttons[i].selectionner();  //on l'affiche comme étant sélectionné
					isRunning = false;
					transitionVersScene = (scenes)vue.staySameWindow(i + 1); // + 1 pour dire qu'il y a une incrémentation de plus, car si c'est égal à 0, on ne change pas de fenêtre.
				}
				else
				{
					//Sinon aucun textbox actif
					//Ce else devrait être dans toutes vos fenêtres où il n'y a pas de textbox.
					textboxActif = nullptr;
					buttons[i].deSelectionner();
				}
			}
		}
	}
}

void SceneEffacer::update()
{
}

void SceneEffacer::draw()
{
	mainWin->clear();
	mainWin->draw(ecranMenu);
	for (int i = 0; i< NBBUTTONS; ++i)
	{
		buttons[i].dessiner(mainWin);;
	}
	mainWin->display();
}