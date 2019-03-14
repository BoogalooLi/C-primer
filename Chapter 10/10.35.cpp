#include<iostream>
#include<list>
#include<vector>
#include<iterator> 

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	for(auto it = v.cend() - 1; it != v.cbegin() - 1; --it)
		cout<<*it<<" ";
	cout<<endl; 
}
