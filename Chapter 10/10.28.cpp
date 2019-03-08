#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<iterator> 

using namespace std;

int main(){
	vector<int> v = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
	list<int> l1, l2, l3;
	unique_copy(v.cbegin(), v.cend(), back_inserter(l1));
	unique_copy(v.cbegin(), v.cend(), inserter(l2, l2.begin()));
	unique_copy(v.cbegin(), v.cend(), front_inserter(l3));
	for(const auto c : l1)
		cout<<c<<" ";
	cout<<endl;
	for(const auto c : l2)
		cout<<c<<" ";
	cout<<endl;
	for(const auto c : l3)
		cout<<c<<" ";
	cout<<endl;
}
