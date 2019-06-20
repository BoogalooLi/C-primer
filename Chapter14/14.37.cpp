#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


struct Compare{
	bool operator()(const int& i1, const int& i2 = 0){
		return i1 == i2;
	}
};

int main(){
	Compare com;
	vector<int> v1 = {1,2,3,4,5,6,7,8,9,0,9,86,56,46,6,56,46,55,64,0,9,6,767,6,7,5};
	replace_if(v1.begin(), v1.end(), com, 100);
	for(auto c : v1)
		cout<<c<<" ";
}

