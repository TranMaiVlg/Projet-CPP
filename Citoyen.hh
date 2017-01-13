#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string>

class Citoyen 
{
	public: int age;
			std::string name;  
	
	public :Citoyen(){}
			virtual ~Citoyen(){}
			Citoyen (int _age, std::string _name) : age(_age), name(_name){} 
			
			void setName(std::string _name)
				{
					name = _name;
				}
				 
			std::string getName()
				{
					return name; 
				}
		
};
