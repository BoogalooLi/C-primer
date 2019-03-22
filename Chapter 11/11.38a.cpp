#include <unordered_map>
#include<iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<string, size_t> word_count;
	string word;
	while(cin>>word)
		++word_count[word];
	for(const auto &c : word_count)
		cout<<w.first<<" occurs"<<w.second
		<<((w.second > 1) ? "times" : "time")<<endl;
	return 0;
}
