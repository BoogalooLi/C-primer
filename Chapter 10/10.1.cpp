#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int num = 1;
	vector<int> vec = {1,2,3,4,5,6,7,8,9,0,9,78,67,6,5,4,534,53,4,24,
	234,3,2343,43,65,34,53,5,234,2,5,234,523,41,1,2,32,32,31,23,432,434,234,
	123,12,353,454,234,54,7,65,6,7534,1,4,234,23,41,1}; //test
	auto result = count(vec.cbegin(), vec.cend(), num);
	cout<<result; 
} 
