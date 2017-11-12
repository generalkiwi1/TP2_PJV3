#include "Spawner.h"

using namespace platformer;

Spawner::Spawner(ActeurType typeToSpawn)
{
	this->ennemieToSpawn = typeToSpawn;
}
ActeurType Spawner::GetEnnemieToSpawn()
{
	return ennemieToSpawn;
}
Ennemie* Spawner::Spawn()
{
	if (ennemieToSpawn = stego)
	{
		return new MonstreStego(100);
	}
	else if (ennemieToSpawn = argent)
	{
		return new MonstreArgentavis(75);
	}
	else if (ennemieToSpawn = raptor)
	{
		return new MonstreRaptor(50);
	}
	else if (ennemieToSpawn = random)
	{
		int rnd = rand() % 3;
		if (rnd = 0)
		{
			return new MonstreStego(100);
		}
		else if (rnd = 1)
		{
			return new MonstreArgentavis(75);
		}
		else
		{
			return new MonstreRaptor(50);
		}
	}
}