#include "Joueur.h"

using namespace platformer;

Joueur::Joueur(State state) : persoRect(0, 0, TAILLE_RECT, TAILLE_RECT)
{
	this->state = state;
}

Joueur::~Joueur()
{
}

bool Joueur::init(const int limiteGauche, const int limiteDroite, const String texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	setTexture(texture);
	setTextureRect(persoRect);
	setOrigin(TAILLE_RECT / 2, TAILLE_RECT /2);

	this->limiteGauche = limiteGauche + TAILLE_RECT / 4;
	this->limiteDroite = limiteDroite - TAILLE_RECT / 4;

	return true;
}

bool Joueur::IsColliding(FloatRect objet)
{
	//Test sur les limites de l'écran
	if (getPosition().x < limiteGauche)
	{
		setPosition(limiteGauche, getPosition().y);
	}
	else if (getPosition().x > limiteDroite)
	{
		setPosition(limiteDroite, getPosition().y);
	}

	if (Sprite::getGlobalBounds().intersects(objet))
	{
		//Colision avec le planché
		if (state == falling && getPosition().y + getOrigin().y - objet.top <= 5 && getPosition().y + getOrigin().y - objet.top >= -5)
		{
			state = idle;
		}
		//Colision avec le plafond
		else if (state == jumping && getPosition().y - getOrigin().y - objet.top + objet.height <= 5 && getPosition().y - getOrigin().y - objet.top + objet.height >= -5)
		{
			state = falling;
		}

		//Colision avec le coté droit
		else if (getPosition().x + getOrigin().x - objet.left <= 5 && getPosition().x + getOrigin().x - objet.left >= 5)
		{
			cantMoveRight = true;
		}

		//Colision avec le coté gauche	
		else if (getPosition().x - getOrigin().x - objet.left + objet.width <= 5 && getPosition().x + getOrigin().x - objet.left + objet.width >= -5)
		{
			cantMoveLeft = true;
		}	
		return true;
	}	
	return false;
}

void Joueur::move(const int directionX, const int directionY)
{
	Sprite::move(directionX*vitesse, directionY*vitesse);
}

void Joueur::Jump()
{
	jumpingTime--;
	if (jumpingTime <= 0)
	{
		isJumping = false;
	}
	Sprite::move(0, -vitesse);
}

bool Joueur::GetState()
{
	return state;
}

