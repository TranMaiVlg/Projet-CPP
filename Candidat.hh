#pragma once  

#include "Actif.hh"
#include "Citoyen.hh"
#include <iostream>

class Candidat : public Actif 
{
	private : int nb_voix;
			  int competence; //les competences sont relatives au nombre de fois que le candidat s est presente
			  bool popularite_enfant;
	
	public :Candidat() {} 
			~Candidat(){}
			Candidat(int _age, std::string _name, int _competence): Actif (_age, _name) 
			{
				competence =_competence; 
			}
			
			 friend std::ostream& operator<<(std::ostream& out, Candidat& c)
			 {
				out << "NOM :		"<< c.name ;
				out<<std::endl; 
				out << "AGE :		"<< c.age;
				out << std::endl;
				out << "COMPETENCES: 	"<< c.competence;
				out << std::endl; 
				return out; 
			 }
			 
			 void afficher ();
			 std::string getName();
			 int getVoix(); 
			 void setVoix(int); 
			 int getCompetence(); 
			 void setPopularite (bool x); 
				
};
