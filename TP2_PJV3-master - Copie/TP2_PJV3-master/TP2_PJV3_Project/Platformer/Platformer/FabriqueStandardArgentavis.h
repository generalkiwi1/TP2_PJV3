#pragma once
#include "MonstreArgentavis.h"


namespace platformer
{
	class FabriqueStandardArgentavis
	{

	private: 
		static const int ARGENTAVIS_SCORE_VALUE = 75;
	public:
		Ennemie* FabriqueStandardArgentavis::SpawnArgentavis()
		{
			return new MonstreArgentavis(ARGENTAVIS_SCORE_VALUE, argent);
		}
	};
}