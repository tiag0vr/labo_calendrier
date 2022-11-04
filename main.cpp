//---------------------------------------------------------
// Classe : PRG1_E
// Fichier : main.cpp
// Auteur(s) : TiagoDeOliveiraJorge & LionelPollien
// But : Ecrire un programme qui affiche pour une année saisie par l'utilisateur le calendrier complet en tenant
// compte des années bissextiles
// Modifications :
// Remarque(s) :
// Compilation :
//    - Version C++ : 20
//    - Compilateur : Mingw-w64 g++ 12.2.0
//---------------------------------------------------------

#include "calendrier.h"

//ev. method pour avoir date exacte
//Revoir include
//Boucle de vérification de l'entrée utilisateur pour oui/non
//Ev Remarques à faire (tools,...)
//Régler Warning


int saisie (const string& msgInvite, const string& msgErreur, const int& min, const int& max);

// Macro pour vider le buffer
#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')


int main() {

   // Déclaration des variables
   int   index = 3;  //Position du 1er jour de l'annee
   char  again;      //caractère pour recommencer ou non le programme
   Mois  mois;       //Enum : mois de l'annee


   //boucle d'execution du programme
   do{

      // Variables pour saisie utilisateur
      string msgEntree = "Veuillez entrer une annee entre 1800 et 2100 :\0";
      string msgErreur = "Cette entree est incorrecte, veuillez recommencer.\n";
      const int ANNEE_MIN = 1800;
      const int ANNEE_MAX = 2100;
      int annee = saisie(msgEntree, msgErreur, ANNEE_MIN, ANNEE_MAX);

      // Saisie de l'année par l'utilisateur
      affichage(mois , annee, index);

      cout << "voulez-vous recommencer [O/N]" << endl;
      cin >> again;

   }while(again == 'O' || again == 'o');

   return EXIT_SUCCESS;
}


// Fonction de saisie utilisateur, recommence en cas de fausse entrée, retourne le contenu de la saisie
int saisie (const string& msgInvite, const string& msgErreur, const int& min, const int& max){

   // Déclaration de variables internes
   int saisie;
   bool erreur;

   do {
      // Message et entrée utilisateur
      cout << msgInvite;
      cin >> saisie;

      // Vérification de l'entrée
      erreur = cin.fail() or saisie < min or saisie > max;
      if (erreur) {
         cout << msgErreur;
         cin.clear();
      }
      CLEAR_BUFFER;

   } while (erreur);

   return saisie;
}
