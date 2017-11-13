#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace sf;

enum State { walking, attacking, dying, dead, idle, jumping, falling, running };
enum ActeurType {other, random, player, raptor, stego, argent};


namespace platformer
{
	class Acteur : public Sprite
	{
	public:
		Acteur(ActeurType ACTEUR_TYPE);
		bool IsColliding(FloatRect objet);
		void ResetCantMove();
		void changeIsFalling();
		void Attack();
		virtual void GotHit();
		const State GetState();
		const ActeurType GetActeurType();
		void setStartDying();
		bool isOnScreen = false;
		bool cantMoveLeft = false; //Indique si le joueur ne peut pas se deplacer vers la gauche.
		bool cantMoveRight = false; //Indique si le joueur ne peut pas se deplacer vers la droite.


	protected:
		const float VITESSE = 3; // Vitesse de deplacement.
		State state = idle; //Etat actuel du joueur.
		State previousState = idle; //Etat precedant du joueur.
		const ActeurType ACTEUR_TYPE = other;
		bool isFalling = false;
		bool isFacingLeft = true;
		int animationNumber = 0;//Animation actuel.
		int nbFrameFromBeginAnimation = 0; //Compteur pour les animations.
	};
}
