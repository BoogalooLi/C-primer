#include<iostream>
#include<utility>
using namespace std;

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2){
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void g(const int& i, const int& j){
	cout<<i<<" "<<j<<endl;
}

int main(){
	flip(g, 41, 1);
	
	int i = 1, j = 42;
	flip(g, i, j);
	
	flip(g, 1, j);
} 
