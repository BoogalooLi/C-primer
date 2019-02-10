#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main() {
    string ascender = "bdfhklt";
    string descender = "gjpqy";
    string available = "aceimnorsuvwxz";
    ifstream input("/home/li/CLionProjects/untitled/word.txt");
    string lword;
    while(input){
        string word;
        input>>word;
        if((word.size() > lword.size()) && word.find_first_not_of(available) == string::npos ){
            lword = word;
        }
    }
    cout<<lword;
}
