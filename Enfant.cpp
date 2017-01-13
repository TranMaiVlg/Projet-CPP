#include "Enfant.hh"


int Enfant:: amadouer (Candidat& e)
{
	srand(time(NULL)); 
	int b = 200, a = 80; 
	if (e.getCompetence() <= 3) 
		return nb_friandises + rand ()% 100; 
	else 
		return nb_friandises + rand ()%(b-a+1)+a; 	 	
}

int Enfant::getFriandises ()
{
	return nb_friandises; 
}

