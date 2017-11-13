#pragma once
#include "Ennemie.h"

namespace platformer
{
	class MonstreRaptor : public Ennemie
	{
	public:
		MonstreRaptor(const int SCORE_VALUE, ActeurType ACTEUR_TYPE);
		~MonstreRaptor();

		bool init(const String texturePath);

	protected:
		void UpdateAnimation();
		void FlipSpriteToRigth();
		void FlipSpriteToLeft();

		const int NBR_COLONES = 6;  //Total de colones dans la spriteSheet
		const int NBR_LIGNES = 4;  //Total de lignes dans la spriteSheet

		const int NUM_POSITION_ANIM_IMMOBILE = 0;
		const int NUM_POSITION_ANIM_MARCHE = 1;
		const int NUM_POSITION_ANIM_ATTAQUE = 2;
		const int NUM_POSITION_ANIM_DEAD = 3;


		const int NBR_ANIMS_IMMOBILE = 3;  //Nombre de frames d'animation pour le idle dans la spriteSheet.
		const int NBR_ANIMS_MARCHE = 6;  //Nombre de frames d'animation pour la marche dans la spriteSheet.
		const int NBR_ANIMS_ATTAQUE = 4;  //Nombre de frames d'animation pour l'attaque dans la spriteSheet.
		const int NBR_ANIMS_DEAD = 5;  //Nombre de frames d'animation pour la mort dans la spriteSheet.

		Texture texture;

		IntRect* intRectsImmobile; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de "idle".  
		IntRect* intRectsMarche; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de marche. 
		IntRect* intRectsDead; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de mort. 
		IntRect* intRectsAttaque; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations d'attaque. 
	};
}

