#pragma once
#include "Acteur.h"

namespace platformer
{
	class Ennemie : public Acteur
	{
	public:
		Ennemie(const int SCORE_VALUE, ActeurType ACTEUR_TYPE);
		virtual ~Ennemie();
		void Walk(const int directionX, const int directionY);
		void GotHit();
		void Update();
		bool LookForPlayer(FloatRect playerPosition);
		virtual bool init(const String texturePath);
		const int GetScore();

		
	protected:
		virtual void UpdateAnimation();
		virtual void FlipSpriteToRigth();
		virtual void FlipSpriteToLeft();

		const int SCORE_VALUE = 0;
		const float SIGHT_RANGE = 5;

		bool isSeeingPlayer;
		int direction = -1;

	};
}