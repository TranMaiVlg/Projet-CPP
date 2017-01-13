#pragma once 

#include <iostream>
#include <random>
#include <time.h>

#include "Passif.hh"
#include "Candidat.hh"


class Enfant : public Passif
{
	private: int nb_friandises; 
	
	public : Enfant(){}
			 ~Enfant(){}
			 Enfant (int _age,std::string _name, int _nb_friandises): Passif (_age, _name)
			{
				nb_friandises = _nb_friandises;
			}
			
			int amadouer (Candidat&);
			int getFriandises ();
	  
			
};


