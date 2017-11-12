#pragma once
#include <string>

using namespace std;


namespace MVC
{
	class Vue
	{
	public:
		Vue();
		bool lastDataInvalidCreate();
		bool lastDataInvalidLogin();
		int staySameWindow(const int buttonValue);

		void confirmEnterredDataCreate(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		bool confirmerEntreeDataLogin(const string pseudo, const string password);
	};
}
