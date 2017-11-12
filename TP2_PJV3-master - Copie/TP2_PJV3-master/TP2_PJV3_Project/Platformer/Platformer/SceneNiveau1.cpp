#include "SceneNiveau1.h"

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace platformer;

SceneNiveau1::SceneNiveau1()
{
	for (int x=0; x < NOMBRE_TUILES_X; x++)
		for (int y = 0; y < NOMBRE_TUILES_Y; y++)
		{
			grilleDeTuiles[x][y] = nullptr;
		}

	for (size_t i = 0; i < NB_BOUFFE_MAX; i++)
	{
		grilleCollectibles[i] = nullptr;
	}
		view = View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
		view.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

SceneNiveau1::~SceneNiveau1()
{
	for (int x = 0; x < NOMBRE_TUILES_X; x++)
		for (int y = 0; y < NOMBRE_TUILES_Y; y++)
		{
			if (grilleDeTuiles[x][y] != nullptr)
			{
				delete grilleDeTuiles[x][y];
			}
		}
	for (size_t i = 0; i < NB_ENNEMY_MAX; i++)
	{	
			delete ennemies[i];
	}
	for (size_t i = 0; i < NB_BOUFFE_MAX; i++)
	{
		delete grilleCollectibles[i];
	}
	delete exit;
	delete joueur;
}

Scene::scenes SceneNiveau1::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneNiveau1::init(RenderWindow * const window)
{
	for (size_t i = 0; i < NB_ENNEMY_MAX; i++)
	{
		ennemies[i] = nullptr;
	}
	// Chargement des sprites pour les tuiles
	for (int i = 0; i < TUILES_ROUGES; i++)
	{
		if (!tuilesRougesT[i].loadFromFile("Ressources\\Tiles\\BlockA" + std::to_string(i) + ".png"))
		{
			return false;
		}
	}

	// Chargement des sprites pour les plateformes
	if (!plateformeT.loadFromFile("Ressources\\Tiles\\Platform.png"))
		 {
		return false;
		}
	
		// Chargement des sprites pour la sortie
		if (!exitT.loadFromFile("Ressources\\Tiles\\Exit.png"))
		{
			return false;
		}
	
		// Chargement de l'arrière plan
	for (int i = 0; i < BACKGROUNDS; i++)
	{
		if (!backgroundT[i].loadFromFile("Ressources\\Backgrounds\\Layer" + std::to_string(i) + "_1.png"))
		{
			return false;
		}
	}

	// Chargement de la nourriture
	for (int i = 0; i < FOODS; ++i)
		{
		if (!foodT[i].loadFromFile("Ressources\\Sprites\\Food\\food" + std::to_string(i) + ".png"))
			{
			return false;
			}
		}

	// Chargement du joueur
	joueur = new Joueur();
	if (!joueur->init("Ressources\\Sprites\\Player\\player_30x35.png"))
	{
		return false;
	}
	
	// Mise en place de l'arrière plan
	for (int i = 0; i < BACKGROUNDS; i++)
	{
		background[i].setTexture(backgroundT[i]);
	}

	srand(time(NULL));
	for (int i = 0; i < 5; i++) // Création de plusieurs background
	{
				//Choix du bloc au hasard
		backgroundPositions[i].x = i * SCREEN_WIDTH;
	    backgroundPositions[i].y = 0;
	}

	// On charge un niveau à partir d'un fichier .txt
		{
		int m = 0;
		int b = 0;
		int e = 0;
		ifstream readLevel("Ressources\\Level\\niveau_DinoRush.txt"); // Lecture d'un niveau par fichier texte
		string currentLine; // Ligne courante
		int levelLine = 0; // Indique à quel niveau du tableau on est rendu.
		while (getline(readLevel, currentLine))
			 {
			 if ((int)currentLine.at(0) != 35)
				{
				 
				 for (int i = 0; i < currentLine.length(); ++i)
				 {

					 int currentNumber = (int)currentLine.at(i);
					 switch (currentNumber)
					 {
					 case 49: // Joueur
						 grilleDeTuiles[i][levelLine] = nullptr;
						 joueur->setPosition((i * TAILLE_TUILES_X), (levelLine * TAILLE_TUILES_Y) + 35 / 2); // 35 == hauteur de la sprite. /2 car origine au milieu
						 break;
					 case 50: // Sol
						 grilleDeTuiles[i][levelLine] = new Sprite(tuilesRougesT[rand() % TUILES_ROUGES]);
						 grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, levelLine* TAILLE_TUILES_Y);
						 break;
					 case 51: // Plateforme
						 grilleDeTuiles[i][levelLine] = new Sprite(plateformeT);
						 grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, levelLine* TAILLE_TUILES_Y);
						 break;
					 case 52: // Ennemi 0
						 if (m < NB_ENNEMY_MAX)
						 {
							 ennemies[m] = new MonstreRaptor(50);
							 if (!ennemies[m]->init("Ressources\\Sprites\\Monster" + std::to_string(0) + "\\Monster" + std::to_string(0) + ".png"))
							 {
								 return false;
							 }
							 ennemies[m]->setPosition(i * TAILLE_TUILES_X, (levelLine + 1)* TAILLE_TUILES_Y - (ENNEMY_0_HEIGHT / 2));
							 ++m;
						 }						 
						 break;
					 case 53: // Ennemi 1
						 if (m < NB_ENNEMY_MAX)
						 {
							 ennemies[m] = new MonstreStego(100);
							 if (!ennemies[m]->init("Ressources\\Sprites\\Monster" + std::to_string(1) + "\\Monster" + std::to_string(1) + ".png"))
							 {
								 return false;
							 }
							 ennemies[m]->setPosition(i * TAILLE_TUILES_X, (levelLine + 1)* TAILLE_TUILES_Y - 10 /*- ENNEMY_1_HEIGHT*/);
							 ++m;
						 }
						 break;
					 case 54: // Ennemi 2
						 if (m < NB_ENNEMY_MAX)
						 {
							 ennemies[m] = new MonstreArgentavis(75);
							 if (!ennemies[m]->init("Ressources\\Sprites\\Monster" + std::to_string(2) + "\\Monster" + std::to_string(2) + ".png"))
							 {
								 return false;
							 }
							 ennemies[m]->setPosition(i * TAILLE_TUILES_X, (levelLine + 1)* TAILLE_TUILES_Y - 10 /*- ENNEMY_2_HEIGHT*/);
							 ++m;
						 }
						 break;
					 case 55: // Bouffe
						 if (b < NB_BOUFFE_MAX)
						 {
							 grilleCollectibles[b] = new Sprite(foodT[rand() % FOODS]);
							 grilleCollectibles[b]->setPosition((i * TAILLE_TUILES_X), ((levelLine + 1) * TAILLE_TUILES_Y) - FOODS_SIZE_Y);
							 ++b;
						 }
						 break;
					 case 56: // Sortie
						 if (e < NB_MAX_EXIT)
						 {
							 exit = new Sprite(exitT);
							 exit->setPosition(i * TAILLE_TUILES_X, levelLine* TAILLE_TUILES_Y);
							 ++e;
						 }		 
						 break;
					 default:
						 break;
					 }
				 }
			levelLine++;
				}
			}
		}

	this->mainWin = window;
	isRunning = true;
	
	return true;
}

