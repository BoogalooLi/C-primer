#include<iostream>
#include<list>
#include<vector>

using namespace std;
template <typename T>
void print(const T& t){
    for(auto it = t.cbegin() ; it != t.cend() ; ++it)
        cout<<*it<<"\t";
    cout<<endl;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};
    list<int> l = {1,2,3,4,5,6,7,8,9,0};
    print(v);
    print(l);
}
