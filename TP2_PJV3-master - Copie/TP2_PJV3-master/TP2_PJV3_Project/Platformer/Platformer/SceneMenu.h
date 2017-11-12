#pragma once
//class SceneMenu
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"


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
		//L'�cran titre est super arbitraire, vous pouvez en trouver un autre si vous voulez.
		Texture ecranMenuT;
		Sprite ecranMenu;

		Textbox buttons[NBBUTTONS];
		Font font;

		//Ne fait pas beaucoup sens � un Textbox, mais � plusieurs, �a le fera.
		Textbox* textboxActif = nullptr;
	};
}