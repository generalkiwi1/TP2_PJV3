#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Platformer/Testeur.h"
#include "../Platformer/Controleur.h"
#include "../Platformer/Modele.h"
//Il faut que ce dernier lien soit aussi dans 
//[right-click sur projet]\éditeur de liens\propriétés\entrées\dépendances additionnelles
//sinon il y aura une erreur de linkage

// Mika - 1640194

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace platformer;
using namespace MVC;

namespace ProjetSFMLTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Testeur testeur;			
			Assert::AreEqual(testeur.testTest(), 0);
		}

		/// Test sur le changement de scène Départ
		TEST_METHOD(ControleurSwitchSceneMenu1)
		{
			MVC::Modele modele;
			MVC::Controleur::getInstance()->changeCurrentScene(0);
			Assert::AreEqual(modele.getScene(), 0);	
		}
		/// Test sur le changement de scène Login
		// Note les test suivant ne marche pas pour je ne sais quelle raison
		TEST_METHOD(ControleurSwitchSceneMenu2)
		{
			MVC::Modele modele;
			MVC::Controleur::getInstance()->changeCurrentScene(1);
			Assert::AreEqual(modele.getScene(), 1);
		}
		/// Test sur le changement de scène Scores
		// Note les test suivant ne marche pas pour je ne sais quelle raison
		TEST_METHOD(ControleurSwitchSceneMenu3)
		{
			MVC::Modele modele;
			MVC::Controleur::getInstance()->changeCurrentScene(2);
			Assert::AreEqual(modele.getScene(), 2);
		}
		/// Test sur le changement de scène Gestion
		// Note les test suivant ne marche pas pour je ne sais quelle raison
		TEST_METHOD(ControleurSwitchSceneMenu4)
		{
			MVC::Modele modele;
			MVC::Controleur::getInstance()->changeCurrentScene(3);
			Assert::AreEqual(modele.getScene(), 3);
		}

		/// Test sur la valeur d'erreur de base create
		// Note les test suivant ne marche pas pour je ne sais quelle raison
		TEST_METHOD(ControleurValeurBase01)
		{
			Assert::IsFalse(Controleur::getInstance()->getErrorCreate());
		}

		// Je n'ai pas tester le reste de la fonction car il retourne toujours 0

		/// Test sur la valeur d'erreur de base login
		TEST_METHOD(ControleurValeurBase02)
		{
			Assert::IsFalse(Controleur::getInstance()->getErrorLogin());
		}

		/// Test sur la valeur d'erreur de base modification
		TEST_METHOD(ControleurValeurBase03)
		{
			Assert::AreEqual(Controleur::getInstance()->getErrorModification(),0);
		}

		/// Test sur la valeur d'erreur de base effacer
		TEST_METHOD(ControleurValeurBase04)
		{
			Assert::AreEqual(Controleur::getInstance()->getLastEffacerState(), 0);
		}

		/// Test sur la méthode créer vide 1
		TEST_METHOD(ControleurValeurCreer01)
		{
			string pseudo = "";
			string password = "";
			string nom = "";
			string prenom = "";
			string courriel = "";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer vide 2
		TEST_METHOD(ControleurValeurCreer02)
		{
			string pseudo = "Mika";
			string password = "";
			string nom = "";
			string prenom = "";
			string courriel = "";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer vide 3 
		TEST_METHOD(ControleurValeurCreer03)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "";
			string prenom = "";
			string courriel = "";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer vide 4
		TEST_METHOD(ControleurValeurCreer04)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "";
			string courriel = "";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer vide 5
		TEST_METHOD(ControleurValeurCreer05)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}
		/// Test sur la méthode créer valide 
		TEST_METHOD(ControleurValeurCreer06)
		{
			string pseudo = "mika"; // Ce test crée un compte tout seul. Il faut changer le nom pour que sa marche
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsFalse(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 1
		TEST_METHOD(ControleurValeurCreer07)
		{
			string pseudo = "Mikaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 2
		TEST_METHOD(ControleurValeurCreer08)
		{
			string pseudo = "Mika";
			string password = "Pa";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 3
		TEST_METHOD(ControleurValeurCreer09)
		{
			string pseudo = "Mika";
			string password = "Pa";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 4
		TEST_METHOD(ControleurValeurCreer10)
		{
			string pseudo = "Mika";
			string password = "Padassssssssssssssssssssssssss";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 5
		TEST_METHOD(ControleurValeurCreer11)
		{
			string pseudo = "Mika";
			string password = "Pa1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 6
		TEST_METHOD(ControleurValeurCreer12)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "M";
			string prenom = "Mika";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 7
		TEST_METHOD(ControleurValeurCreer13)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "M";
			string courriel = "Mika@Mika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 8
		TEST_METHOD(ControleurValeurCreer14)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "MikaMika.com";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 9
		TEST_METHOD(ControleurValeurCreer15)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mikacom";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode créer invalide 10
		TEST_METHOD(ControleurValeurCreer16)
		{
			string pseudo = "Mika";
			string password = "Password1!";
			string nom = "Mika";
			string prenom = "Mika";
			string courriel = "Mika@Mika.capcom";
			Controleur::getInstance()->confirmCreateData(pseudo, password, nom, prenom, courriel);
			Assert::IsTrue(Controleur::getInstance()->getErrorCreate());
		}

		/// Test sur la méthode login valide
		TEST_METHOD(ControleurValeurLogin01)
		{
			string pseudo = "mika";
			string password = "Password1!";
			Controleur::getInstance()->confirmLoginData(pseudo, password);
			Assert::IsFalse(Controleur::getInstance()->getErrorLogin());
		}

		/// Test sur la méthode login invalide 1
		TEST_METHOD(ControleurValeurLogin02)
		{
			string pseudo = "mika";
			string password = "garbage!";
			Controleur::getInstance()->confirmLoginData(pseudo, password);
			Assert::IsTrue(Controleur::getInstance()->getErrorLogin());
		}

		/// Test sur la méthode login invalide 2
		TEST_METHOD(ControleurValeurLogin03)
		{
			string pseudo = "garbage";
			string password = "Password1!";
			Controleur::getInstance()->confirmLoginData(pseudo, password);
			Assert::IsTrue(Controleur::getInstance()->getErrorLogin());
		}

		/// Test sur la méthode login invalide 3
		TEST_METHOD(ControleurValeurLogin04)
		{
			string pseudo = "garbage";
			string password = "garbage!";
			Controleur::getInstance()->confirmLoginData(pseudo, password);
			Assert::IsTrue(Controleur::getInstance()->getErrorLogin());
		}

		/// Test sur la méthode modif valide
		TEST_METHOD(ControleurValeurModif01)
		{
			string pseudo = "mika";
			string password = "Password1!";
			Controleur::getInstance()->confirmModificationData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getErrorModification(),1);
		}

		/// Test sur la méthode modif invalide 1
		TEST_METHOD(ControleurValeurModif02)
		{
			string pseudo = "mika";
			string password = "garbage!";
			Controleur::getInstance()->confirmModificationData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getErrorModification(), 0);
		}

		/// Test sur la méthode modif invalide 2
		TEST_METHOD(ControleurValeurModif03)
		{
			string pseudo = "garbage";
			string password = "Password1!";
			Controleur::getInstance()->confirmModificationData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getErrorModification(), 0);
		}

		/// Test sur la méthode modif invalide 3
		TEST_METHOD(ControleurValeurModif04)
		{
			string pseudo = "garbage";
			string password = "garbage!";
			Controleur::getInstance()->confirmModificationData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getErrorModification(), 0);
		}

		/// Test sur la méthode effacer valide
		TEST_METHOD(ControleurValeurEffacer01)
		{
			string pseudo = "mika";
			string password = "Password1!";
			Controleur::getInstance()->confirmEraseData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getLastEffacerState(), 1);
		}

		/// Test sur la méthode effacer invalide 1
		TEST_METHOD(ControleurValeurEffacer02)
		{
			string pseudo = "mika";
			string password = "garbage!";
			Controleur::getInstance()->confirmEraseData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getLastEffacerState(), 0);
		}

		/// Test sur la méthode effacer invalide 2
		TEST_METHOD(ControleurValeurEffacer03)
		{
			string pseudo = "garbage";
			string password = "Password1!";
			Controleur::getInstance()->confirmEraseData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getLastEffacerState(), 0);
		}

		/// Test sur la méthode effacer invalide 3
		TEST_METHOD(ControleurValeurEffacer04)
		{
			string pseudo = "garbage";
			string password = "garbage!";
			Controleur::getInstance()->confirmEraseData(pseudo, password);
			Assert::AreEqual(Controleur::getInstance()->getLastEffacerState(), 0);
		}











	};
}