#include<iostream>
#include<string>

using namespace std;

template <typename... Args>
void g(Args... args){
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(args)<<endl;
	cout<<endl;
}

template <typename T, typename... Args>
void foo(const T& t, const Args&... rest){
	g(rest...);
}

int main(){
	int i = 0;
	double d = 3.14;
	string s = "what's your problem";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
}
