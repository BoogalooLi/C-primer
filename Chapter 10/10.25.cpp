#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string>& words){
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool check_size(const string& s, string::size_type sz){
	return s.size() >= sz;
}

void biggies(vector<string> & words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string& s1, const string& s2){return s1.size() < s2.size();});
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz) );
    for_each(words.begin(), wc, [](const string& s){cout<<s<<" ";});
    cout<<endl;
}


int main() {
    string str;
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(vec, 5);

}
