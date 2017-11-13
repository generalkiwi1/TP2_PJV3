#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

// Mika - 1640194

using namespace sf;

namespace platformer
{
	class SceneCreer : public Scene
	{
	public:
		SceneCreer();
		~SceneCreer();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		static const int NBBUTTONS = 7;
		static const int NBBUTTONMODIFIABLE = 5;
		//L'�cran titre est super arbitraire, vous pouvez en trouver un autre si vous voulez.
		Texture ecranMenuT;
		Sprite ecranMenu;

		Textbox buttons[NBBUTTONS];
		Textbox textboxErreur; // Ce textbox agit plut�t comme un messagebox.
		Font font;

		//N�cessaire car on ne peut pas que le code ascii que Enter et Backspace ne soit jamais saisie
		bool backspaceActif = false;
		bool enterActif = false;

		//Ne fait pas beaucoup sens � un Textbox, mais � plusieurs, �a le fera.
		Textbox* textboxActif = nullptr;
	};
}