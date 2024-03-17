/** @file missile.cpp
 * @brief Définitions méthodes classe Missile
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 02/05/2023	*/

#include "missile.hpp"

/** @brief Méthode d'affichage
 * @param render : fenêtre d'affichage
 * @param nJoueur : numéro du joueur ayant lancé le missile */
void Missile::AfficheArme(SFMLRenderer& render, int nJoueur){
    if (etat == true){
        render.afficheMissile(*this, nJoueur);
    }
    else return;
}

/** @brief Méthode d'avancement, selon l'orientation du missile */
void Missile::Avance(){
    float dX = -10*sin((3.14/180)*this->getArmeSprite()->getRotation());        // Déplacement du robot en fonction de son orientation
    float dY = 10*cos((3.14/180)*this->getArmeSprite()->getRotation());

    this->getArmeSprite()->move(dX,dY);
}

/** @brief Méthode de suppression de l'affichage */
void Missile::Casser(){
    etat = false;
}