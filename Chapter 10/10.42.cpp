#include<iostream>
#include<list>
#include<vector>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
	list<string> lst = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	lst.sort();
	lst.unique();
	for(auto c : lst)
		cout<<c<<" ";
	cout<<endl;
}
