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


bool morethan5(const string& s1){
	return s1.size() >= 5;
}

int main()
{
	vector<string> vec = {"fox", "jumps", "over", "quick", "red", "the", "quick", "red", "the", "slow", "turtle"};
	auto five = partition(vec.begin(), vec.end(), morethan5);
	print(vec);
	for(auto print = five - 1; print != vec.cbegin() - 1; --print)
		cout<<*print<<" ";
}

