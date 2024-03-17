/** @file missile.hpp
 * @brief Header classe Missile
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 02/05/2023	*/

#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "arme.hpp"
#include "sfml_renderer.hpp"
#include <cmath>

class Missile : public Arme{
	/** @class Missile
	 * @brief Classe représentant un missile lancé par un joueur */

	public :
		/** @brief Constructeur, paramètres dépendants du sprite du robot
		 * @param x,y : coordonnées du sprite (point en haut à gauche) 
		 * @param o : orientation du sprite */
		Missile(int x, int y, int o){																	
			sf::Sprite* aS = new sf::Sprite;												
			aS->setPosition(x-37*sin((3.14/180)*o),y+30*cos((3.14/180)*o));
			aS->setRotation(o);
			armeSprite = aS;

			etat = true;
			degats = 1;
		}

		/** @brief Méthode d'affichage
 		 * @param render : fenêtre d'affichage
 		 * @param nJoueur : numéro du joueur ayant lancé le missile */
		void AfficheArme(SFMLRenderer& render, int nJoueur);											

		/** @brief Méthode d'avancement, selon l'orientation du missile */
		void Avance();		
		
		/** @brief Méthode de suppression de l'affichage */														
		void Casser();																					
};

#endif
