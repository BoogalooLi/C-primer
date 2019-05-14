#include<iostream>
#include<string>
#include<memory>

using namespace std;

void ReadCin(size_t size){
    string str;
    unique_ptr<char[]> uptr(new char[size]);
    while(cin>>str){
        for(auto i = 0; i <= str.size(); ++i)
            uptr[i] = str[i];
    }
    for(auto i = 0; i <= str.size(); ++i)
        cout<<uptr[i]<<endl;
}

int main(){
    ReadCin(10);
}
//no test
