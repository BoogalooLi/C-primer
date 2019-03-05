#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto n = 5;
    auto i = count_if(vec.begin(), vec.end(), [n](const string& s){return s.size() >= n; });
    cout<<i<<endl;
}
