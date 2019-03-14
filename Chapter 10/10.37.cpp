#include<iostream>
#include<list>
#include<vector>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,0};
	list<int> l(5);
	copy(v.cbegin() + 3, v.cend() - 2, l.rbegin()) ;//no const iterator for list here, because const iterators are read-only
	for(auto c : l)
		cout<<c<<" ";
	cout<<endl;
}
