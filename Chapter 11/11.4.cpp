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
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		for(auto &s : word)
			s = tolower(s);
		++words[word];
	}
	for(const auto w : words)
		cout<<w.first<<" "<<w.second<<endl;
	cout<<endl;
}
