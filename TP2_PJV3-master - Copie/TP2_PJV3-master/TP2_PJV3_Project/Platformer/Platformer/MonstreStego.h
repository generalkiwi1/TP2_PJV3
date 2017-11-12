#pragma once
#include "Ennemie.h"

namespace platformer
{
	class MonstreStego : public Ennemie
	{
	public:
		MonstreStego(const int SCORE_VALUE);
		~MonstreStego();

		bool init(const String texturePath);

	protected:
		void UpdateAnimation();
		void FlipSpriteToRigth();
		void FlipSpriteToLeft();

		const int NBR_COLONES = 12;  //Total de colones dans la spriteSheet
		const int NBR_LIGNES = 2;  //Total de lignes dans la spriteSheet


		const int NUM_POSITION_ANIM_MARCHE = 0;
		const int NUM_POSITION_ANIM_DEAD = 1;

		const int NBR_ANIMS_MARCHE = 12;  //Nombre de frames d'animation pour la marche dans la spriteSheet.
		const int NBR_ANIMS_DEAD = 1;  //Nombre de frames d'animation pour la mort dans la spriteSheet.
		
		ActeurType ACTEUR_TYPE = stego;

		Texture texture;

		int nbFrameFromBeginAnimation = 0; //Compteur pour les animations.

		IntRect* intRectsMarche; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de marche. 
		IntRect* intRectsDead; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de mort. 
		
	};
}

