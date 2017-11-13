#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

namespace platformer
{
	class Projectile
	{
	public:
		Projectile(float vitesse);
		void init(const Texture& texture, const int noProjectile);
		void setPosition(const Vector2f& position);
		void Update();
		void Draw(RenderWindow& fenetre, Sprite& spriteProjectile);
		bool IsColliding(const Vector2f& positionObjet, const int largeurObjet, const int hauteurObjet);
		void HaveToDie();
		bool GetHaveToDie();

	protected:
		int noProjectile;
		float vitesse = 0;
		float rayon = 0;
		int directionY = 1;
		bool haveToDie = false;
		Vector2f position;
	};
}
