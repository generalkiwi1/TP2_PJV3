# include "Projectile.h"

using namespace platformer;

Projectile::Projectile(float vitesse): vitesse(vitesse)
{

}

void Projectile::init(const Texture& texture, const int noProjectile)
{
	rayon = texture.getSize().x / 2;
	this->noProjectile = noProjectile;
}

void Projectile::setPosition(const Vector2f& position)
{
	this->position = position;
}

void Projectile::Update()
{
	position.y += (directionY * vitesse);
}

void Projectile::Draw(RenderWindow& fenetre, Sprite& spriteBalle)
{
	spriteBalle.setPosition(this->position);
	fenetre.draw(spriteBalle);
}

bool Projectile::IsColliding(const Vector2f& positionObjet, const int largeurObjet, const int hauteurObjet)
{

	if ((position.x >= positionObjet.x -(largeurObjet/2) && position.x <= positionObjet.x + (largeurObjet / 2)) && (position.y >= positionObjet.y - (hauteurObjet / 2) && position.y <= positionObjet.y + (hauteurObjet / 2)))
	{
		return true;
	}
	return false;
}

void Projectile::HaveToDie()
{
	haveToDie = true;
}
bool Projectile::GetHaveToDie()
{
	return haveToDie;
}