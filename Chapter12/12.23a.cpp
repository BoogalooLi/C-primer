#include<iostream>
#include<string>
#include<memory>

using namespace std;

void Combine(const char& c1, const char& c2){
    auto size = sizeof(c1) + sizeof(c2);
    char *ch = new char[size];
    unique_ptr<char[]> uptr(ch);
    uptr[1] = c1;
    uptr[2] = c2;
    
}

int main(){
    Combine('a', 'b');
}