void SceneNiveau1::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fenêtre ne mettrait pas nécessairement 
			//fin à l'application
			isRunning = false;
			transitionVersScene = (scenes)vue.staySameWindow(8); // Sortie du jeu
		}

		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				view.move(-10000, 0); // On remet la vue au début
				adjustView();
				mainWin->setView(view);
				isRunning = false;
				transitionVersScene = (scenes)vue.staySameWindow(0); // + 1 pour dire qu'il y a une incrémentation de plus, car si c'est égal à 0, on ne change pas de fenêtre.
			}
		}
	}

	interfaceCommande = 0;

	//Méthode binaire: appuyer à gauche et à droite sumultanément va donner 3, et le personnage ne se dépalcera alors pas.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		interfaceCommande |= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		interfaceCommande |= 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		interfaceCommande |= 3;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
	{
		interfaceCommande |= 4;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
	{
		interfaceCommande |= 5;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		interfaceCommande |= 6;
	}

}

void SceneNiveau1::update()
{

	if (joueur->IsColliding(exit->getGlobalBounds()))
	{
		score += WIN_SCORE_VALUE;
		haveWin = true;
		isRunning = false;
	}
	if (joueur->GetState() != attacking)
	{
		joueur->ResetCantMove();

		for (int i = 0; i < NOMBRE_TUILES_X; ++i)
		{
			for (int j = 0; j < NOMBRE_TUILES_Y; ++j)
			{
				if (grilleDeTuiles[i][j] != nullptr)
				{
					joueur->IsColliding(grilleDeTuiles[i][j]->getGlobalBounds());
				}
			}
		}
		if (joueur->GetState() != jumping)
		{
			joueur->changeIsFalling();
		}
	}

	if (joueur->GetState() == attacking)
	{
		joueur->Attack();
	}
	else if (interfaceCommande == 0 && (joueur->GetState() == walking || joueur->GetState() == running))
	{
		joueur->move(0, 0, 0);
	}
	else if (interfaceCommande == 1)
	{
		joueur->move(-1, 0, 1);
		if (joueur->getPosition().x <= view.getCenter().x)
			view.move(-3, 0);
		adjustView();
	}
	else if (interfaceCommande == 2)
	{
		joueur->move(1, 0, 1);
		if (joueur->getPosition().x >= view.getCenter().x)
			view.move(3, 0);
		adjustView();
	}
	else if (interfaceCommande == 3 && (joueur->GetState() == walking || joueur->GetState() == idle || joueur->GetState() == running))
	{
		joueur->Jump();
	}
	else if (interfaceCommande == 4 && (joueur->GetState() == walking || joueur->GetState() == idle || joueur->GetState() == running))
	{
		joueur->move(-1, 0, 2);
	}
	else if (interfaceCommande == 5 && (joueur->GetState() == walking || joueur->GetState() == idle || joueur->GetState() == running))
	{
		joueur->move(1, 0, 2);
	}
	else if (interfaceCommande == 6 && (joueur->GetState() == walking || joueur->GetState() == idle || joueur->GetState() == running))
	{
		joueur->Attack();
	}

	if (joueur->GetState() == jumping)
	{
		joueur->Jump();
	}
	if (joueur->GetState() == falling)
	{
		joueur->move(0, 1, 1);
	}
	joueur->updateAnimation();

	for (size_t i = 0; i < NB_ENNEMY_MAX; i++)
	{
		if (ennemies[i] != nullptr)
		{
			if (ennemies[i]->GetState() != attacking)
			{
				ennemies[i]->ResetCantMove();

				for (int x = 0; x < NOMBRE_TUILES_X; ++x)
				{
					for (int y = 0; y < NOMBRE_TUILES_Y; ++y)
					{
						if (grilleDeTuiles[x][y] != nullptr)
						{
							ennemies[i]->IsColliding(grilleDeTuiles[x][y]->getGlobalBounds());
						}
					}
				}
			}
			ennemies[i]->Update();
		}
	}
	
	for (size_t i = 0; i < NB_ENNEMY_MAX; i++)
	{
		if (ennemies[i] != nullptr)
		{			
			if (joueur->IsColliding(ennemies[i]->getGlobalBounds()))
			{
				if (joueur->GetState() == attacking )
				{
					score += ennemies[i]->GetScore();
					delete ennemies[i];
					ennemies[i] = nullptr;
				}
				else if (joueur->GetState() == falling && ennemies[i]->GetActeurType() != stego)
				{
					score += ennemies[i]->GetScore();
					delete ennemies[i];
					ennemies[i] = nullptr;

					if (joueur->GetState() == falling)
					{
						joueur->Jump();
					}
				}
				else
				{
					joueur->setPosition((i * TAILLE_TUILES_X), (13 * TAILLE_TUILES_Y) + 35 / 2);
					//isRunning = false;
				}
			}
		}
	}
	for (size_t i = 0; i < NB_BOUFFE_MAX; i++)
	{
		if (grilleCollectibles[i] != nullptr)
		{
			if (joueur->IsColliding(grilleCollectibles[i]->getGlobalBounds()))
			{
				score += FOOB_SCORE_VALUE;
				delete grilleCollectibles[i];
				grilleCollectibles[i] = nullptr;
					
			}
		}
	}
	if (timer > TIME_MAX_TO_FINISH)
	{
		isRunning = false;
	}
	//++timer;
}
void SceneNiveau1::draw()
{
	mainWin->clear();
	mainWin->setView(view);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < BACKGROUNDS; ++j)
		{
			background[j].setPosition(backgroundPositions[i]);
			mainWin->draw(background[j]);
		}
	}

	for (int x = 0; x < NOMBRE_TUILES_X; x++)
		for (int y = 0; y < NOMBRE_TUILES_Y; y++)
		{
			if (grilleDeTuiles[x][y] != nullptr)
			{
				mainWin->draw(*grilleDeTuiles[x][y]);
			}
		}

	mainWin->draw(*exit);
	
	for (int x = 0; x < NB_BOUFFE_MAX; x++)
	{
		if (grilleCollectibles[x] != nullptr)
		{
			mainWin->draw(*grilleCollectibles[x]);
		}
	}
	for (int x = 0; x < NB_ENNEMY_MAX; x++)
	{
			if (ennemies[x] != nullptr)
			{
				mainWin->draw(*ennemies[x]);
			}
	}

	mainWin->draw(*joueur);
	mainWin->display();
}

void SceneNiveau1::adjustView()
{
	if (view.getCenter().x < MIN_VIEW_X)
	{
		view.setCenter(MIN_VIEW_X, view.getCenter().y);
	}
	else if (view.getCenter().x > MAX_VIEW_X)
	{
		view.setCenter(MAX_VIEW_X, view.getCenter().y);
	}
}


