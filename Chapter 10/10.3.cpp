#include<iostream>
#include<numeric>
#include<vector>


using namespace std;

int main(){
	vector<int> numbers = {1,2,3,4,5,6,7,8,9,0};
	cout<<accumulate(numbers.cbegin(), numbers.cend(), 0);
} 
