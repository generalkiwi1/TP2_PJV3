#define _USE_MATH_DEFINES

#include "Acteur.h"

using namespace platformer;


Acteur::Acteur(ActeurType ACTEUR_TYPE) : ACTEUR_TYPE(ACTEUR_TYPE)
{

}



bool Acteur::IsColliding(FloatRect objet)
{


	if (Sprite::getGlobalBounds().intersects(objet))
	{

		//Colision avec le planché
		if (state == falling && getPosition().y + getOrigin().y - objet.top <= 5 && getPosition().y + getOrigin().y - objet.top >= -5)
		{	
				isFalling = false;
				state = idle;	
		}
		else if ((state != jumping) && (state != falling) && getPosition().y + getOrigin().y - objet.top <= 5 && getPosition().y + getOrigin().y - objet.top >= -5)
		{
				isFalling = false;
		}

		//Colision avec le plafond
		else if (state == jumping && getPosition().y - getOrigin().y - objet.top <= 5 && getPosition().y - getOrigin().y - objet.top >= -5)
		{
			state = falling;
		}

		//Colision avec le coté droit
		else if (getPosition().x /*+ getOrigin().x*/ - objet.left <= 5 && getPosition().x /*+ getOrigin().x */- objet.left >= -5)
		{
			cantMoveRight = true;
		}

		//Colision avec le coté gauche	
		else if (getPosition().x /*- getOrigin().x*/ - objet.left - objet.width <= 5 && getPosition().x /*- getOrigin().x*/ - objet.left - objet.width >= -5)
		{
			cantMoveLeft = true;
		}
		return true;
	}
	return false;
}

void Acteur::ResetCantMove()
{
	cantMoveLeft = false;
	cantMoveRight = false;
	isFalling = true;
}

void Acteur::GotHit()
{

}
const State Acteur::GetState()
{
	return state;
}

void Acteur::Attack()
{
	state = attacking;
}

void Acteur::changeIsFalling()
{
	if (isFalling)
	{
		state = falling;
	}
}

const ActeurType Acteur::GetActeurType()
{
	return ACTEUR_TYPE;
}

void Acteur::setStartDying()
{
	state = dying;
}
