#include "Joker.hh"

using namespace std;


int Joker::EnfantRevolutionnaire (Enfant& e1)
{
	return e1.getFriandises() * 3;	
}

int Joker::CandidatRevolutionnaire (Candidat& c1)
{
	if (c1.getCompetence() < 6)
		return 6; 
	else 
		return 0; //max de competences atteint le joker ne peut rien faire dans ce cas pour aider le candidat a avoir plus d'annees d'anciennete 
}
