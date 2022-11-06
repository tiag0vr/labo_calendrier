//
// Created by Tjorge on 01.11.2022.
//
#include "calendrier.h"


bool estBissextile(int annee) {
    if (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0)) {
        return true;
    }
    return false;
}

int nbJourMois(Mois mois, int annee) {

    switch (mois)
    {
        case Janvier:
        case Mars:
        case Mai:
        case Juillet:
        case Aout:
        case Octobre:
        case Decembre:
            return 31;
        case Fevrier:
            return 28 + (int) estBissextile(annee);
        default:
            return 30;
    }
}

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
    return "Error";
}

void affichage(int annee, int index) {
    for (int i = 0; i < 12; ++i) {
        cout << nomMois((Mois)i) << " " << annee << endl;
        cout << " L  M  M  J  V  S  D" << endl;
        for (int j = 1; j <= nbJourMois((Mois)i, annee); ++j) {
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

int jourAnnee(int annee, int index){
    //index pour l'an 1800 => mercredi
    index = 2;

    for (int i = 1800; i < annee; ++i) {

        if (estBissextile(i)) {
            index += 2;
        }
        else {
            ++index;
        }
    }

    index %= 7;

    return index;
}
