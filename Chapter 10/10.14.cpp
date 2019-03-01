#include<iostream>

using namespace std;

int main(){
	auto he = [] (const int& a, const int& b) -> int {	return a + b;	};
	
	cout<<he(5,8);
}
