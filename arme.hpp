/** @file arme.hpp
 * @brief Header classe Arme
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 02/05/2023	*/

#ifndef ARME_HPP
#define ARME_HPP

class SFMLRenderer;
class Robot;

#include <memory>
#include <SFML/Graphics.hpp>

class Arme{
	/** @class Arme
	 * @brief Classe abstraite représentant une arme utilisée par un joueur */

	public :
		/** @brief Méthode d'affichage
		 * @param nJoueur : numéro du joueur ayant utilisé l'arme */
		virtual void AfficheArme(SFMLRenderer& render, int nJoueur) = 0;

		/** @brief Méthode d'avancement */
		virtual void Avance() = 0;

		/** @brief Méthode de suppression de l'affichage */
		virtual void Casser() = 0;
		
		/** @brief Destructeur */
		virtual ~Arme() {
			delete armeSprite;
		};

		// Getters
		sf::Sprite* getArmeSprite() {return armeSprite;};							
		bool getEtat() {return etat;};
		int getDegats() {return degats;};

	protected :
		/** @brief Pointeur sur sprite, contenant la position et l'orientation de l'arme*/
		sf::Sprite* armeSprite;					
		
		/** @brief Etat de l'arme, true si arme fonctionnelle, false sinon */
		bool etat;									
		
		/** @brief Valeur de dégâts associée à l'arme utilisée (1 pour missile, 3 pour mine) */
		int degats;					
};

/** @brief Pointeur partagé sur un élément de type Arme */
typedef std::shared_ptr<Arme> arme_ptr;

#endif
