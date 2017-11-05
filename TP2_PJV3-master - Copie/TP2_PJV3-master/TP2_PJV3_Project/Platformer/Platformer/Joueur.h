#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
enum State { walking, attacking, dead, idle, jumping, falling, hit, running };
/// <summary>
/// Squelette d'une classe joueur.  Y a pas grand chose ici, mais c'est tout de même la sprite
/// De l'ensemble des animations qui est utilisée.
///
///QUATRES CONSEILS IMPORTANTS:
///1- Vous aurez le choix entre animer la spriteSheet ou d'intégrer 4 sprites différentes.  Dans ce cas-ci, votre 
///joueur ne devra plus hériter de sprite
///
///2- Si vous faites plus d'un niveau, le joueur pourrait être portée dans la game et passé par référence plutôt que détruit et crée à chaque niveau de jeu.
///
///3- Pour faire changer votre personnage direction, il faudra le "refléter dans une direction (reflet == scaling à -1)
///
///4- Si vous utilisez les sprites founis pour le joueur et que vous utilisez le cadre du Rectangle de sprite pour vos collisions, vos collisions seront probablement très éloignées.
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

		IntRect* intRectsImmobile; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de "idle".  
		IntRect* intRectsMarche; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de marche. 
		IntRect* intRectsCourse; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de course. 
		IntRect* intRectsSaut; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de saut. 
		IntRect* intRectsDead; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de mort. 
		IntRect* intRectsAttaque; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations d'attaque. 

	};
}

