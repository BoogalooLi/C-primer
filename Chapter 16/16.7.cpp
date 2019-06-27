#include<iostream>


using namespace std;



template <typename T, unsigned N>
constexpr int Size(T (&arr)[N]){
	return N - 1;
}

int main(){
	cout<<Size("1234567890")<<endl;
} 
