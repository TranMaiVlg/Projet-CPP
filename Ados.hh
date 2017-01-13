#pragma once 

#include "Passif.hh"
#include "Electeurs.hh"

class Ados : public Passif
{	
	private : 
		int nb_points; 
		
	public :Ados() {}
			~Ados(){} 
			Ados (int _age, std::string _name, int _nb_points): Passif(_age, _name)
			{ 
				nb_points = _nb_points;
			}
			
			int amadouer (Electeurs&); 
			int getPoints(); 			 
};
