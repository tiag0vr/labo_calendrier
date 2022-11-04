//
// Created by Tjorge on 01.11.2022.
//

#ifndef CALENDRIER_CALENDRIER_H
#define CALENDRIER_CALENDRIER_H

#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

enum Mois {Janvier, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout,
              Septembre, Octobre, Novembre, Decembre};

/*
 * Determine si une annee est bissextile ou non
 */
bool anneeBissextile (int annee);
int nbJoursMois (Mois mois, bool estBissextile);

string nomMois(Mois mois);

void affichage(Mois mois, int annee, int index);

#endif //CALENDRIER_CALENDRIER_H
