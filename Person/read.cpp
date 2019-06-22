#include"Person.h"

std::istream &read(std::istream &is, Person &p){
	is>>p.name>>p.address;
	return is;
}
