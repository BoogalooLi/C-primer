#include<iostream>
#include<string>
#include<list>
#include<deque>
#include<vector>

using namespace std;

int main(){
	vector<string> vec;
	vec.at(0); 		    //out of range
	vec[0];    		    //out of range
	vec.front();	            //empty
	vec.back();		    //empty
}
