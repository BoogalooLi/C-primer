/*
no eror
*/

#include<iostream>
#include<numeric>
#include<vector>


using namespace std;

int main(){
	vector<double> numbers = {1.2,2.3,3.1,4.5,5.3,6.4,7.3,9.4,0.4};
	cout<<accumulate(numbers.cbegin(), numbers.cend(), 0);
} 
