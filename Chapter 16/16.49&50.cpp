#include<iostream>
#include<string>

using namespace std;

template <typename T> void f(T) { cout<<"f(T)"<<endl; }
template <typename T> void g(T) { cout<<"g(T)"<<endl; }
template <typename T> void f(const T*) { cout<<"f(const T*)"<<endl; }
template <typename T> void g(T*) { cout<<"g(T*)"<<endl; }

int main(){
	int i = 42;
	int* p1 = &i;
	const int ci = 0;
	const int* p2 = &ci;
	
	g(42);
	f(42);
	
	g(p1);
	f(p1);
	
	g(ci);
	f(ci);
	
	g(p2);
	f(p2);
}
