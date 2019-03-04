#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string>& words){
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> & words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string& s1, const string& s2){return s1.size() < s2.size();});
    auto wc = partition(words.begin(), words.end(), [sz](const string& s){return s.size() >= sz; } );
    for_each(words.begin(), wc, [](const string& s){cout<<s<<" ";});
    cout<<endl;
}


int main() {
    string str;
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(vec, 5);

}
