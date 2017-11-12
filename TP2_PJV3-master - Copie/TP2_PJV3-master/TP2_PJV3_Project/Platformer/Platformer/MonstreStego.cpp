
#include "MonstreStego.h"

using namespace platformer;

MonstreStego::MonstreStego(const int SCORE_VALUE) : Ennemie(SCORE_VALUE, ACTEUR_TYPE)
{

}

MonstreStego::~MonstreStego()
{
	delete intRectsMarche;
	delete intRectsDead;
}

bool MonstreStego::init(const String texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	setTexture(texture);

	intRectsMarche = new IntRect[NBR_ANIMS_MARCHE];
	intRectsDead = new IntRect[NBR_ANIMS_DEAD];

	int largeur = texture.getSize().x / NBR_COLONES; //On calcule la largeur et la hauteur à partir de la taille de la texture
	int hauteur = texture.getSize().y / NBR_LIGNES; //et des nombres d'animations



	for (int i = 0; i < NBR_ANIMS_MARCHE; ++i)
	{
		intRectsMarche[i].left = largeur * i;
		intRectsMarche[i].top = hauteur * NUM_POSITION_ANIM_MARCHE;
		intRectsMarche[i].width = largeur;
		intRectsMarche[i].height = hauteur;
	}


	for (int i = 0; i < NBR_ANIMS_DEAD; ++i)
	{
		intRectsDead[i].left = largeur * i;
		intRectsDead[i].top = hauteur * NUM_POSITION_ANIM_DEAD;
		intRectsDead[i].width = largeur;
		intRectsDead[i].height = hauteur;
	}


	//Le rectangle d'animation initial
	setTextureRect(intRectsMarche[0]);


	setOrigin(intRectsMarche[0].height / 2, intRectsMarche[0].width / 2);

	return true;
}

void MonstreStego::UpdateAnimation()
{
	if (previousState != state)
	{
		previousState = state;
		nbFrameFromBeginAnimation = 0;
	}
	++nbFrameFromBeginAnimation;
	int animationNumber = 0;

	if (state == walking || state == idle || state == falling)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsMarche[animationNumber]);
		if (nbFrameFromBeginAnimation >= 71)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == dead)
	{

	}
	
}

void MonstreStego::FlipSpriteToRigth()
{
	Sprite::setScale(-1.f, 1.f);
}

void MonstreStego::FlipSpriteToLeft()
{
	Sprite::setScale(1.f, 1.f);
}