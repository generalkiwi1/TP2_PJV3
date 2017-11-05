#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
enum State { walking, attacking, dead, idle, jumping, falling, hit, running };
/// <summary>
/// Squelette d'une classe joueur.  Y a pas grand chose ici, mais c'est tout de m�me la sprite
/// De l'ensemble des animations qui est utilis�e.
///
///QUATRES CONSEILS IMPORTANTS:
///1- Vous aurez le choix entre animer la spriteSheet ou d'int�grer 4 sprites diff�rentes.  Dans ce cas-ci, votre 
///joueur ne devra plus h�riter de sprite
///
///2- Si vous faites plus d'un niveau, le joueur pourrait �tre port�e dans la game et pass� par r�f�rence plut�t que d�truit et cr�e � chaque niveau de jeu.
///
///3- Pour faire changer votre personnage direction, il faudra le "refl�ter dans une direction (reflet == scaling � -1)
///
///4- Si vous utilisez les sprites founis pour le joueur et que vous utilisez le cadre du Rectangle de sprite pour vos collisions, vos collisions seront probablement tr�s �loign�es.
///Votre jouuer pourrait "porter" un rectangle de collsion faisait 32 pixels de large.
///
/// </summary>
namespace platformer
{
	class Joueur : public Sprite
	{
	public:
		Joueur(State state);
		~Joueur();
		bool IsColliding(FloatRect objet);
		void move(const int directionX, const int directionY, const float multiplicateurVitesse);
		void Jump();
		State GetState();
		bool init(const int limiteGauche, const int limiteDroite, const String texturePath);
		void ResetCantMove();
		void changeIsFalling();
		void updateAnimation();
		void Attaque();
	private:

		const int NBR_COLONES = 12;  //Total de colones dans la spriteSheet
		const int NBR_LIGNES = 8;  //Total de lignes dans la spriteSheet
		const int NUM_POSITION_ANIM_IMMOBILE = 0;
		const int NUM_POSITION_ANIM_MARCHE = 1;
		const int NUM_POSITION_ANIM_COURSE = 3;
		const int NUM_POSITION_ANIM_SAUT = 5;
		const int NUM_POSITION_ANIM_DEAD = 6;
		const int NUM_POSITION_ANIM_ATTAQUE = 7;
		const int NUM_POSITION_DERNIERE_ANIM_ATTAQUE = 7;
		const int NBR_ANIMS_IMMOBILE = 5;  //Nombre de frames d'animation pour le idle dans la spriteSheet.
		const int NBR_ANIMS_MARCHE = 12;  //Nombre de frames d'animation pour la marche dans la spriteSheet.
		const int NBR_ANIMS_COURSE = 8;  //Nombre de frames d'animation pour la course dans la spriteSheet.
		const int NBR_ANIMS_SAUT = 3;  //Nombre de frames d'animation pour le saut dans la spriteSheet.
		const int NBR_ANIMS_DEAD = 2;  //Nombre de frames d'animation pour la mort dans la spriteSheet.
		const int NBR_ANIMS_ATTAQUE = 5;  //Nombre de frames d'animation pour l'attaque dans la spriteSheet.

		Texture texture;

		float vitesse = 3;
		int jumpingTime = 45;
		State state = idle;
		State previousState = idle;
		bool cantMoveLeft = false;
		bool cantMoveRight = false;
		bool isFalling = false;
		int nbFrameFromBeginAnimation = 0;

		IntRect* intRectsImmobile; //Tableau dynamique � deux dimensions pour des rectangles de d�coupage, pour les animations de "idle".  
		IntRect* intRectsMarche; //Tableau dynamique � deux dimensions pour des rectangles de d�coupage, pour les animations de marche. 
		IntRect* intRectsCourse; //Tableau dynamique � deux dimensions pour des rectangles de d�coupage, pour les animations de course. 
		IntRect* intRectsSaut; //Tableau dynamique � deux dimensions pour des rectangles de d�coupage, pour les animations de saut. 
		IntRect* intRectsDead; //Tableau dynamique � deux dimensions pour des rectangles de d�coupage, pour les animations de mort. 
		IntRect* intRectsAttaque; //Tableau dynamique � deux dimensions pour des rectangles de d�coupage, pour les animations d'attaque. 

	};
}

