/** @file sfml_renderer.hpp
 * @brief Header classe SFMLRenderer
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#ifndef SFML_RENDERER_HPP
#define SFML_RENDERER_HPP

class Cassable;
class Incassable;
class Robot;
class Missile;
class Mine;

#include <SFML/Graphics.hpp>
#include <iostream>
#include "incassable.hpp"
#include "cassable.hpp"
#include "robot.hpp"
#include "missile.hpp"
#include "mine.hpp"

class SFMLRenderer {
	/** @class SFMLRenderer	
	 * @brief Classe réprésentant la fenêtre d'affichage du jeu */

	public:
		/** @brief Constructeur */
		SFMLRenderer();			

		/** @brief Destructeur */
		~SFMLRenderer(){	
    		delete window;
		}
		
		/** @brief Méthode d'affichage arrière-plan
		 * @param PJ1 : points de vie restants J1
		 * @param PJ2 : points de vie restants J2 */
		void remiseArrierePlan(int PJ1, int PJ2);

		/** @brief Méthode d'affichage points de vie
		 * @param PJ1 : points de vie restants J1
		 * @param PJ2 : points de vie restants J2 */
		void affichePtsDeVie(int PJ1, int PJ2);
    
		/** @brief Méthode d'affichage mur cassable
		 * @param c : objet à afficher */
    	void afficheCassable(Cassable& c);	

		/** @brief Méthode d'affichage mur incassable
		 * @param i : objet à afficher */	
		void afficheIncassable(Incassable& i);

		/** @brief Méthode d'affichage robot
		 * @param r : objet à afficher 
		 * @param nJoueur : numéro du joueur associé*/
		void afficheRobot(Robot& r, int nJoueur);

		/** @brief Méthode d'affichage missile
		 * @param m : objet à afficher 
		 * @param nJoueur : numéro du joueur associé */
		void afficheMissile(Missile& m, int nJoueur);

		/** @brief Méthode d'affichage mine
		 * @param n : objet à afficher 
		 * @param nJoueur : numéro du joueur associé */
		void afficheMine(Mine& n, int nJoueur);

		/** @brief Méthode de gestion de fin de partie
		 * @param nPerdant : numéro du joueur perdant */
		void finDePartie(int nPerdant);

		// Getter
   		sf::RenderWindow& getWindow() {return *window;};	// Getter

	private:
		/** @brief Pointeur sur un objet de type fenêtre */
     	sf::RenderWindow* window;
};

#endif
