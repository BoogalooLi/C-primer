#include<string>
#include <vector>
#include <utility>
#include <map>
#include<algorithm>
#include <iostream>

using namespace std;

string delete_multimap(multimap<string, string> &mlmp, const string &s){
	auto pos = mlmp.find(s);
	if(pos != mlmp.end()){
		mlmp.erase(pos);
		return "complete";
	}
	else
		return "this key isn't in this multimap, pls change another one";
}

void print_multimap(multimap<string, string> &mlmp){
	for(const auto& c: mlmp)
		cout<<c.first<<" "<<c.second<<endl;
	cout<<endl;
}

int main(){
}
