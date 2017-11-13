#pragma once

#include "MonstreStego.h"
#include "MonstreArgentavis.h"
#include "MonstreRaptor.h"


namespace platformer
{
	class SpawnerStatic
	{
	public:
		SpawnerStatic(ActeurType typeToSpawn);
		Ennemie* Spawn();
	private:
		ActeurType ennemieToSpawn = random;
		static const int RAPTOR_SCORE_VALUE = 50;
		static const int ARGENTAVIS_SCORE_VALUE = 75;
		static const int STEGO_SCORE_VALUE = 100;
	};
}
