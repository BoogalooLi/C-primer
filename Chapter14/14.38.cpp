#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>
#include<set>
using namespace std;


struct Compare{
	bool operator()(const string& s, const int& filter= 0){
		return s.size() == filter;
	}
};

int main(){
	//open a file
	string file_name;
	cin>>file_name;
	ifstream in(file_name);
	
	string word;
	Compare com;
	//map for recording sizes and underlying times
	map<int, int> mp;
	set<int> st = {1,2,3,4,5,6,7,8,9,10};
	for(const auto i : st)
		mp.insert({i, 0});
	while(getline(in, word)){
		for(const auto i : st)
			if(com(word, i))
				++mp[i];
	}
}

