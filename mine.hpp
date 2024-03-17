/** @file mine.hpp
 * @brief Header classe Mine
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/05/2023	*/

#ifndef MINE_HPP
#define MINE_HPP

#include "arme.hpp"
#include "sfml_renderer.hpp"

class Mine : public Arme{
	/** @class Mine
	 * @brief Classe représentant une mine posée par un joueur */

	public : 
		/** @brief Constructeur
		 * @param x,y : coordonnées du sprite (point en haut à gauche) */
		Mine(int x, int y){														
			sf::Sprite* aS = new sf::Sprite;							
			aS->setPosition(x,y);
			armeSprite = aS;

			etat = true;
			degats = 3;
		}

		/** @brief Méthode d'affichage
		 * @param nJoueur : numéro du joueur ayant posé la mine */
		void AfficheArme(SFMLRenderer& render, int nJoueur);					

		/** @brief Méthode d'avancement, retourne directement car mine fixe */
		void Avance();		

		/** @brief Méthode de suppression de l'affichage */					
		void Casser();
};

#endif