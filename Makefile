LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

all : jeu

jeu : main.o partie.o sfml_renderer.o cassable.o incassable.o robot.o missile.o mine.o
	g++ main.o partie.o sfml_renderer.o cassable.o incassable.o robot.o missile.o mine.o -o jeu $(LIBS)
	
main.o : main.cpp partie.hpp sfml_renderer.hpp
	g++ -c main.cpp

partie.o : partie.cpp partie.hpp mur.hpp sfml_renderer.hpp robot.hpp
	g++ -c partie.cpp

cassable.o : cassable.cpp cassable.hpp mur.hpp
	g++ -c cassable.cpp

incassable.o : incassable.cpp incassable.hpp mur.hpp
	g++ -c incassable.cpp

robot.o : robot.cpp robot.hpp 
	g++ -c robot.cpp

sfml_renderer.o : sfml_renderer.cpp sfml_renderer.hpp cassable.hpp incassable.hpp robot.hpp missile.hpp mine.hpp
	g++	-c sfml_renderer.cpp

missile.o : missile.cpp missile.hpp arme.hpp
	g++ -c missile.cpp

mine.o : mine.cpp mine.hpp arme.hpp
	g++ -c mine.cpp

clean : 
	rm -f *.o

vclean : 
	rm -f jeu
