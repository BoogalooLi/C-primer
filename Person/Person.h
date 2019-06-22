#ifndef PERSON_H
#define PERSON_H

#include<string> 
#include<iostream> 

class Person{
	friend std::istream &read(std::istream &, Person &);
	friend std::ostream &print(std::ostream &, const Person &);
	
	private:
	std::string name;
	std::string address;
	int age;
	
	public:
	std::string person_name() const {return name;}
	std::string person_address() const {return address;}
	int person_age() const {return age;}
	 
	//���캯�� 
	Person() = default;
	explicit Person(const std::string &s) : name(s){}
	Person(const std::string &n, const std::string &a, const int &age) : name(n), address(a), age(age){}
	Person(std::istream&);
};

#endif
//���⺯�� 
std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);

inline Person::Person(std::istream &is){
	read(is, *this);
}
