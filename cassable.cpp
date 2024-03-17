/** @file cassable.cpp
 * @brief Définitions méthodes classe Cassable
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 25/04/2023	*/

#include "cassable.hpp"

/** @brief Méthode d'affichage
 * @param render : fenêtre d'affichage */
void Cassable::AfficheMur(SFMLRenderer& render){
    if (etat == true){
        render.afficheCassable(*this);
    }
    else return;
}

/** @brief Méthode de suppression d'affichage */
void Cassable::Casser(){
    etat = false;
}