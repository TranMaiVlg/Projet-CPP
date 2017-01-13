#pragma once 

#include <iostream>

#include "Enfant.hh"
#include "Candidat.hh"

class Joker 
{
	public : Joker (){}
			 ~Joker (){}
			  
			int EnfantRevolutionnaire (Enfant&); 
			int CandidatRevolutionnaire(Candidat&); 
			
};
