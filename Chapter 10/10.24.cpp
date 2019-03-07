#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz){
	return s.size() < sz;
}

vector<int>::const_iterator find_if_bigger(const vector<int> &v, const string& s){
	return find_if(v.cbegin(), v.cend(), bind(check_size, s, _1));
}

int main(int argc, char const *argv[])
{
	string s = "abdfd";
	vector<int> v = {1,2,3,4,5,6,7,8,90};
	cout<<*find_if_bigger(v, s);
	return 0;
}
