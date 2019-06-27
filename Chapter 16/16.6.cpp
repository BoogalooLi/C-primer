#include<iostream>


using namespace std;

template <typename T, unsigned M>
const T* begin(const T (&array)[M]){
	return array;
}

template <typename T, unsigned M> //"" useful, int useless
const T* end(const T (&array)[M]){
	
	return array + M - 2;
}


int main(){
	
	auto b = begin("123456789");
	cout<<*b<<endl;
	
	auto e = end("123456789");
	cout<<*e<<endl;
	
} 
