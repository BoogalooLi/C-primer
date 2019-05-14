#include<iostream>
#include<string>
#include<memory>

using namespace std;

void Combine(const string& c1, const string& c2){
    const auto size = c1.size() + c2.size();
    char *p = new char[size];
    unique_ptr<char[]> uptr(p);
    size_t i;
    for(auto j = 0; j <= c1.size(); ++j)
        uptr[j] = c1[j];
    for(auto i = 0; i <= c2.size(); ++i)
        uptr[i + c1.size()] = c2[i];
    for(auto i = 0; i <= size; ++i)
        cout<<uptr[i]<<endl;
}

int main(){
    Combine("12345", "67890");
    
}
