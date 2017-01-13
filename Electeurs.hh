#pragma once

#include <iostream>
#include <random>
#include <time.h>

#include "Actif.hh"


class Electeurs : public Actif
{
	private: int nb_points;
		     
	
	public :Electeurs() {} 
		    ~Electeurs(){}
		    Electeurs (int _age, std::string _name):Actif (_age, _name){}
		    
			void setPoints(int x); 
			int getPoints();
			int voter();
			void afficher(); 
		
};
