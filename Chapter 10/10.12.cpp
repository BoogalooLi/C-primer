#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
#include"Sales_data"

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

bool compareISBN(const Sales_data& s1, const Sales_data& s2){
	return s1.isbn() < s2.isbn();
}

int main()
{
	vector<Sales_data> vec ;//no examples here, so no test for this scripts
	
	elimDup(vec);
	stable_sort(vec.begin(), vec.end(), compareISBN);
	print(vec);
}

