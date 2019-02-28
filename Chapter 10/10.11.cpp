#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 

using namespace std;

void print(const vector<string>& v){
	for(const auto & c : v)
		cout<<c<<" ";
	cout<<endl;
}

void elimDup(vector<string>& v){
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

bool isShorter(const string& s1, const string& s2){
	return s1.size() < s2.size();
}

int main()
{
	vector<string> vec = {"fox", "jumps", "over", "quick", "red", "the", "quick", "red", "the", "slow", "turtle"};
	
	elimDup(vec);
	stable_sort(vec.begin(), vec.end(), isShorter);
	print(vec);
}

