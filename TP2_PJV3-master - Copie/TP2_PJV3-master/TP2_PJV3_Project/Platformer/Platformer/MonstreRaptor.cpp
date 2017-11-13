
#include "MonstreRaptor.h"

using namespace platformer;

MonstreRaptor::MonstreRaptor(const int SCORE_VALUE, ActeurType ACTEUR_TYPE) : Ennemie(SCORE_VALUE, ACTEUR_TYPE)
{

}

MonstreRaptor::~MonstreRaptor()
{
	delete intRectsImmobile;
	delete intRectsMarche;
	delete intRectsDead;
	delete intRectsAttaque;
}

bool MonstreRaptor::init(const String texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	setTexture(texture);
	intRectsImmobile = new IntRect[NBR_ANIMS_IMMOBILE];
	intRectsMarche = new IntRect[NBR_ANIMS_MARCHE];
	intRectsAttaque = new IntRect[NBR_ANIMS_ATTAQUE];
	intRectsDead = new IntRect[NBR_ANIMS_DEAD];

	int largeur = texture.getSize().x / NBR_COLONES; //On calcule la largeur et la hauteur à partir de la taille de la texture
	int hauteur = texture.getSize().y / NBR_LIGNES; //et des nombres d'animations


	for (int i = 0; i < NBR_ANIMS_IMMOBILE; ++i)
	{
		intRectsImmobile[i].left = largeur * i;
		intRectsImmobile[i].top = hauteur * NUM_POSITION_ANIM_IMMOBILE;
		intRectsImmobile[i].width = largeur;
		intRectsImmobile[i].height = hauteur;
	}
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

void MonstreRaptor::UpdateAnimation()
{
	if (previousState != state)
	{
		previousState = state;
		nbFrameFromBeginAnimation = 0;
	}
	++nbFrameFromBeginAnimation;
	animationNumber = 0;

	if (state == idle)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsImmobile[animationNumber]);
		if (nbFrameFromBeginAnimation >= 17)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == walking || state == falling)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsMarche[animationNumber]);
		if (nbFrameFromBeginAnimation >= 35)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == attacking)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsAttaque[animationNumber]);
		if (nbFrameFromBeginAnimation >= 23)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == dying)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsDead[animationNumber]);
		if (nbFrameFromBeginAnimation >= 29)
		{
			state = dead;
		}
	}

}

void MonstreRaptor::FlipSpriteToLeft()
{
	Sprite::setScale(-1.f, 1.f);
}

void MonstreRaptor::FlipSpriteToRigth()
{
	Sprite::setScale(1.f, 1.f);
}