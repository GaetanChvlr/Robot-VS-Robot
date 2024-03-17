/** @file incassable.hpp
 * @brief Header classe Incassable
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#ifndef INCASSABLE_HPP
#define INCASSABLE_HPP

#include "mur.hpp"
#include "sfml_renderer.hpp"

class Incassable : public Mur{
	/** @class Incassable
	 * @brief Classe représentant un mur ne pouvant pas être détruit par un missile */

	public : 
		/** @brief Constructeur
		 * @param x,y : coordonnées du sprite (point en haut à gauche)
		 * @param tx,ty : longueur et largeur du sprite */
		Incassable(int x, int y, int tx, int ty){									
			sf::Sprite* mS = new sf::Sprite;							
			mS->setPosition(sf::Vector2f(x,y));
			murSprite = mS;	

			longueur = tx;
			largeur = ty;
		}

		/** @brief Méthode d'affichage
		 * @param render : fenêtre d'affichage */
		void AfficheMur(SFMLRenderer& render);										
		
		/** @brief Méthode héritée de Mur */
		void Casser();																

		// Faux "getter"
		bool getEtat(){return true;};	 			
																	
};

#endif
