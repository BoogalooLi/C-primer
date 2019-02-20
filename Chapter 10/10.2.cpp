#include<iostream>
#include<algorithm>
#include<string>
#include<list>

using namespace std;

int main(){
	string str = "good";
	list<string> lst= {"good", "good", "study", "day", "day", "up" };//test
	auto result = count(lst.cbegin(), lst.cend(), str);
	cout<<result; 
} 
