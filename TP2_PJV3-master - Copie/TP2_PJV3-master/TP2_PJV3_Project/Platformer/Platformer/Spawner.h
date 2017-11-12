#pragma once

#include "MonstreStego.h"
#include "MonstreArgentavis.h"
#include "MonstreRaptor.h"


namespace platformer
{
	class Spawner
	{
	public:
		Spawner(ActeurType typeToSpawn);
		ActeurType GetEnnemieToSpawn();
		Ennemie* Spawn();
	private:
		ActeurType ennemieToSpawn = random;
	};
}
