/** @file cassable.hpp
 * @brief Header classe Cassable
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 08/04/2023	*/

#ifndef CASSABLE_HPP
#define CASSABLE_HPP

#include "mur.hpp"
#include "sfml_renderer.hpp"

class Cassable : public Mur{
	/** @class Cassable
	 * @brief Classe représentant un mur pouvant être détruit par un missile */

	public : 
		/** @brief Constructeur
		 * @param x,y : coordonnées du sprite (point en haut à gauche)
		 * @param tx,ty : longueur et largeur du sprite */
		Cassable(int x, int y, int tx, int ty){				
			sf::Sprite* mS = new sf::Sprite;
			mS->setPosition(sf::Vector2f(x,y));
			murSprite = mS;
			 
			longueur = tx;
			largeur = ty;
            etat = true;
		}

		/** @brief Méthode d'affichage
		 * @param render : fenêtre d'affichage */
		void AfficheMur(SFMLRenderer& render);									

		/** @brief Méthode de suppression d'affichage */
		void Casser();															

		// Getter
		bool getEtat(){return etat;};											

    private :
		/** @brief Etat du mur, true si mur existant, false sinon */
        bool etat;
};

#endif
