#include "Ennemie.h"

using namespace platformer;

Ennemie::Ennemie(const int SCORE_VALUE, ActeurType ACTEUR_TYPE) : SCORE_VALUE(SCORE_VALUE), Acteur(ACTEUR_TYPE)
{
	
}

Ennemie::~Ennemie()
{

}
bool Ennemie::init(const String texturePath)
{
	return false;
}

void Ennemie::Walk(const int directionX, const int directionY)
{
	if (cantMoveLeft && isFacingLeft)
	{
		isFacingLeft = false;
		direction = (direction * -1);
	}
	else if (cantMoveRight && !isFacingLeft)
	{
		isFacingLeft = true;
		direction = (direction * -1);
	}
	if (!cantMoveRight && directionX > 0)
	{
		Sprite::move(directionX * VITESSE, directionY * VITESSE);
		FlipSpriteToRigth();
	}
	else if (!cantMoveLeft && directionX < 0)
	{
		Sprite::move(directionX * VITESSE, directionY * VITESSE);
		FlipSpriteToLeft();
	}
	else
	{
		Sprite::move(0, directionY * VITESSE);
	}
	if (state != falling)
	{
		state = walking;
	}
}

void Ennemie::Update()
{
	if (state != dying && state != dead)
	{
		if (state != jumping)
		{
			changeIsFalling();
		}
		/*if (state == falling)
		{
		Walk(0, 1);
		}*/
		if (direction < 0)
		{
			Walk(-1, 0);
		}
		else if (direction > 0)
		{
			Walk(1, 0);
		}
	}
	UpdateAnimation();
	
}

void Ennemie::UpdateAnimation()
{

}

const int Ennemie::GetScoreValue()
{
	return SCORE_VALUE;
}

void Ennemie::FlipSpriteToRigth()
{

}

void Ennemie::FlipSpriteToLeft()
{

}

const bool Ennemie::GetHaveToAttack() const
{
	return haveToAttack;
}