/** @file mine.cpp
 * @brief Définitions méthodes classe Mine
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/05/2023	*/

#include "mine.hpp"

/** @brief Méthode d'affichage
 * @param nJoueur : numéro du joueur ayant posé la mine */
void Mine::AfficheArme(SFMLRenderer& render, int nJoueur){
    if (etat == true){
        render.afficheMine(*this, nJoueur);
    }
    else return;
}

/** @brief Méthode d'avancement, retourne directement car mine fixe */
void Mine::Avance(){
    return;                        
}

/** @brief Méthode de suppression de l'affichage */
void Mine::Casser(){
    etat = false;
}