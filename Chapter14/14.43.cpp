#include<functional>
#include<iostream>
#include<vector>

using namespace std;

bool modu(const vector<int>& v, const int& n){
	modulus<int> mod;
	for(const auto& i : v){
		if(mod(i, n))
			return false;
		else
			continue;
	}
	return true;
}
int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int n;
	cin>>n;
	cout<<modu(v, n);
}
