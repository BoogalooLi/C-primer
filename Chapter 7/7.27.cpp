#include<iostream>
#include"Lscreen.h"

using namespace std;

int main(){
	Lscreen m1(5,5,'X');
	m1.move(4,0).set('#').display(cout);
	cout<<"\n";
	m1.display(cout);
	cout<<"\n";
}
