//
// Created by Tjorge on 01.11.2022.
//
#include "calendrier.h"


// Fonction determinant si une année est bissextile, retourne un booléen
bool estBissextile (int annee){
   if((annee % 4 == 0 && annee % 100 != 0)
      || annee % 400 == 0){
      return true;
   }
   return false;
}

// Fonction retournant le nombre de jours de chaque mois
int nbJoursMois (bool estBissextile, Mois mois){

   switch(mois){
      case Janvier :
      case Mars :
      case Mai :
      case Juillet :
      case Aout :
      case Octobre :
      case Decembre :
         return 31;

      case Fevrier :
         return 28 + estBissextile;

      default :
         return 30;
   }
}

// Fonction retournant le nom de chaque mois
string nomMois(Mois mois) {
   switch (mois)
   {
      case Janvier:
         return "Janvier";
      case Fevrier:
         return "Fevrier";
      case Mars:
         return "Mars";

      case Avril:
         return "Avril";

      case Mai:
         return "Mai";

      case Juin:
         return "Juin";

      case Juillet:
         return "Juillet";

      case Aout:
         return "Aout";

      case Septembre:
         return "Septembre";

      case Octobre:
         return "Octobre";

      case Novembre:
         return "Novembre";

      case Decembre:
         return "Decembre";

      default:
         break;
   }
}

// Fonction affichant les jours numériques de chaque mois
void affichage(Mois mois, int annee, int index) {
   for (int i = 0; i < 12; ++i) {
      cout << nomMois((Mois)i) << " " << annee << endl;
      cout << " L  M  M  J  V  S  D" << endl;
      for (int j = 1; j <= nbJoursMois(estBissextile(annee), mois); ++j) {
         if (j == 1 && index != 0) {
            cout << setw(index * 3) << " ";
         }

         cout << setw(2) << j << " ";

         ++index;
         index = index % 7;
         if (index % 7 == 0) {
            cout << endl;
         }
      }
      cout << endl << endl;
   }
}


