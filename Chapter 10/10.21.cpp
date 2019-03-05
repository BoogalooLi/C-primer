#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;
	auto f = [i]()mutable ->bool {return i > 0 ? --i : i;};
	cout<<f();

	return 0;
}
