#pragma once
#include <string>

using std::string;

namespace MVC
{
	class Modele
	{
	public:
		Modele();
		string salutations(const string& salutationRecue, int& pointsPolitesse);
		float calcul(float num1, float num2, char option);

	private:
		string politesses[3];

	};
}
