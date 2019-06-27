#include<iostream>


using namespace std;

template <typename T, unsigned M>
void print(const T (&array)[M]){
	for(const auto& ele : array)
		cout<<ele<<endl;
}


int main(){
	int a[5] = {1,2,3,4,5};
	print(a);
} 
