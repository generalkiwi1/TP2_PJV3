#include "Joueur.h"


using namespace platformer;

Joueur::Joueur() : Acteur(ACTEUR_TYPE)
{
	
}

Joueur::~Joueur()
{
	delete intRectsImmobile;
	delete intRectsMarche;
	delete intRectsCourse;
	delete intRectsSaut;
	delete intRectsDead;
	delete intRectsAttaque;
}

bool Joueur::init(const String texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	setTexture(texture);

	intRectsImmobile = new IntRect[NBR_ANIMS_IMMOBILE]; //On se fait des tableaux pour les niveaux individuelles
	intRectsMarche = new IntRect[NBR_ANIMS_MARCHE];
	intRectsCourse = new IntRect[NBR_ANIMS_COURSE];
	intRectsSaut = new IntRect[NBR_ANIMS_SAUT];
	intRectsDead = new IntRect[NBR_ANIMS_DEAD];
	intRectsAttaque = new IntRect[NBR_ANIMS_ATTAQUE];
	
	
	int largeur = texture.getSize().x / NBR_COLONES; //On calcule la largeur et la hauteur à partir de la taille de la texture
	int hauteur = texture.getSize().y / NBR_LIGNES; //et des nombres d'animations


	//Taille et position de chacun des rectangles												
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


	for (int i = 0; i < NBR_ANIMS_COURSE; ++i)
	{
		intRectsCourse[i].left = largeur * i;
		intRectsCourse[i].top = hauteur * NUM_POSITION_ANIM_COURSE;
		intRectsCourse[i].width = largeur;
		intRectsCourse[i].height = hauteur;
	}

	for (int i = 0; i < NBR_ANIMS_SAUT; ++i)
	{
		intRectsSaut[i].left = largeur * i;
		intRectsSaut[i].top = hauteur * NUM_POSITION_ANIM_SAUT;
		intRectsSaut[i].width = largeur;
		intRectsSaut[i].height = hauteur;
	}

	for (int i = 0; i < NBR_ANIMS_DEAD; ++i)
	{
		intRectsDead[i].left = largeur * i;
		intRectsDead[i].top = hauteur * NUM_POSITION_ANIM_DEAD;
		intRectsDead[i].width = largeur;
		intRectsDead[i].height = hauteur;
	}

	for (int i = 0; i < NUM_POSITION_DERNIERE_ANIM_ATTAQUE; ++i)
	{
		if (i < 2)
		{
			intRectsAttaque[i].left = largeur * i;
			intRectsAttaque[i].top = hauteur * NUM_POSITION_ANIM_ATTAQUE;
			intRectsAttaque[i].width = largeur;
			intRectsAttaque[i].height = hauteur;
		}
		else if (i == 2)
		{
			intRectsAttaque[i].left = largeur * i;
			intRectsAttaque[i].top = hauteur * NUM_POSITION_ANIM_ATTAQUE;
			intRectsAttaque[i].width = largeur * 1.5;
			intRectsAttaque[i].height = hauteur;
		}
		else if (i == 4)
		{
			intRectsAttaque[3].left = largeur * i;
			intRectsAttaque[3].top = hauteur * NUM_POSITION_ANIM_ATTAQUE;
			intRectsAttaque[3].width = largeur * 2;
			intRectsAttaque[3].height = hauteur;
		}
		else if (i == 6)
		{
			intRectsAttaque[4].left = largeur * i;
			intRectsAttaque[4].top = hauteur * NUM_POSITION_ANIM_ATTAQUE;
			intRectsAttaque[4].width = largeur * 3;
			intRectsAttaque[4].height = hauteur;
		}
	}


	//Le rectangle d'animation initial
	setTextureRect(intRectsImmobile[0]);

	
	setOrigin(intRectsImmobile[0].height / 2, intRectsImmobile[0].width / 2);

	return true;
}



void Joueur::move(const int directionX, const int directionY, const float multiplicateurVitesse)
{
	if (directionX == 0 && directionY == 0 && multiplicateurVitesse == 0)
	{
		state = idle;
	}
	else
	{
		if (state != jumping && state != falling)
		{
			if (directionX != 0 && directionY == 0 && multiplicateurVitesse == 1)
			{
				state = walking;
			}
			else if (directionY == 0 && multiplicateurVitesse > 1)
			{
				state = running;
			}
		}
		
		if (!cantMoveRight && directionX > 0)
		{
			Sprite::move(directionX * VITESSE * multiplicateurVitesse, directionY * VITESSE * multiplicateurVitesse);
			Sprite::setScale(1.f, 1.f);
		}
		else if (!cantMoveLeft && directionX < 0)
		{
			Sprite::move(directionX * VITESSE * multiplicateurVitesse, directionY * VITESSE * multiplicateurVitesse);
			Sprite::setScale(-1.f, 1.f);
		}
		else
		{
			Sprite::move(0, directionY * VITESSE * multiplicateurVitesse);
		}
		
	}
	
}

void Joueur::Jump()
{
	state = jumping;
	jumpingTime--;
	if (jumpingTime <= 0)
	{
		state = falling;
		jumpingTime = 45;
	}
	Sprite::move(0, -VITESSE);
}

void Joueur::updateAnimation()
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
		animationNumber = floor(nbFrameFromBeginAnimation / 15);
		setTextureRect(intRectsImmobile[animationNumber]);
		if (nbFrameFromBeginAnimation >= 74)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == walking)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 6);
		setTextureRect(intRectsMarche[animationNumber]);
		if (nbFrameFromBeginAnimation >= 71)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == running)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 3);
		setTextureRect(intRectsMarche[animationNumber]);
		if (nbFrameFromBeginAnimation >= 28)
		{
			nbFrameFromBeginAnimation = 0;
		}
	}
	else if (state == jumping)
	{
		if (nbFrameFromBeginAnimation < 6)
		{
			setTextureRect(intRectsSaut[0]);
		}
		else
		{
			setTextureRect(intRectsSaut[1]);
		}
	}
	else if (state == falling)
	{
		setTextureRect(intRectsSaut[2]);
	}
	else if (state == attacking)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 3);
		if (animationNumber < 5)
		{
			setTextureRect(intRectsAttaque[animationNumber]);
		}
		else
		{
			if (animationNumber == 5)
			{
				setTextureRect(intRectsAttaque[4]);
			}
			else if (animationNumber == 6)
			{
				setTextureRect(intRectsAttaque[3]);
			}
			else if (animationNumber == 7)
			{
				setTextureRect(intRectsAttaque[2]);
			}
			else if (animationNumber == 8)
			{
				setTextureRect(intRectsAttaque[1]);
			}
			else if (animationNumber == 9)
			{
				setTextureRect(intRectsAttaque[0]);
			}
			
		}
		if (nbFrameFromBeginAnimation >= 31)
		{
			nbFrameFromBeginAnimation = 0;
			state = idle;
		}
	}
	else if (state == dying)
	{
		animationNumber = floor(nbFrameFromBeginAnimation / 12);
		setTextureRect(intRectsDead[animationNumber]);
		if (nbFrameFromBeginAnimation >= 11)
		{
			setTextureRect(intRectsDead[1]);
			state = dead;
		}
	}
	
}



