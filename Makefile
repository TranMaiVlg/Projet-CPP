all: VIDI

CXXFLAGS= g++ -Wall -g --std=c++11

VIDI : Ados.o Candidat.o Electeurs.o Election.o Enfant.o Fonctions.o Joker.o
	 g++ -g Ados.o Candidat.o  Electeurs.o Election.o Enfant.o Fonctions.o Joker.o -o VIDI


Ados.o : Ados.cpp Ados.hh Passif.hh Citoyen.hh
	 	$(CXXFLAGS) -c Ados.cpp
	
Candidat.o : Candidat.cpp Candidat.hh 
	$(CXXFLAGS) -c Candidat.cpp
	
Electeurs.o : Electeurs.cpp Electeurs.hh 
	$(CXXFLAGS) -c Electeurs.cpp

Election.o : Election.cpp 
	$(CXXFLAGS) -c Election.cpp

Enfant.o : Enfant.cpp Enfant.hh Passif.hh Citoyen.hh
	$(CXXFLAGS) -c Enfant.cpp

Fonctions.o : Fonctions.cpp Fonctions.hh
	$(CXXFLAGS) -c Fonctions.cpp
		
Joker.o : Joker.cpp Joker.hh
	$(CXXFLAGS) -c Joker.cpp

clean :
	rm -f *.o *~ VIDI
	
test :
	./VIDI
