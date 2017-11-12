#pragma once

#include "Acteur.h"



namespace platformer
{
	class Joueur : public Acteur
	{
	public:
		Joueur();
		~Joueur();
		
		void move(const int directionX, const int directionY, const float multiplicateurVitesse);
		void Jump();
		bool init(const String texturePath);
		
		
		void updateAnimation();

	private:

		const int NBR_COLONES = 12;  //Total de colones dans la spriteSheet
		const int NBR_LIGNES = 8;  //Total de lignes dans la spriteSheet

		const int NUM_POSITION_ANIM_IMMOBILE = 0;
		const int NUM_POSITION_ANIM_MARCHE = 1;
		const int NUM_POSITION_ANIM_COURSE = 3;
		const int NUM_POSITION_ANIM_SAUT = 5;
		const int NUM_POSITION_ANIM_DEAD = 6;
		const int NUM_POSITION_ANIM_ATTAQUE = 7;

		const int NUM_POSITION_DERNIERE_ANIM_ATTAQUE = 7; //Cette animation a une largeur variable et on se sert de cette variable pour caculer la position de l'animation.

		const int NBR_ANIMS_IMMOBILE = 5;  //Nombre de frames d'animation pour le idle dans la spriteSheet.
		const int NBR_ANIMS_MARCHE = 12;  //Nombre de frames d'animation pour la marche dans la spriteSheet.
		const int NBR_ANIMS_COURSE = 8;  //Nombre de frames d'animation pour la course dans la spriteSheet.
		const int NBR_ANIMS_SAUT = 3;  //Nombre de frames d'animation pour le saut dans la spriteSheet.
		const int NBR_ANIMS_DEAD = 2;  //Nombre de frames d'animation pour la mort dans la spriteSheet.
		const int NBR_ANIMS_ATTAQUE = 5;  //Nombre de frames d'animation pour l'attaque dans la spriteSheet.

		ActeurType ACTEUR_TYPE = player;

		Texture texture;

		int jumpingTime = 45; //Duree du saut.
			
		int nbFrameFromBeginAnimation = 0; //Compteur pour les animations.

		IntRect* intRectsImmobile; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de "idle".  
		IntRect* intRectsMarche; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de marche. 
		IntRect* intRectsCourse; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de course. 
		IntRect* intRectsSaut; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de saut. 
		IntRect* intRectsDead; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de mort. 
		IntRect* intRectsAttaque; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations d'attaque. 

	};
}

