#include "Fonctions.hh"

using namespace std;

void setAge(int &age) 
{	
	cout << "Quel age avez vous?"<< endl; 
	cin >> age; 
	if (age < 1 || age > 99)
	    throw string("L'age doit être compris entre 1 et 99");
}

void setReponse(char &reponse)
{
	cout << "O/N ?" << endl;
	cin >> reponse;
	if (reponse != 'O' && reponse != 'N' && reponse != 'o' && reponse != 'n')
		throw string("Veuillez entrer O ou N");
}

void setFriandises (int &nb_friandises)
{
	cin >> nb_friandises;
	if (nb_friandises < 0 || nb_friandises > 100)
		throw string("Le nombre de friandises doit être compris entre 0 et 100");
}

void setPoints (int &nb_pts)
{
	cin >> nb_pts;
	if (nb_pts < 0 || nb_pts > 100)
		throw string("Le nombre de points doit être compris entre 0 et 100");
}

void setCandidat (string &nom)
{
	cin >> nom;
	if (nom != "Aminata" && nom != "aminata" && nom != "AMINATA" && nom != "Tran" && nom != "tran" && nom != "TRAN")
		throw string ("Les 2 candidats sont Aminata et Tran et pas quelqu'un d'autre. Tapez l'un des deux noms !");
}

void setElecteurs (std::string &electeurs) 
{
	cin >> electeurs;
	if (electeurs != "philosophes" && electeurs != "Philosophes" && electeurs != "litteraires" && electeurs != "Litteraires" && electeurs != "scientifiques" && electeurs != "Scientifiques" && electeurs != "paresseux" && electeurs != "Paresseux") 
		throw string ("Veuillez entrer un nom de groupes d'électeurs");
}

void setAnciennete(int &anciennete) 
{	
	cin >> anciennete; 
	if (anciennete < 0 || anciennete > 6)
	    throw string("Etes-vous sur du nombre d'élections où vous êtes présenté ? Ressaisissez le !");
}

