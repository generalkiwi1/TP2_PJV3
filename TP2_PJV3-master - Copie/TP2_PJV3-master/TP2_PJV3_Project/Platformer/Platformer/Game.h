#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace platformer
{	
	/// <summary>
	/// Nouvelle version de la classe game.  � pr�sent elle sera surtout charg�e de charger les diff�rentes sc�nes
	/// testTest est toujours pr�sent pour que vous puissez faire le lien avec les test unitaires
	/// </summary>
	class Game
	{
	public:
		Game();
		int run();
		int testTest();
		View view;

	private:
		// Constantes du monde
		const int SCREEN_WIDTH = 800;
		const int SCREEN_HEIGHT = 480;

		const int WORLD_WIDTH = 4000;
		const int WORLD_HEIGHT = 480;


		bool init();

		RenderWindow mainWin;
		Event event;

	};
}