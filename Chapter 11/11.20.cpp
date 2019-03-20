#include<string>
#include <vector>
#include <utility>
#include <map>
#include<algorithm>
#include <iostream>

using namespace std;

int main(){
	std::map<string, size_t> word_count;
	string word;
	while(cin>>word){
		auto ret = word_count.insert({word, 1});
		if(!ret.second)
			++ret.first->second;
	}
}
