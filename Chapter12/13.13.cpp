#include<iostream>
#include<vector>
#include<memory>

using namespace std;

struct X{
	X(){ cout<<"X()"<<endl;}
	X(const X&){ cout<<"X(const X&)"<<endl;}
	X& operator=(const X&){ cout<<"X operator="<<endl;}
	~X(){ cout<<"~X()"<<endl;};
	int x; 
};

void A(){
	X a;
	auto b = a;
}

void B(){
	X a, b;
	b = a;
} 

void C(){
	X x1, x2;
	vector<X> a1 = {x1};
	vector<X> a2 = {x1, x2};
}

void D(X x){ }

X D1(X x){ return x;}

void E(X& x){ }

X& E1(X& x){ return x;}

void F(){ 
	shared_ptr<X> a(new X());	
}

void F1(X x){
	shared_ptr<X> a = make_shared<X>(x);
}

void F12(X& x){
	shared_ptr<X> a = make_shared<X>(x);
}
shared_ptr<X> F2(X x){
	shared_ptr<X> a = make_shared<X>(x);
	return a;
}

shared_ptr<X> F21(X& x){
	shared_ptr<X> a = make_shared<X>(x);
	return a;
}

int main(){
	A();
	B();
	C();
	X x;
	D(x);
	E(x);
	D1(x);
	E1(x);
	F();
	F1(x);
	F12(x);
	F2(x);
	F21(x);
}

/*
X()
X(const X&)
~X()
~X()
X()
X()
X operator=
~X()
~X()
X()
X()
X(const X&)
X(const X&)
~X()
X(const X&)
X(const X&)
X(const X&)
X(const X&)
~X()
~X()
~X()
~X()
~X()
~X()
~X()
X()
X(const X&)
~X()
X(const X&)
X(const X&)
~X()
~X()
X()
~X()
X(const X&)
X(const X&)
~X()
~X()
X(const X&)
~X()
X(const X&)
X(const X&)
~X()
~X()
X(const X&)
~X()
~X()
*/
