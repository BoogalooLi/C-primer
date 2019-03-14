#include<iostream>
#include<list>
#include<vector>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
	list<int> l = {1,2,3,4,5,6,7,8,9,10,12,0,423,234,3423,0,543,2,34,0,44,12,3,4,5};
	int val = 0;
	auto it = find(l.crbegin(), l.crend(), val);
  //list don't support operator - for iterators and at(), []
	int i = 0;
	while(it != l.crend()){
		++it;
		++i;
	}
	cout<<i;
}
