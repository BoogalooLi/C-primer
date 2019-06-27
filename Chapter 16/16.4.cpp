#include<iostream>
#include<string>
#include<list>
#include<vector>

using namespace std;

template <typename T, typename U>
const T find(T b, T e, const U& u){
	for(; b != e; ++b){
		if(*b == u)
			return b;
	}
	return e;
}

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,0};
	list<string> l = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
	auto iv = find(v.begin(), v.end(), 7);
	cout<<*iv<<endl;
	auto il = find(l.begin(), l.end(), "4");
	cout<<*il<<endl;
} 
