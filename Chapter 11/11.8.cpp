#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	string word;
	auto it = find(v.cbegin(), v.cend(), word);
	if(it == v.cend())
		v.push_back(word);
	else
		cout<<"this word is a copy one"<<endl;
	return 0;
}
