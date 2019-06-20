#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>
#include<set>
using namespace std;


struct Compare{
	bool operator()(const string& s, const int& filter= 10){
		return s.size() >= filter;
	}
};

int main(){
	//open a file
	string file_name;
	cin>>file_name;
	ifstream in(file_name);
	
	string word;
	Compare com;
	int less_than_10 = 0;
	int	more_than_9 = 0;
	while(getline(in, word)){
		switch(com(word)){
			case true:
				++more_than_9;
				break;
			case false:
				++less_than_10;
				break;
		}
	}
}

