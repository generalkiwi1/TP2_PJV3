#include "SpawnerStatic.h"

using namespace platformer;

SpawnerStatic::SpawnerStatic(ActeurType typeToSpawn)
{
	this->ennemieToSpawn = typeToSpawn;
}
Ennemie* SpawnerStatic::Spawn()
{
	if (ennemieToSpawn = stego)
	{
		return new MonstreStego(STEGO_SCORE_VALUE, stego);
	}
	else if (ennemieToSpawn = argent)
	{
		return new MonstreArgentavis(ARGENTAVIS_SCORE_VALUE, argent);
	}
	else if (ennemieToSpawn = raptor)
	{
		return new MonstreRaptor(RAPTOR_SCORE_VALUE, raptor);
	}
	else if (ennemieToSpawn = random)
	{
		int rnd = rand() % 3;
		if (rnd = 0)
		{
			return new MonstreStego(STEGO_SCORE_VALUE, stego);
		}
		else if (rnd = 1)
		{
			return new MonstreArgentavis(ARGENTAVIS_SCORE_VALUE, argent);
		}
		else
		{
			return new MonstreRaptor(RAPTOR_SCORE_VALUE, raptor);
		}
	}
}