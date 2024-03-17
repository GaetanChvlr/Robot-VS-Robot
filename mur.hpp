/** @file mur.hpp
 * @brief Header classe Mur
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#ifndef MUR_HPP
#define MUR_HPP

class SFMLRenderer;

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

class Mur{
	/** @class Mur
	 * @brief Classe abstraite représentant un obstacle */

	public :
		/** @brief Méthode d'affichage
		 * @param render : fenêtre d'affichage */
		virtual void AfficheMur(SFMLRenderer& render) = 0;			
		
		/** @brief Méthode de suppression de l'affichage */
		virtual void Casser() = 0;
		
		// Getter virtuel
		virtual bool getEtat() = 0;
		
		/** @brief Destructeur */
		virtual ~Mur() {
			delete murSprite;
		};

		// Getters
		sf::Sprite* getMurSprite() {return murSprite;};						
		const int getLongueur() const { return longueur; };
		const int getLargeur() const { return largeur; };

	protected :
		/** @brief Dimensions du sprite */
		int longueur;
		int largeur;	

		/** @brief Pointeur sur le sprite du mur, contenant la position */
		sf::Sprite* murSprite;									
};

/** @brief Pointeur partagé sur un élément de type Mur */
typedef std::shared_ptr<Mur> mur_ptr;

#endif
