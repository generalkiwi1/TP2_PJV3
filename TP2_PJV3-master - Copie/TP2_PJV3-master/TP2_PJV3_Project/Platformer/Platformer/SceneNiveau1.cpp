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
	joueur = new Joueur(idle);
	if (!joueur->init(TAILLE_TUILES_X, WORLD_WIDTH-TAILLE_TUILES_X, "Ressources\\Sprites\\Player\\player_30x35.png"))
	{
		return false;
	}

	// Chargement des ennemis
	for (int i = 0; i < ENNEMIES; i++)
	{
		if (!ennemiesT[i].loadFromFile("Ressources\\Sprites\\Monster" + std::to_string(i) + "\\Monster"+ std::to_string(i) + ".png"))
		{
			return false;
		}
	}

	// Mise en place de l'arrière plan
	for (int i = 0; i < BACKGROUNDS; i++)
	{
		background[i].setTexture(backgroundT[i]);
	}

	for (int i = 0; i < 5; i++) // Création de plusieurs background
	{
		backgroundPositions[i].x = i * SCREEN_WIDTH;
		backgroundPositions[i].y = 0;
	}


	srand(time(NULL));
	// On charge un niveau à partir d'un fichier .txt
	{
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
						joueur->setPosition((i * TAILLE_TUILES_X), (levelLine * TAILLE_TUILES_Y)+35/2); // 35 == hauteur de la sprite. /2 car origine au milieu
						break;
					case 50: // Sol
						grilleDeTuiles[i][levelLine] = new Sprite(tuilesRougesT[rand() % TUILES_ROUGES]);
						grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, levelLine* TAILLE_TUILES_Y);
						break;
					case 51: // Plateforme
						grilleDeTuiles[i][levelLine] = new Sprite(plateformeT);
						grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, levelLine* TAILLE_TUILES_Y);
						break;
					case 52: // Ennemi 1
						grilleDeTuiles[i][levelLine] = nullptr;
						grilleDeTuiles[i][levelLine] = new Sprite(ennemiesT[0]);
						grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, (levelLine + 1)* TAILLE_TUILES_Y - ENNEMY_0_HEIGHT);
						break;
					case 53: // Ennemi 2
						grilleDeTuiles[i][levelLine] = nullptr;
						grilleDeTuiles[i][levelLine] = new Sprite(ennemiesT[1]);
						grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, (levelLine + 1)* TAILLE_TUILES_Y - ENNEMY_1_HEIGHT);
						break;
					case 54: // Ennemi 3
						grilleDeTuiles[i][levelLine] = nullptr;
						grilleDeTuiles[i][levelLine] = new Sprite(ennemiesT[2]);
						grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, (levelLine + 1)* TAILLE_TUILES_Y - ENNEMY_2_HEIGHT);
						break;
					case 55: // Bouffe
						grilleDeTuiles[i][levelLine] = new Sprite(foodT[rand() % FOODS]);
						grilleDeTuiles[i][levelLine] ->setPosition((i * TAILLE_TUILES_X), ((levelLine+1) * TAILLE_TUILES_Y)-FOODS_SIZE_Y);
						break;
					case 56: // Sortie
						grilleDeTuiles[i][levelLine] = new Sprite(exitT);
						grilleDeTuiles[i][levelLine]->setPosition(i * TAILLE_TUILES_X, levelLine* TAILLE_TUILES_Y);
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
			transitionVersScene = Scene::scenes::SORTIE;
		}

		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				view.move(-10000, 0); // On remet la vue au début
				adjustView();
				mainWin->setView(view);
				isRunning = false;
				transitionVersScene = Scene::scenes::TITRE;
			}
		}
	}

	interfaceCommande = 0;

	//Méthode binaire: appuyer à gauche et à droite sumultanément va donner 3, et le personnage ne se dépalcera alors pas.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		interfaceCommande |= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		interfaceCommande |= 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		interfaceCommande |= 3;
	}

}

void SceneNiveau1::update()
{
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
	if (interfaceCommande == 1)
	{
		joueur->move(-1, 0);
		if (joueur->getPosition().x <= view.getCenter().x)
		view.move(-3,0);
		adjustView();
	}
	else if(interfaceCommande == 2)
	{
		joueur->move(1, 0);
		if (joueur->getPosition().x >= view.getCenter().x)
			view.move(3,0);
		adjustView();
	}
	
	if (joueur->GetState() == jumping)
	{
		joueur->Jump();
	}
	else if (interfaceCommande == 3 && (joueur->GetState() == walking || joueur->GetState() == idle))
	{
		joueur->Jump();
	}
	if (joueur->GetState() == falling)
	{
		joueur->move(0, 1);
	}
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

