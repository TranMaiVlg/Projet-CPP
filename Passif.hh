#pragma once 

#include "Citoyen.hh"
#include "Actif.hh"


class Passif : public Citoyen
{	
	public :Passif(){} 
			Passif (int _age, std::string _name):Citoyen(_age, _name){}
			virtual ~Passif (){} 
		    
		    int amadouer () ; 
};
