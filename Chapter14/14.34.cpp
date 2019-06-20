#include<iostream>
using std::cout;
using std::endl;
struct if_then_else{
	const int operator()(const int& i1, const int& i2, const int& i3) const{
		return i1 ? i2 : i3; 
	}	
};

int main(){
	if_then_else ite;
	auto ans1 = ite(1,2,3);
	auto ans2 = ite(0,2,3);
	cout<<ans1<<endl;
	cout<<ans2<<endl;
}
