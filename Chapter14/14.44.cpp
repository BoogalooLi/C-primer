#include<functional>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	map<string, function<int(int, int)>> calculate_int;
	calculate_int = {
	{"+", plus<int>()},
	{"-", minus<int>()},
	{"*", multiplies<int>()},
	{"/", divides<int>()},
	{"%", modulus<int>()},
	};
	cout<<calculate_int["+"](10, 5)<<endl;
	cout<<calculate_int["-"](10, 5)<<endl;
	cout<<calculate_int["*"](10, 5)<<endl;
	cout<<calculate_int["/"](10, 5)<<endl;
	cout<<calculate_int["%"](10, 5)<<endl;
}
