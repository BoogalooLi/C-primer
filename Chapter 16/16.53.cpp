#include<iostream>
#include<string>

using namespace std;

template <typename T>
ostream& print(ostream& os, const T& t){
	return os<<t<<endl;;
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest){
	os<<t<<",";
	return print(os, rest...);
}

int main(){
	int i = 1;
	double d = 1.234;
	string s = "string";
	char c = 'a';
	bool b = false;
	print(cout, i, d, s, c, b);
	print(cout, i, d, s, c);
	print(cout, i, d, s);
	print(cout, i, d);
	print(cout, i);

}
