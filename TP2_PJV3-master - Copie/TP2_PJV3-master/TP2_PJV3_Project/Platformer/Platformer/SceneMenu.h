#pragma once
//class SceneMenu
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

// Mika - 1640194

using namespace sf;

namespace platformer
{
	class SceneMenu : public Scene
	{
	public:
		SceneMenu();
		~SceneMenu();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		static const int NBBUTTONS = 3;
		//L'écran titre est super arbitraire, vous pouvez en trouver un autre si vous voulez.
		Texture ecranMenuT;
		Sprite ecranMenu;

		Textbox buttons[NBBUTTONS];
		Font font;

		//Ne fait pas beaucoup sens à un Textbox, mais à plusieurs, ça le fera.
		Textbox* textboxActif = nullptr;
	};
}