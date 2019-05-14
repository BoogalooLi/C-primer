#include<iostream>
#include<string>
#include<memory>

using namespace std;

int main(){
    allocator<string> a;
    auto n = 10;
    string * const p = a.allocate(n);
    string s;
    string * q = p;
    while(cin >> s && q != p + n)
        a.construct(q, s);

    const size_t size = q - p;

    while(q != p)
        a.destroy(--q);

    a.deallocate(p, n);
    
}
