
#include "MonstreArgentavis.h"

using namespace platformer;

MonstreArgentavis::MonstreArgentavis(const int SCORE_VALUE, ActeurType ACTEUR_TYPE): Ennemie(SCORE_VALUE, ACTEUR_TYPE)
{
	
}

MonstreArgentavis::~MonstreArgentavis()
{
	delete intRectsMarche;
	delete intRectsDead;
	delete intRectsAttaque;
}

bool MonstreArgentavis::init(const String texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	setTexture(texture);
	intRectsMarche = new IntRect[NBR_ANIMS_MARCHE];
	intRectsAttaque = new IntRect[NBR_ANIMS_ATTAQUE];
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
	for (int i = 0; i < NBR_ANIMS_ATTAQUE; ++i)
	{
		intRectsAttaque[i].left = largeur * i;
		intRectsAttaque[i].top = hauteur * NBR_ANIMS_ATTAQUE;
		intRectsAttaque[i].width = largeur;
		intRectsAttaque[i].height = hauteur;
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

void MonstreArgentavis::UpdateAnimation()
{
	if (timeRemainingForShooting == 0)
	{
		haveToAttack = true;
		timeRemainingForShooting = TIME_FOR_RELOADING_SHOOT;
	}
	else
	{
		haveToAttack = false;
	}
	--timeRemainingForShooting;

	if (previousState != state)
	{
		previousState = state;
		nbFrameFromBeginAnimation = 0;
	}
	++nbFrameFromBeginAnimation;
	animationNumber = 0;


	if (state == walking || state == falling)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsMarche[animationNumber]);
		if (nbFrameFromBeginAnimation >= 47)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == attacking)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsAttaque[animationNumber]);
		if (nbFrameFromBeginAnimation >= 5)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == dying)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 12);
		setTextureRect(intRectsDead[animationNumber]);
		if (nbFrameFromBeginAnimation >= 11)
		{
			state = dead;
		}
	}

}

void MonstreArgentavis::FlipSpriteToLeft()
{
	Sprite::setScale(-1.f, 1.f);
}

void MonstreArgentavis::FlipSpriteToRigth()
{
	Sprite::setScale(1.f, 1.f);
}