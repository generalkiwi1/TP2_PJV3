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
		void Update();
		virtual bool init(const String texturePath);
		const int GetScoreValue();
		const bool GetHaveToAttack() const;

		
	protected:
		virtual void UpdateAnimation();
		virtual void FlipSpriteToRigth();
		virtual void FlipSpriteToLeft();

		const int SCORE_VALUE = 0;
		const float SIGHT_RANGE = 5;

		bool haveToAttack = false;
		int direction = -1;

	};
}