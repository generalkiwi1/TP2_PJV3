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
		int lastDataModifiedState(); // Rester sur la même fenêtre ou bien modifier le compte
		int lastDataEffacerState();

		int staySameWindow(const int buttonValue);

		void confirmEnterredDataCreate(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		bool confirmerEntreeDataLogin(const string pseudo, const string password);
		bool confirmerEntreeDataModification(const string pseudo, const string password);
		bool confirmEffacerCompte(const string pseudo, const string password);
		void miseAJourSiPossible(const string pseudo, const string password, const string nom, const string prenom, const string courriel);
		void effacerCompte();
		
	};
}
