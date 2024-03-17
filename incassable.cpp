/** @file incassable.cpp
 * @brief Définitions méthodes classe Incassable
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 25/04/2023	*/

#include "incassable.hpp"

/** @brief Méthode d'affichage
 * @param render : fenêtre d'affichage */
void Incassable::AfficheMur(SFMLRenderer& render){
    render.afficheIncassable(*this);
}

/** @brief Méthode héritée de la classe Mur : 
 *          rien ne se passe, le mur est incassable par définition */
void Incassable::Casser(){
    return;                     
}