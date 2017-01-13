#include <iostream>
#include <vector>
#include <string>

#include "Enfant.hh"
#include "Candidat.hh"
#include "Joker.hh"
#include "Electeurs.hh"
#include "Ados.hh"
#include "Fonctions.hh"


using namespace std; 


int main ()
{
	const int age_min = 35, popularite_min = 60 ;
	
	//Groupe d'electeurs existant lors de l'election
	vector <Electeurs> E;
	Electeurs E1(46, "Scientifiques");
	Electeurs E2(71, "Philosophes");
	Electeurs E3(54, "Litteraires");
	Electeurs E4(38, "Paresseux");
	E.push_back(E1);E.push_back(E2);E.push_back(E3);E.push_back(E4);	
	
	
	cout <<"***************************Bienvenue dans VIDI********************************"<<endl;  cout<<endl; cout<<endl; 
	cout <<"Les élections approchent. Elles nécessitent l'implication de tout le monde:"<<endl; 
	cout <<"Enfants Adolescents Adultes chacun a son importance "<<endl; cout <<endl;  
	cout << "Si vous êtes prêt, découvrons les élections dans ce monde de révolutionnaires "<<endl; cout<<endl;  
	cout << "-------Commencez par renseigner votre nom------------- "<< endl; 
	string nom; cin >> nom; 
	cout << "---------------Joli prénom!----------------"<<endl; cout<<"On espère qu'il vous portera chance!"   << endl;cout<<endl; 
	cout <<"Quel âge avez vous?"<<endl; 
	int age; cin >>age; 
	while (age < 1 || age > 99) 
	{
		try
		{
			setAge(age);
		}
		catch(string const& chaine)
		{
		    cerr << chaine << endl;
		}
	}
	// USER = citoyen passif 
	if (age < age_min)  
	{
		cout << "Nous vous rappelons que l'age minimal pour être candidat est fixé à :"<< age_min << "ans!!"<< endl;
		cout << "Vous ne pouvez donc être candidat"<< endl;
		cout << "Par contre, vous pouvez soutenir le candidat de votre choix"<< endl;cout<<endl; cout<<endl; 	
		Candidat c1(45,"AMINATA",2) ;
		Candidat c2 (88, "TRAN_MAI",5);
		cout <<"**********Candidats*********"<<endl; cout<<endl; 
		cout<<"**************************************Premier Candidat*************************************"<<endl; cout<<endl; 
		cout << c1 << endl;cout<<endl;
		cout<<"**************************************Deuxieme Candidat*************************************"<<endl; cout<<endl;   
		cout << c2 << endl;cout<<endl; 
		 
		//User = ENFANT  NE PEUT QUE SOUTENIR UN CANDIDAT
		if (age < 15)  
		{
			cout << "Comme vous l'avez remarqué, Tran est vieux mais a plus de chances de gagner que Aminata qui est jeune "<<endl; 
			cout << "C'est la règle dans VIDI"<< endl;cout<<"Mais, c'est quand même révoltant!"<<endl;  
			cout << "Si tu souhaites changer cette situation, TU PEUX FAIRE QUELQUE CHOSE "<< endl; 
			cout << "Etant enfant, tu peux directement influer sur le vote du candidat contrairement aux ados "<< endl; 
			cout<< "Combien de friandises souhaitez vous donner au candidat *** "<< c1.getName() << " ***?" << endl; 
			int nb_friandises;cin >>nb_friandises;
			while (nb_friandises < 0 || nb_friandises > 100) 
			{
				try
				{
					setFriandises(nb_friandises);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
			Enfant e1 (age, nom, nb_friandises);c1.setVoix(e1.amadouer(c1));
			cout<< "Combien de friandises souhaitez-vous donner au candidat *** "<< c2.getName() << " ***?" << endl; cin >>nb_friandises;  
			while (nb_friandises < 0 || nb_friandises > 100) 
			{
				try
				{
					setFriandises(nb_friandises);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
			Enfant e2(age, nom, nb_friandises); c2.setVoix(e2.amadouer(c2)); 
			cout <<"Vous avez donné plus de friandises a votre candidat prefere normalement. Mais cela ne suffit pas,cela ne lui est pas bénéfique peut etre"; 
			cout << endl; 
			cout << "Souhaites tu changer cette situation en faisant appel au joker. O/N" <<endl; 
			char reponse; cin >> reponse; 
			while (reponse != 'O' && reponse != 'N' && reponse != 'o' && reponse != 'n')
			{
				try
				{
					setReponse(reponse);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
			//ENFANT REVOLUTIONNAIRE 
			if (reponse == 'O' || reponse == 'o')
			{
				cout << "On va donc faire appel au ***chef des revolutionnaires Mc Joker*** afin de nous aider à donner toutes les chances à ce candidat"<<endl; 
				Joker j1; 
				int piege = j1.EnfantRevolutionnaire(e1);  //Mc Joker va gonfler l apport de cet enfant pour le vote de son candidat préféré 
				cout <<"Qui est votre candidat préféré? Aminata ou Tran ? "<< endl;
				string nom;	cin >> nom;  
				while (nom != "Aminata" && nom != "aminata" && nom != "Tran" && nom != "tran")
				{
					try	
					{
						setCandidat(nom);
					}
					catch(string const& chaine)
					{
						cerr << chaine << endl;
					}
				}
				if (nom == "Aminata" || nom == "aminata")
				{
					c1.setVoix(c1.getVoix()+piege) ;	
				} 
				if (nom == "Tran" || nom == "tran")
				{
					c2.setVoix(c2.getVoix()+piege );
				}
			}
			//ENFANT NON REVOLUTIONNAIRE 
			else if(reponse == 'N' || reponse == 'n')	  
			{
				c1.setVoix(e1.amadouer(c1)) ;
				c2.setVoix(e2.amadouer(c2)) ;
			}
			cout<<endl; cout<<endl; cout<<endl; 
			cout<< "***********************Deliberation Campagne Enfant**********************************"<<endl; cout<<endl; cout<<endl; 
			cout << "************************Premier Candidat********************************************"<<endl; 
			c1.afficher(); 
			cout <<endl;cout<<endl;
			cout << "************************Deuxieme Candidat********************************************"<<endl;   
			c2.afficher();cout <<endl;cout<<endl;  
			if (c1.getVoix() < c2.getVoix())
				{cout << "Félicitations à " << c2.getName() << " qui est l'heureux gagnant de cette élection !" << endl;cout<<endl;} 
			else
				{cout << "Félicitations à " << c1.getName() << " qui est l'heureux gagnant de cette élection !" << endl;cout<<endl;} 
		} 
		// User = ADO   donne juste un nbre de points a son groupe delecteurs  
		else 
		{
			cout << "En tant qu'ADOLESCENT, tu peux avoir une importante influence sur les électeurs."<< endl;
			cout << "Aminata est un jeune ingénieur, les scientifiques le soutiennent." << endl;
			cout << "Tran est un écrivain qui a déjà publié plusieurs best-sellers, les littéraires l'adorent." << endl;cout << endl;
			cout << "Quatre groupes d'électeurs, Va falloir choisir celui qui va soutenir le candidat ayant la même idéologie que toi " << endl;cout<<endl; 
			for (unsigned int i = 0; i != E.size(); ++i)
			{
				E[i].afficher();
			}
			cout <<"************************ATTENTION choix crucial !*********************************" << endl;cout<<endl; 
			cout << "Choisis le groupe auquel tu souhaites te joindre. "<<endl; 
			string electeurs; cin >> electeurs; 
			while (electeurs != "philosophes" && electeurs != "Philosophes" && electeurs != "litteraires" && electeurs != "Litteraires" && electeurs != 			"scientifiques" && electeurs != "Scientifiques" && electeurs != "paresseux" && electeurs != "Paresseux") 
			{
				try	
				{
					setElecteurs(electeurs);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
			cout << "Les compteurs sont à zéro! A toi de leur en donner. Plus y a de points, plus l'impact sur les élections sera important" << endl;cout<<endl; 
			cout << "Combien de points souhaitez vous donner pour soutenir les " << electeurs << " ?" << endl;
			int nb_points; cin>>nb_points;  
 			while (nb_points < 0 || nb_points > 100) 
			{
				try
				{
					setPoints(nb_points);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
			Ados a1 (age, nom, nb_points);
			if (electeurs == "scientifiques" || "Scientifiques")
				c1.setVoix(a1.amadouer (E1));	
			if (electeurs == "philosophes" || "Philosophes")
				a1.amadouer (E2);
			if (electeurs == "litteraires" || "Litteraires")
				a1.amadouer (E3);
			if (electeurs == "paresseux" || "Paresseux")
				a1.amadouer (E4);
	
			cout<< "******************Délibération Campagne Ados**********************************"<<endl; cout<<endl; 
			
			cout << "************************Deuxieme Candidat********************************************"<<endl; cout << endl; 
			c2.afficher();cout << endl;  
			if (c1.getVoix() < c2.getVoix())
				c2.afficher();
			else
				c1.afficher();
		} 
	}
	//utilisateur = actif   
	else  
	{
		cout << "Vous avez l'âge pour être candidat. Souhaitez-vous vous présenter à cette élection ?" << endl; 
		char reponse; cin >>reponse; 
		while (reponse != 'O' && reponse != 'N' && reponse != 'o' && reponse != 'n')
		{	
			try
			{
				setReponse(reponse);
			}
			catch(string const& chaine)
			{
				cerr << chaine << endl;
			}
		}

		//utilisateur = candidat 
		if (reponse == 'O' || reponse == 'o')   
		{
			cout << "Veuillez renseigner le nombre de fois que vous vous présentez aux élections"<< endl; 			
			cout << "Ceci augmente vos chances de gagner. " << endl; 
			cout << "A VIDI, on compte sur votre honnetete, si les informations s'averent fausses, vous etes suspendus" << endl; 
			int anciennete; cin >> anciennete; 
			cout << endl; 
			while (anciennete < 0 || anciennete > 6)
			{
				try
				{
					setAnciennete(anciennete);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
	
			// Creer a partir de ce moment un candidat conforme a l utilisateur 
			Candidat C_user (age, nom, anciennete);  //idee d amelioration pour le rapport Ajouter un attribut argent at a chauqe fois que le candidat veut faire 															appel au joker il perd de l argent
			Candidat Ca(54,"Adversaire",2);
			cout << "*******************				Veuillez vous preparer!			****************************" << endl; 
			cout << "Les enfants et adolescents ne votent pas dans VIDI MAIS............"<< endl; 
			cout << "Leurs soutiens peuvent tout faire basculer !" << endl;

			//deroulement du vote
			cout  << "*******Campagne Enfant*******"<< endl; 
			Enfant e; 
			//les enfants donnent aux candidats des friandises "aleatoirement" en tenant compte de son anciennete
			C_user.setVoix (e.amadouer(C_user));
			Ca.setVoix(e.amadouer(Ca));   
			
			cout << "--------------- Deliberation Campagne Enfant--------------------" << endl; 
			Ca.afficher();
			C_user.afficher();
			  
			if (C_user.getVoix() > popularite_min)
			{
				C_user.setPopularite(true) ; 
				cout << "Ca sent bon pour vous! Les enfants ont l'air de vous apprecier. " << endl;
			}	
			else
			{
				C_user.setPopularite(false);   
				cout << "Bon courage pour la suite des elections" << endl;	
			}
			cout << "******************Campagne Ados*********************" << endl;
			cout << "Quel est votre idée de développement ?"<<endl; 
			cout << endl; 
			string ideologie;
			for (unsigned int i = 0; i != E.size(); ++i)
			{
				E[i].afficher();
				cout << endl; 
			}
			cout << endl;  
			cin >> ideologie; 
			cout << "On rappelle les normes de cette campagne"<<endl; 
			cout << "Vous ne recoltez pas des points directement, les ados n'ont pas d'influence directe comme les enfants, MAIS peuvent vous aider à obtenir un 				max d'électeurs"<<endl;
			Ados a;     
			Electeurs e2;
			e2.setPoints (e2.voter()+a.amadouer (e2)); 
			int n = e2.getPoints();
			e2.setPoints(e2.voter()+a.amadouer(e2)); 
			int m = e2.getPoints();
			Ca.setVoix(m);
			cout << "Votre groupe d'électeurs vous a récolté " << n << "points" << endl; 
			C_user.setVoix(n);
			cout << "Ce qui vous fait un total de :";
			C_user.afficher();
			cout << "voix" << endl;  
			if ((C_user.getVoix())  < (Ca.getVoix()))
			{
				cout << "Vous etes l'heureux gagnant de cette élection "<<endl; 
				cout << endl; 
				cout << "Vous etes le président "<<endl; 
				cout << "Bonne chance pour ce mandat"<<endl; 
			}
			if ((C_user.getVoix())  > (Ca.getVoix()))
			{
				cout << " - - "<<endl; 
				cout << "  ^"<<endl; 
				cout << "Vous avez perdu cette élection"<<endl;   
			}
			else 
			{
				cout << "Vous êtes à égalité et dans ce cas, le candidat le plus ancien sera élu"<<endl; 
				cout << "Si vous souhaitez changer cette situation, faiites appel au joker"<<endl; 
				cout << "Le souhaitez-vous? O/N"<<endl; 
				char appel; cin >> appel; 
				if (appel == 'O')  //le joker va permettre au candidat d avoir le max de competence qui est fixé a 6
				{
					Joker j; 
					j.CandidatRevolutionnaire(C_user);
					
					if ((C_user.getCompetence())  < (Ca.getCompetence()))
					{
						cout << "Gagnant: "<<Ca.getName()<<endl;
						cout << "Le joker n'a rien pu faire pour vous"<<endl;  	
					}
					else 
					{
						cout <<"Gagnant: "<< C_user.getName()<<endl; 
					} 	
				}
				else if (appel == 'N')
				{
					if ((C_user.getCompetence())  < (Ca.getCompetence()))
					{
						cout << "Gagnant: "<<Ca.getName()<<endl; 	
					}
					else 
					{
						cout <<"Gagnant: "<< C_user.getName()<<endl; 
					}
				}	
			}
		
		}



		else // Utilisateur est un electeur en utilisant les points recoltes aupres des ados 
		{
			cout << "Vous pouvez soutenir le candidat de votre choix";
			cout <<"Voici les groupes existant dans VIDI "<<endl; 
			for (unsigned int i = 0; i != E.size(); ++i)
			{
				E[i].afficher();
			}
			cout << "Choisis auquel des groupes d'électeurs tu veux te joindre. ATTENTION c'est un choix crucial !" << endl;
			string electeurs; cin >> electeurs; 
			while (electeurs != "philosophes" && electeurs != "Philosophes" && electeurs != "litteraires" && electeurs != "Litteraires" && electeurs != 			"scientifiques" && electeurs != "Scientifiques" && electeurs != "paresseux" && electeurs != "Paresseux") 
			{
				try	
				{
					setElecteurs(electeurs);
				}
				catch(string const& chaine)
				{
					cerr << chaine << endl;
				}
			}
			Electeurs e3; Ados a3;   
			vector <Candidat> v1; 
			Candidat c3(74,"MELAINE",true) ;
			Candidat c4 (33, "SHAGUFTA",false);
			v1.push_back(c3);v1.push_back(c4); 
			cout <<"*******************Candidats******************"<<endl;; 
			for (unsigned int i =0; i!= v1.size(); ++i)
			{
				v1[i].afficher();cout <<endl;  
			}
			cout<<endl; 
			int n = a3.amadouer(e3); e3.setPoints(n);
			c3.setVoix(e3.getPoints());
			int m = a3.amadouer(e3); e3.setPoints(m); 
			c4.setVoix(e3.getPoints()); 
			cout << "A l'issue de ce vote, voici les points accordés aux candidats par la nation vidienne"<<endl; 
			cout<< c3.getName()<<" :"<<c3.getVoix()<<" voix";
			cout <<c4.getName()<<" :"<<c4.getVoix()<<" voix"; 
		
		}
	
			
	}
	
}
