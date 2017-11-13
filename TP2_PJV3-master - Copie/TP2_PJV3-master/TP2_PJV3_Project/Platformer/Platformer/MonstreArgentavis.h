#pragma once
#include "Ennemie.h"
#include "Projectile.h"

namespace platformer
{
	class MonstreArgentavis : public Ennemie
	{
	public:
		MonstreArgentavis(const int SCORE_VALUE, ActeurType ACTEUR_TYPE);
		~MonstreArgentavis();

		bool init(const String texturePath);
		const Vector2f& Shoot() const;
		
	protected:
		void UpdateAnimation();
		void FlipSpriteToRigth();
		void FlipSpriteToLeft();
		


		const int NBR_COLONES = 8;  //Total de colones dans la spriteSheet
		const int NBR_LIGNES = 3;  //Total de lignes dans la spriteSheet

		const int NUM_POSITION_ANIM_MARCHE = 0;
		const int NUM_POSITION_ANIM_ATTAQUE = 1;
		const int NUM_POSITION_ANIM_DEAD = 2;

		const int NBR_ANIMS_MARCHE = 8;  //Nombre de frames d'animation pour la marche dans la spriteSheet.
		const int NBR_ANIMS_ATTAQUE = 1;  //Nombre de frames d'animation pour l'attaque dans la spriteSheet.
		const int NBR_ANIMS_DEAD = 1;  //Nombre de frames d'animation pour la mort dans la spriteSheet.

		const int TIME_FOR_RELOADING_SHOOT = 600;

		int timeRemainingForShooting = 0;
		

		Texture texture;

		IntRect* intRectsMarche; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de marche. 
		IntRect* intRectsDead; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de mort. 
		IntRect* intRectsAttaque; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations d'attaque. 
	};
}

