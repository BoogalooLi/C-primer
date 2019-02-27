#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> vec = {1,2,3,4,5,6,7,8,9,12};
	fill_n(vec.begin(), 10, 0);
	for(auto c : vec)
		cout<<c<<endl; 
	
}

