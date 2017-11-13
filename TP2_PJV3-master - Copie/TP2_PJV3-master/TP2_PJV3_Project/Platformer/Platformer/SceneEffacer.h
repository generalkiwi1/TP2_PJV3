#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

// Mika - 1640194


using namespace sf;

namespace platformer
{
	class SceneEffacer : public Scene
	{
	public:
		SceneEffacer();
		~SceneEffacer();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		static const int NBBUTTONS = 4;
		//L'écran titre est super arbitraire, vous pouvez en trouver un autre si vous voulez.
		Texture ecranMenuT;
		Textbox textboxErreur; // Ce textbox agit plutôt comme un messagebox.
		Sprite ecranMenu;

		Textbox buttons[NBBUTTONS];
		Font font;

		//Nécessaire car on ne peut pas que le code ascii que Enter et Backspace ne soit jamais saisie
		bool backspaceActif = false;
		bool enterActif = false;

		//Ne fait pas beaucoup sens à un Textbox, mais à plusieurs, ça le fera.
		Textbox* textboxActif = nullptr;
	};
}
