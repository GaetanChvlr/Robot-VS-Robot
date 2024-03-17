/** @file main.cpp
 * @brief Main projet "Robot vs Robot"
 * @author Gaëtan Chevalier
 * @author Hugo Correas
 * @date 03/04/2023	*/

#include "partie.hpp"

int main(int argc, char* argv[])
{
	Partie* P = new Partie(10);					 	// Création de la partie	
	
	SFMLRenderer* render =  new SFMLRenderer();		// Création de la fenêtre d'affichage
	
	P->PartieEnCours(*render);						// Lancement de la partie

	delete render;									
	delete P;

	return 0;
}
