#include "Candidat.hh"
 
using namespace std; 


void Candidat :: afficher ()
{ 
	cout << name <<": "<< nb_voix<<" voix"<<endl;
}

string Candidat::getName()
{
	return name;
}

int Candidat::getVoix()
{
	return nb_voix; 
}

int Candidat::getCompetence()
{
	return competence; 
}

void Candidat::setVoix(int x)
{
	nb_voix = x; 
}

void Candidat::setPopularite(bool x)
{
	popularite_enfant = x; 
}

