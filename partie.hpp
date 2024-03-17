/** @file partie.hpp
 * @brief Header classe Partie
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#ifndef PARTIE_HPP
#define PARTIE_HPP

#include "mur.hpp"
#include "missile.hpp"
#include "mine.hpp"
#include "robot.hpp"
#include <vector>

class Partie {
	/** @class Partie
	 * @brief Classe réprésentant une partie de jeu */
	 
	public :
		/** @brief Constructeur
		* @param nbObstacles : nombre de murs présents dans la partie */
		Partie(int nbObstacles);			
		
		/** @brief Constructeur par copie*/
		Partie(const Partie& p){							
			*this = p;
		}

		/** @brief Opérateur d'assignement */
		Partie& operator=(const Partie& p){					
			J1 = p.J1;
			J2 = p.J2;
			murs = p.murs;

			return *this;
		}

		/** @brief Destructeur*/
		~Partie(){};

		/** @brief Méthode d'ajout à la liste des murs
		 * @param mur : pointeur sur l'objet à ajouter */
		void AjouteMur(mur_ptr mur) {murs.push_back(mur);};										

		/** @brief Méthode de gestion du déroulement de la partie
 		 * @param render : fenêtre d'affichage */
		void PartieEnCours(SFMLRenderer& render);
		
		/** @brief Méthode de gestion des évènements
 		 * @param render : fenêtre d'affichage */
		void GestionEvts(SFMLRenderer& render);

		/** @brief Méthode d'affichage
 		 * @param render : fenêtre d'affichage */
		void Affiche(SFMLRenderer& render);

		/** @brief Méthode de vérifications de collision entre 2 sprites
 		 * @param spr1 : premier pointeur sur sprite
         * @param spr2 : deuxième pointeur sur sprite */
		int VerifCollision(sf::Sprite* spr1, sf::Sprite* spr2);				// Vérification collisions
		
		/** @brief Méthode de vérification de collision pour un robot
 		 * @param spr1 : pointeur sur sprite du robot à tester */
		int VerifCollisionGlobal(sf::Sprite* spr1);

		/** @brief Méthode de mise à jour des armes
 		 * @param render : fenêtre d'affichage */
		void UpdateArmes(SFMLRenderer& render);

		// Getters
		const int getNbObstacles() const { return murs.size(); };			// Getters
		const std::vector<mur_ptr> getMurs() const { return murs; };

	private : 
		/** @brief Premier joueur, objet type Robot */
		Robot J1;

		/** @brief Deuxième joueur, objet type Robot */
		Robot J2;

		/** @brief Liste de pointeurs sur les obstacles */
		std::vector<mur_ptr> murs;	
};


#endif
