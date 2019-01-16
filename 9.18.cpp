#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(){
	string str;
	deque<string> d;
	while(cin>>str){
		d.push_back(str);
	}
	for(auto it = d.cbegin() ; it != d.cend(); ++it)
		cout<<*it<<endl;
}
