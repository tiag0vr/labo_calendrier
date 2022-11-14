//---------------------------------------------------------
// Classe : PRG1_E
// Fichier :
//          - main.cpp
//          - calendrier.cpp
//          - calendrier.h
// Auteur(s) : TiagoDeOliveiraJorge & LionelPollien
// But : Ecrire un programme qui affiche, pour une année saisie par l'utilisateur,
//       le calendrier complet en tenant compte des années bissextiles
// Modifications :
// Remarque(s) :
//           - Au début, nous avions créé un fichier tools.cpp ainsi qu'un
//             fichier tools.h afin d'implémenter les diverses méthodes
//             utiles à notre programme mais qui n'étaient pas directement
//             reliées au calendrier (par exemple : les méthodes de saisies).
//             Mais vu que nous n'avons qu'un seul programme, cela n'était
//             pas vraiment utile donc nous l'avons supprimé et nous avons
//             mis les méthodes non utiles à l'affichage du calendrier dans
//             le main.
//           - Afin de savoir quel est le 1er jour de l'annee, nous avons
//             utilisé une année de référence où nous connaissions le jour
//             du 1er janvier. Nous n'avons pas utilisé la librairie <ctime>
//             car nous n'avons pas réussi à l'utiliser correctement.
// Compilation :
//    - Version C++ : 20
//    - Compilateur : Mingw-w64 g++ 12.2.0
//---------------------------------------------------------

#include "calendrier.h"

/*
 * Fonction de saisie utilisateur, recommence en cas
 * de fausse entrée, retourne le contenu de la saisie
*/
int saisie (const int& min, const int& max);

//Fonction de saisie pour savoir si l'utilisateur veux recommencer ou non
char saisieRecommencer ();

// Macro pour vider le buffer
#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')


int main() {

   // Déclaration des variables
    int  index = 0; //Entier pour indiquer la position du 1er jour de l'année
                    // initialisation obligatoire car sinon warning
    char again;     //caractère pour recommencer ou non le programme
    int  annee;
    const int ANNEE_MIN = 1800;
    const int ANNEE_MAX = 2100;

   //boucle d'execution du programme
   do{
       annee = saisie(ANNEE_MIN, ANNEE_MAX);

       index = premierJourAnnee(annee, index, ANNEE_MIN);

       affichage(annee, index);

       again = saisieRecommencer();

   }while(again == 'O' || again == 'o');

   return EXIT_SUCCESS;
}


int saisie (const int& min, const int& max){

   // Déclaration de variables internes
   int saisie;
   bool erreur;
   string msgEntree = "Veuillez entrer une annee entre 1800 et 2100 :";
   string msgErreur = "Cette entree est incorrecte, veuillez recommencer.\n";

   do {
      // Message et entrée utilisateur
      cout << msgEntree;
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


char saisieRecommencer(){
    char again;
    bool erreur;
    const string msgRecommencer =
            "Cette entree est incorrect, veuillez recommencer : [O/N]";
    const string msgEntree =
            "Voulez-vous recommencer ?";

    do{
        cout << msgEntree << endl;
        cin >> again;

        erreur = cin.fail() or again != 'O' and again != 'o'
                 and again != 'N' and again != 'n';
        if(erreur){
            cout << msgRecommencer << endl;
            cin.clear();
        }
        CLEAR_BUFFER;

    }while(erreur);

    return again;
}
