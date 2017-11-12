#include "Game.h"
#include "SceneTitre.h"
#include "SceneNiveau1.h"
#include "SceneMenu.h"
#include "SceneGestion.h"
#include "SceneLogin.h"
#include "SceneMeilleurScore.h"
#include "SceneCreer.h"
#include "SceneModifier.h"
#include "SceneEffacer.h"

using namespace platformer;

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Platformer");  // , Style::Titlebar); / , Style::FullScreen);
	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
}

int Game::testTest()
{
	return 0;
}

int Game::run()
{
	//deux enums et un pointeur de scene pour faire la manipulation de scène
	Scene::scenes selecteurDeScene = Scene::scenes::MENU;
	Scene::scenes sceneEnRetour;
	Scene* sceneActive = nullptr; //Pointeur de la super-classe, peut pointer sur n'imprte quelle scène

	while (true)
	{
		//Seule condition de sortie de toute l'app
		if (selecteurDeScene == Scene::scenes::SORTIE)
		{
			return EXIT_SUCCESS;
		}
		else			
		{
			//Vous allez ajouter d'autre scènes, alors elles devront
			//être ajoutées ici
			switch (selecteurDeScene)
			{
			case Scene::scenes::MENU:
				sceneActive = new SceneMenu();
				break;
			case Scene::scenes::LOGIN:
				sceneActive = new SceneLogin();
				break;
			case Scene::scenes::MEILLEURS_SCORES:
				sceneActive = new SceneMeilleurScore();
				break;
			case Scene::scenes::GESTION:
				sceneActive = new SceneGestion();
				break;
			case Scene::scenes::CREER:
				sceneActive = new SceneCreer();
				break;
			case Scene::scenes::MODIFIER:
				sceneActive = new SceneModifier();
				break;
			case Scene::scenes::EFFACER:
				sceneActive = new SceneEffacer();
				break;
			case Scene::scenes::NIVEAU1:
				sceneActive = new SceneNiveau1();
				break;
			}
			
			if (sceneActive->init(&mainWin))
			{
				sceneEnRetour = sceneActive->run();
				//À la fin d'une scène, s'il y a des sauvegardes à faire
				//C'est aussi possible de les faire là.
			}
			else
			{
				//cleap-up à faire pour s'assurer  de ne pas avoir de leak
				//(malgré l'échec)
				return EXIT_FAILURE;
			}			
		}

		selecteurDeScene = sceneEnRetour;
		delete sceneActive;
		sceneActive = nullptr;
	}
}

bool Game::init()
{
	return true;
}
