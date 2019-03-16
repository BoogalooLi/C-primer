#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
	map<string, size_t> words;
	string word;
	while(cin>>word){
		for(auto &c : word)
			c = tolower(c);
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++words[word];
	}
	for(const auto w : words)
		cout<<w.first<<" "<<w.second<<endl;
	cout<<endl;
}
