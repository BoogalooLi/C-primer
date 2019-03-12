#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<iterator> 
#include<fstream>

using namespace std;

int main(){
	ifstream input("in.txt"); //your file name
	istream_iterator<string> in(input);
	istream_iterator<string> end;
	vector<string> v;
	while(in != end)
		v.push_back(*in++);
		
	for(auto c : v)
		cout<<c<<" ";
		
	cout<<endl;
}
