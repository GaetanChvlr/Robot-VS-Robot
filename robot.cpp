/** @file robot.cpp
 * @brief Définitions méthode classe Robot
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 25/04/2023	*/

#include "robot.hpp"
#include <iostream>
#include <cmath>

/** @brief Méthode d'affichage
 * @param render : fenêtre d'affichage */
void Robot::AfficheRobot(SFMLRenderer& render){
    render.afficheRobot(*this, getNumeroJoueur());
}

/** @brief Méthode de rotation à gauche du sprite */
void Robot::TourneAGauche(){
    this->getSprite()->rotate(-5);
}

/** @brief Méthode de rotation à droite du sprite */
void Robot::TourneADroite(){
    this->getSprite()->rotate(5);
}

/** @brief Méthode d'avancée du spritee */
void Robot::Avance(){
    int dX = -5*sin((3.14/180)*this->getSprite()->getRotation());       // Déplacement du robot en fonction de son orientation
    int dY = 5*cos((3.14/180)*this->getSprite()->getRotation());
    this->getSprite()->move(dX,dY);
}

/** @brief Méthode de recul du sprite */
void Robot::Recule(){
    int dX = 5*sin((3.14/180)*this->getSprite()->getRotation());
    int dY = -5*cos((3.14/180)*this->getSprite()->getRotation());
    this->getSprite()->move(dX,dY);
}

/** @brief Méthode d'avancée des missiles */
void Robot::AvanceMissiles(){
    for (const arme_ptr a : armes){
        a->Avance();
    }
}

/** @brief Méthode de récupération du nombre d'armes actives */
int Robot::getNbArmesActives(){
    int i = 0;
    for (const arme_ptr a : armes){
        if (a->getEtat() == true) i++;
    }
    return i;
}