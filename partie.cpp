/** @file partie.cpp
 * @brief Définitions méthodes classe Partie
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#include "partie.hpp"
#include "sfml_renderer.hpp"

#include <random>
#include <unistd.h>
#include <cmath>

/** @brief Constructeur
 * @param nbObstacles : nombre de murs présents dans la partie */
Partie::Partie(int nbObstacles){
	Robot* r1 = new Robot(750,40,45,10,1);						// Création des robots
	J1 = *r1;

	Robot* r2 = new Robot(35,780,-135,10,2);
	J2 = *r2;

	std::srand(time(nullptr));									// Création des obstacles
	for (int i = 0; i < nbObstacles; i++){

		int x = (int)rand()%700 + 20;
		int y = (int)rand()%700 + 20;
		int tx = (int)rand()%50 + 30;
		int ty = (int)rand()%50 + 30;

		if (i%2 == 0){														// Ajout au jeu, avec les shared_ptr
			this->AjouteMur(std::make_shared<Incassable>(x,y,tx,ty));
		}
		else{
			this->AjouteMur(std::make_shared<Cassable>(x,y,tx,ty));
		}
	}

	this->AjouteMur(std::make_shared<Incassable>(0,0,800,10));			// Création des bords
	this->AjouteMur(std::make_shared<Incassable>(0,0,10,800));
	this->AjouteMur(std::make_shared<Incassable>(790,0,10,800));
	this->AjouteMur(std::make_shared<Incassable>(0,790,800,10));
}

/** @brief Méthode de gestion du déroulement de la partie
 * @param render : fenêtre d'affichage */
void Partie::PartieEnCours(SFMLRenderer& render){
	render.getWindow().display();										// Rafraîchissement de la fenêtre

    while(render.getWindow().isOpen()){
        sf::Event evt;													// Gestion évènements
        while (render.getWindow().pollEvent(evt)){				
		
            if (evt.type == sf::Event::Closed){					// Fermeture
                render.getWindow().close();
            }
		
			if (evt.type == sf::Event::KeyPressed){				// Entrée clavier
				this->GestionEvts(render);
			}
        }
		
		UpdateArmes(render);											// Avancée missiles
		
		render.remiseArrierePlan(J1.getPtsDeVie(),J2.getPtsDeVie());	// Affichage arrière-plan
		
		this->Affiche(render);  										// Affichage des sprites

		if (J1.getPtsDeVie() <= 0) render.finDePartie(1);				// Vérifications fin de partie
		else if (J2.getPtsDeVie() <= 0) render.finDePartie(2);
		else{
			render.getWindow().display();
		}
    }
}

/** @brief Méthode de gestion des évènements
 * @param render : fenêtre d'affichage */
void Partie::GestionEvts(SFMLRenderer& render){
	sf::Keyboard K;

	if (K.isKeyPressed(sf::Keyboard::Left)){						// Rotation à gauche J1
		J1.TourneAGauche();

		if (VerifCollisionGlobal(J1.getSprite()) == 1){		// Mouvement contraire si collision
			J1.TourneADroite();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::Right)){						// Rotation à droite J1
		J1.TourneADroite();

		if (VerifCollisionGlobal(J1.getSprite()) == 1){
			J1.TourneAGauche();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::Up)){							// Avancée J1
		J1.Avance();

		if (VerifCollisionGlobal(J1.getSprite()) == 1){
			J1.Recule();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::Down)){						// Recul J1
		J1.Recule();	
		
		if (VerifCollisionGlobal(J1.getSprite()) == 1){
			J1.Avance();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::M)){						 	// Missile J1
		int X = J1.getSprite()->getPosition().x;			
		int Y = J1.getSprite()->getPosition().y;
		int O = J1.getSprite()->getRotation();

		if (J1.getNbArmesActives() < 4){
			J1.AjouteArme(std::make_shared<Missile>(X,Y,O));		// Missile placé à la même position que le robot, avec la même orientation
		}
	}

	if (K.isKeyPressed(sf::Keyboard::P)){							// Mine J1
		int X = J1.getSprite()->getPosition().x;
		int Y = J1.getSprite()->getPosition().y;

		if (J1.getNbArmesActives() < 4){
			J1.AjouteArme(std::make_shared<Mine>(X,Y));				// Mine placée à la même position que le robot
		}
	}

	if (K.isKeyPressed(sf::Keyboard::Q)){							// Rotation à gauche J2
		J2.TourneAGauche();

		if (VerifCollisionGlobal(J2.getSprite()) == 1){
			J2.TourneADroite();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::D)){							// Rotation à droite J2
		J2.TourneADroite();

		if (VerifCollisionGlobal(J2.getSprite()) == 1){
			J2.TourneAGauche();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::Z)){							// Avancée J2
		J2.Avance();	

		if (VerifCollisionGlobal(J2.getSprite()) == 1){
			J2.Recule();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::S)){							// Recul J2
		J2.Recule();
		
		if (VerifCollisionGlobal(J2.getSprite()) == 1){
			J2.Avance();
		}
	}

	if (K.isKeyPressed(sf::Keyboard::E)){							// Missile J2
		int X = J2.getSprite()->getPosition().x;	
		int Y = J2.getSprite()->getPosition().y;
		int O = J2.getSprite()->getRotation();
		
		if (J2.getNbArmesActives() < 4){
			J2.AjouteArme(std::make_shared<Missile>(X,Y,O));		// Missile placé à la même position que le robot, avec la même orientation
		}
	}

	if (K.isKeyPressed(sf::Keyboard::A)){							// Mine J2
		int X = J2.getSprite()->getPosition().x;
		int Y = J2.getSprite()->getPosition().y;

		if (J2.getNbArmesActives() < 4){
			J2.AjouteArme(std::make_shared<Mine>(X,Y));				// Mine placée à la même position que le robot
		}
	}
}

