#include<iostream>
#include<string>
#include<list>
#include<deque>

using namespace std;

int main(){
	list<int> lst;
	deque<int> odd, even;
	for(auto c : lst){
		switch(c%2){
			case 0:
				even.push_back(c);
				break;
			case 1:
				odd.push_back(c);
				break;
		}
	} 
}
