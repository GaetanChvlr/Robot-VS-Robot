/** @file robot.hpp
 * @brief Header classe Robot
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 25/04/2023	*/

#ifndef ROBOT_HPP
#define ROBOT_HPP

class SFMLRenderer;
class Arme;

#include "sfml_renderer.hpp"
#include "arme.hpp"
#include <iostream>

class Robot{
	/** @class Robot
	 * @brief Classe réprésentant un joueur */

    public :
        /** @brief Constructeur par défaut */
        Robot(){                                        
            ptsDeVie = 0;
            numeroJoueur = 0;
        };

        /** @brief Constructeur
		* @param px,py : coordonnées du sprite (point en haut à gauche) 
        * @param o : orientation du sprite 
        * @param ptsVie : points de vie du joueur
        * @param nJoueur : numéro du joueur */
        Robot(int px, int py, int o, int ptsVie, int nJoueur){            
            sf::Sprite* mS = new sf::Sprite;                            
			mS->setPosition(sf::Vector2f(px,py));
            mS->setRotation(o);
			robSprite = mS;
            
            ptsDeVie = ptsVie;
            numeroJoueur = nJoueur;
        }

        /** @brief Constructeur par copie */
		Robot(const Robot& r){                                            
			*this = r;
		}

        /** @brief Opérateur d'assignement */
        Robot& operator=(const Robot& r){                                 
            ptsDeVie = r.ptsDeVie;
            numeroJoueur = r.numeroJoueur;
            robSprite = r.robSprite;

            return *this;
        }

        /** @brief Destructeur */
        ~Robot(){                                                         
            delete robSprite;
        };

        /** @brief Méthode d'affichage
         * @param render : fenêtre d'affichage */
		void AfficheRobot(SFMLRenderer& render);  

        /** @brief Méthode de rotation à gauche du sprite */                
        void TourneAGauche();

        /** @brief Méthode de rotation à droite du sprite */
        void TourneADroite();

        /** @brief Méthode d'avancée du sprite */
        void Avance();

        /** @brief Méthode de recul du sprite */
        void Recule();

        // Setter
        void setPtsDeVie(int pts){ptsDeVie = pts;};                         // Setter

        // Getters
        int getPtsDeVie() {return ptsDeVie;};                               // Getters
        int getNumeroJoueur() {return numeroJoueur;};
        int getNbArmesActives();
        sf::Sprite* getSprite() {return robSprite;};
        std::vector<arme_ptr> getArmes() {return armes;};

        /** @brief Méthode d'ajout à la liste des armes
		 * @param arme : pointeur sur l'objet à ajouter */
        void AjouteArme(arme_ptr arme) {armes.push_back(arme);};            // Gestion des armes
        
        /** @brief Méthode d'avancée des missiles */
        void AvanceMissiles();

    private :
        /** @brief Points de vie du joueur */
        int ptsDeVie;

        /** @brief Numéro assigné au joueur (1 ou 2)*/
        int numeroJoueur;

        /** @brief Pointeur sur le sprite du robot */
        sf::Sprite* robSprite;

        /** @brief Liste de pointeurs sur les armes utilisés */
        std::vector<arme_ptr> armes;	
};

#endif