/** @brief Méthode d'affichage
 * @param render : fenêtre d'affichage */
void Partie::Affiche(SFMLRenderer& render){							
	for (const mur_ptr m : murs){								// Murs
		m->AfficheMur(render);
	}

	J1.AfficheRobot(render);									// Robot J1
	
	for (const arme_ptr a : J1.getArmes()){						// Affichage armes J1
		a->AfficheArme(render,1);
	}

	J2.AfficheRobot(render);									// Robot J2
	
	for (const arme_ptr a : J2.getArmes()){						// Affichage armes J2
		a->AfficheArme(render,2);
	}
}

/** @brief Méthode de vérifications de collision entre 2 sprites
 * @param spr1 : premier pointeur sur sprite
 * @param spr2 : deuxième pointeur sur sprite */
int Partie::VerifCollision(sf::Sprite* spr1, sf::Sprite* spr2){			// 1 si collision, 0 sinon
	sf::Vector2f pos1 = spr1->getPosition();					// Création de deux zones correspondants aux deux sprites
	sf::FloatRect dim1 = spr1->getLocalBounds();
	sf::Vector2f s1 = spr1->getScale();

	sf::Vector2f pos2 = spr2->getPosition();
	sf::FloatRect dim2 = spr2->getLocalBounds();
	sf::Vector2f s2 = spr2->getScale();
    
    sf::RectangleShape bounds1(sf::Vector2f(dim1.width,dim1.height));
    bounds1.setPosition(pos1.x,pos1.y);
    bounds1.setRotation(spr1->getRotation());
	bounds1.setScale(s1);

	sf::RectangleShape bounds2(sf::Vector2f(dim2.width,dim2.height));
    bounds2.setPosition(pos2.x,pos2.y);
    bounds2.setRotation(spr2->getRotation());
	bounds2.setScale(s2);

	if (bounds1.getGlobalBounds().intersects(bounds2.getGlobalBounds()) == 1) return 1;		// Vérification de l'intersection entre les deux zones

	return 0;													// Sinon, on renvoie 0
}

/** @brief Méthode de vérification de collision pour un robot
 * @param spr1 : pointeur sur sprite du robot à tester */
int Partie::VerifCollisionGlobal(sf::Sprite* spr1){	
	if (VerifCollision(spr1,J1.getSprite())*VerifCollision(spr1,J2.getSprite()) == 1){			// 1 si le robot est en contact avec les deux
																								// Par définition, il est déjà en contact avec lui-même
		return 1;
	}

	for (const mur_ptr m : murs){													// Collisions robot et murs toujours existants
		if (m->getEtat() == true && VerifCollision(spr1, m->getMurSprite()) == 1){
			return 1;
		}
	}
	return 0;
}

/** @brief Méthode de mise à jour des armes
 * @param render : fenêtre d'affichage */
void Partie::UpdateArmes(SFMLRenderer& render){	
	J1.AvanceMissiles();														// Avancée des missiles
	J2.AvanceMissiles();

	for (const arme_ptr a : J1.getArmes()){										// Vérification des collisions pour les armes J1
		for (const mur_ptr m : murs){												// Armes J1/Murs
			if (VerifCollision(a->getArmeSprite(),m->getMurSprite())==1){

				if (m->getEtat() == true && a->getEtat() == true){
					a->Casser();
					m->Casser();
				}
				
			}
		}

		if (VerifCollision(a->getArmeSprite(),J2.getSprite())==1){					// Armes J1/J2
			if (a->getEtat() == true){												
				J2.setPtsDeVie(J2.getPtsDeVie()- a->getDegats());
				a->Casser();
			}
		}

    }

	for (const arme_ptr a : J2.getArmes()){										// Vérification des collisions pour les armes J2
		for (const mur_ptr m : murs){												// Armes J2/Murs
			if (VerifCollision(a->getArmeSprite(),m->getMurSprite())==1){

				if (m->getEtat() == true && a->getEtat() == true){
					a->Casser();
					m->Casser();
				}
			}
		}

		if (VerifCollision(a->getArmeSprite(),J1.getSprite())==1){					// Armes J2/J1
			if (a->getEtat() == true){
				J1.setPtsDeVie(J1.getPtsDeVie()- a->getDegats());
				a->Casser();
			}
		}
    }
}