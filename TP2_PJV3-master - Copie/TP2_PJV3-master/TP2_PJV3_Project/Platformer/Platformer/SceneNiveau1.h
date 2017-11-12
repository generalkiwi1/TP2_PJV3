#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Joueur.h"
#include "MonstreStego.h"
#include "MonstreRaptor.h"
#include "MonstreArgentavis.h"

using namespace sf;


namespace platformer
{
	class SceneNiveau1 : public Scene
	{
	public:
		SceneNiveau1();
		~SceneNiveau1();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		// Constantes du monde
		const int SCREEN_WIDTH = 800;
		const int SCREEN_HEIGHT = 480;
		const int WORLD_WIDTH = 4000;
		const int WORLD_HEIGHT = 480;
		
		const int MIN_VIEW_X = SCREEN_WIDTH / 2;
		const int MAX_VIEW_X = WORLD_WIDTH - MIN_VIEW_X;
		
			
		static const int NOMBRE_TUILES_X = 100;
		static const int NOMBRE_TUILES_Y = 15;
		static const int TAILLE_TUILES_X = 40;
		static const int TAILLE_TUILES_Y = 32;
		static const int TUILES_ROUGES = 7;
		static const int BACKGROUNDS = 3;
		static const int FOODS = 4;
		static const int FOODS_SIZE_X = 25;
		static const int FOODS_SIZE_Y = 34;
		static const int ENNEMIES = 3;
		static const int ENNEMY_0_WIDTH = 150;
		static const int ENNEMY_0_HEIGHT = 95;
		static const int ENNEMY_1_WIDTH = 225;
		static const int ENNEMY_1_HEIGHT = 115;
		static const int ENNEMY_2_WIDTH = 75;
		static const int ENNEMY_2_HEIGHT = 85;
		static const int NB_ENNEMY_MAX = 20;
		static const int NB_BOUFFE_MAX = 50;
		static const int NB_MAX_EXIT = 1;
		static const int WIN_SCORE_VALUE = 1000;
		static const int FOOB_SCORE_VALUE = 25;
		static const int TIME_MAX_TO_FINISH = 3600;

		int timer = 0;
		bool haveWin = false;
		int score = 0;

		/// <summary>
		/// Th�oriquement la fen�tre pourrait �tre remplie de tuile de mani�re exacte (20 X 15 pour �tre pr�cis, voir plus haut)
		/// On a donc une grille de pointeurs null, et si un bloc doit �tre conc�tis�, alors il ne sera pas null.
		/// </summary>
		Sprite* grilleDeTuiles[NOMBRE_TUILES_X][NOMBRE_TUILES_Y];
		Sprite* grilleCollectibles[NB_BOUFFE_MAX];
		Sprite* exit;

		/// <summary>
		/// On a 7 tuiles rouges de base; alors on va toutes les utiliser, pour le moment.
		/// </summary>
		Texture tuilesRougesT[TUILES_ROUGES];
		
		/// <summary>
		/// Trois backgrounds superpos�s pour le plus bel effet visuel
		/// </summary>
		Texture backgroundT[BACKGROUNDS];
		Sprite background[BACKGROUNDS];
		Vector2f backgroundPositions[5];
		
		Texture foodT[FOODS];
		
		Texture exitT;
		
		Texture plateformeT;
		
		Joueur * joueur;
		Ennemie * ennemies[NB_ENNEMY_MAX];
		int interfaceCommande;
		View view;
		
		void adjustView();
		
		
	};
}