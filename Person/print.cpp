#include"Person.h"

std::ostream &print(std::ostream &os, const Person &p){
	os<<p.person_name()<<" "<<p.person_address();
	return os;
}


