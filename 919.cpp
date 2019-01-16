#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(){
	string str;
	list<string> l;
	while(cin>>str){
		l.push_back(str);
	}
	for(auto it = l.cbegin() ; it != l.cend(); ++it)
		cout<<*it<<endl;
}
