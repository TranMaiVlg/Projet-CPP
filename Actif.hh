#pragma once 
#include "Citoyen.hh"

class Actif : public Citoyen 
{		
	public :Actif(){}
			virtual ~Actif() {}
			Actif(int _age, std::string _name):Citoyen(_age, _name){} 
			
			void afficher() ;			
};  
