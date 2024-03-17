/** @file sfml_renderer.cpp
 * @brief Définitions méthodes classe SFMLRenderer
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#include "sfml_renderer.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <unistd.h>

/** @brief Constructeur */
SFMLRenderer::SFMLRenderer()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Robot vs Robot");
    window->setFramerateLimit(80);
    remiseArrierePlan(0,0);
}

/** @brief Méthode d'affichage arrière-plan
 * @param PJ1 : points de vie restants J1
 * @param PJ2 : points de vie restants J2 */
void SFMLRenderer::remiseArrierePlan(int PJ1, int PJ2){
    // Chargement image de fond
    sf::Texture background;
    background.loadFromFile("images/fond.jpg");

    // Création sprite d'arrière-plan
    sf::Sprite backgroundSprite(background);

    // Taille du fond
    backgroundSprite.setScale(sf::Vector2f(80.0/65.6, 80/65.6));

    // Affichage arrière-plan
    window->draw(backgroundSprite);

    // Affichage points de vie
    this->affichePtsDeVie(PJ1,PJ2);
}

/** @brief Méthode d'affichage points de vie
 * @param PJ1 : points de vie restants J1
 * @param PJ2 : points de vie restants J2 */
void SFMLRenderer::affichePtsDeVie(int PJ1, int PJ2){
    sf::Font Police;                // Chargement police
    Police.loadFromFile("afterhours.ttf");
    
    sf::Text PdV1;                  // Création texte 1
    PdV1.setFont(Police);

    std::string s1 = "J1 : ";
    s1.append(std::to_string(PJ1));
    PdV1.setString(s1);
    PdV1.setPosition(10,0);
    PdV1.setFillColor(sf::Color::White);

    sf::Text PdV2;                  // Création texte 2
    PdV2.setFont(Police);

    std::string s2 = "J2 : ";
    s2.append(std::to_string(PJ2));
    PdV2.setString(s2);
    PdV2.setFillColor(sf::Color::White);
    PdV2.setPosition(10,30);

    window->draw(PdV1);             // Affichage
    window->draw(PdV2);
}

/** @brief Méthode d'affichage mur cassable
 * @param c : objet à afficher */
void SFMLRenderer::afficheCassable(Cassable& c){
    int X = c.getMurSprite()->getPosition().x;
    int Y = c.getMurSprite()->getPosition().y;
    int TX = c.getLongueur();
    int TY = c.getLargeur();

    // Chargement image cassable
    sf::Texture mur_texture;
    mur_texture.loadFromFile("images/cassable.jpg");

    // Récupération du sprite
    sf::Sprite* mur_sprite = c.getMurSprite();

    // MAJ de la texture
    mur_sprite->setTexture(mur_texture);

    // Position du sprite
    mur_sprite->setPosition(X,Y);

    // Taille du mur
    mur_sprite->setScale(sf::Vector2f(float(TX)/30.0, float(TY)/30.0));

    // Affichage
    window->draw(*mur_sprite);
}

/** @brief Méthode d'affichage mur incassable
 * @param i : objet à afficher */	
void SFMLRenderer::afficheIncassable(Incassable& i){
    int X = i.getMurSprite()->getPosition().x;
    int Y = i.getMurSprite()->getPosition().y;
    int TX = i.getLongueur();
    int TY = i.getLargeur();

    // Chargement image incassable
    sf::Texture mur_texture;
    mur_texture.loadFromFile("images/incassable.jpg");

    // Récupération du sprite
    sf::Sprite* mur_sprite = i.getMurSprite();

    // MAJ de la texture
    mur_sprite->setTexture(mur_texture);

    // Position du sprite
    mur_sprite->setPosition(X,Y);

    // Taille du mur
    mur_sprite->setScale(sf::Vector2f(float(TX)/5.0, float(TY)/5.0));

    // Affichage
    window->draw(*mur_sprite);
}

/** @brief Méthode d'affichage robot
 * @param r : objet à afficher 
 * @param nJoueur : numéro du joueur associé*/
void SFMLRenderer::afficheRobot(Robot& r, int nJoueur){
    int X = r.getSprite()->getPosition().x;
    int Y = r.getSprite()->getPosition().y;
    int O = r.getSprite()->getRotation();

    // Chargement image robot
    sf::Texture robot_texture;
    if (nJoueur == 1) robot_texture.loadFromFile("images/robot1.png");
    else robot_texture.loadFromFile("images/robot2.png");

    // Récupération du sprite robot
    sf::Sprite* robot_sprite = r.getSprite();

    // MAJ de la texture
    robot_sprite->setTexture(robot_texture);

    // Affichage robot
    window->draw(*robot_sprite);
}

/** @brief Méthode d'affichage missile
 * @param m : objet à afficher 
 * @param nJoueur : numéro du joueur associé */
void SFMLRenderer::afficheMissile(Missile& m, int nJoueur){
    // Chargement image missile
    sf::Texture missile_texture;
    if (nJoueur == 1) missile_texture.loadFromFile("images/missile1.png");
    else missile_texture.loadFromFile("images/missile2.png");

    // Récupération du sprite
    sf::Sprite* arme_sprite = m.getArmeSprite();

    // MAJ de la texture
    arme_sprite->setTexture(missile_texture);

    // Taille du sprite
    arme_sprite->setScale(sf::Vector2f(10.0/254.0, 37.0/980.0));

    // Affichage
    window->draw(*arme_sprite);
}

/** @brief Méthode d'affichage mine
 * @param n : objet à afficher 
 * @param nJoueur : numéro du joueur associé */
void SFMLRenderer::afficheMine(Mine& n, int nJoueur){
    // Chargement image mine
    sf::Texture mine_texture;
    if (nJoueur == 1) mine_texture.loadFromFile("images/mine1.png");
    else mine_texture.loadFromFile("images/mine2.png");

    // Récupération du sprite
    sf::Sprite* arme_sprite = n.getArmeSprite();

    // MAJ de la texture
    arme_sprite->setTexture(mine_texture);
    
    // Taille du sprite
    arme_sprite->setScale(sf::Vector2f(10.0/254.0, 90.0/980.0));

    // Affichage
    window->draw(*arme_sprite);
}

/** @brief Méthode de gestion de fin de partie
 * @param nPerdant : numéro du joueur perdant */
void SFMLRenderer::finDePartie(int nPerdant){
    // Nouveau fond
    sf::RectangleShape Fond(sf::Vector2f(800,800));
    Fond.setPosition(sf::Vector2f(0,0));
    Fond.setFillColor(sf::Color::Black);
    window->draw(Fond);

    // Affichage texte
    sf::Font Police;
    Police.loadFromFile("afterhours.ttf");
    sf::Text Txt;
    Txt.setFont(Police);

    if (nPerdant == 1){
        Txt.setFillColor(sf::Color::Blue);
        Txt.setString("Victoire Joueur 2 !");
    }
    else{
        Txt.setFillColor(sf::Color::Red);
        Txt.setString("Victoire Joueur 1 !");
    }

    Txt.setCharacterSize(40);
    Txt.setPosition(sf::Vector2f(240,350));

    window->draw(Txt);
    window->display();

    sleep(3);                   // Attente avant fermeture de la fenêtre

    window->close();

}