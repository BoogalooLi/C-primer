#include<fstream>
#include"Strblob.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    ifstream in("test.txt"); 
    StrBlob sb;
    string s, st;
    //inut
    while(getline(in, s)){
        istringstream is(s);
        while(is>>st)
            sb.push_back(st);
    }

    auto ptr = sb.begin();

    while(ptr.pos() < sb.size()){
        cout<<ptr.deref()<<endl;
        ptr.incr();
    }

    
}


/*
this
is
a
test
file.
*/
