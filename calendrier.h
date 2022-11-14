#ifndef CALENDRIER_CALENDRIER_H
#define CALENDRIER_CALENDRIER_H

#include <string>   //string
#include <iomanip>  //affichage console
#include <iostream> //cout & cin
#include <cstdlib>  //Exit Succes
#include <limits>   //limits

using namespace std;

enum Mois { Janvier, Fevrier, Mars, Avril, Mai, Juin, Juillet,
    Aout, Septembre, Octobre, Novembre, Decembre };

//Fonction retournant un boolean si oui ou non une année est bissextile
bool estBissextile(const int& annee);

//Fonction retournant le nombre de jours d'un mois
int nbJourMois(const Mois& mois, const int& annee);

//Fonction retournant le noms du mois sous forme de string
string nomMois(const Mois& mois);

//Fonction affichant le calendrier de l'annee souhaitée
void affichage(const int& annee, int index);

//Fonction retournant quel est le 1er jour de l'annee
int premierJourAnnee(const int& annee, int index, const int& ANNEE_MIN);

#endif //CALENDRIER_CALENDRIER_H
