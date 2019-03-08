#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<iterator> 

using namespace std;

int main(){
	vector<int> v = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
	list<int> l;
	unique_copy(v.cbegin(), v.cend(), back_inserter(l));
	for(const auto c : l)
		cout<<c<<" ";
}
