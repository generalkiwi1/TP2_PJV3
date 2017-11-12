#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"


using namespace sf;

namespace platformer
{
	class SceneModifier : public Scene
	{
	public:
		SceneModifier();
		~SceneModifier();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		static const int NBBUTTONS = 7;
		//L'écran titre est super arbitraire, vous pouvez en trouver un autre si vous voulez.
		Texture ecranMenuT;
		Sprite ecranMenu;

		Textbox buttons[NBBUTTONS];
		Font font;

		//Ne fait pas beaucoup sens à un Textbox, mais à plusieurs, ça le fera.
		Textbox* textboxActif = nullptr;
	};
}