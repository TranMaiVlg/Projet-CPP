#include "Electeurs.hh"

using namespace std; 

int Electeurs::voter()
{
	int vote = rand()% 3;
	return vote*this-> nb_points; 
}

void Electeurs::afficher()
{
	cout << name << endl;
}

void Electeurs::setPoints(int x)
{
	nb_points = x;
}

int Electeurs::getPoints()
{
	return nb_points;
}

