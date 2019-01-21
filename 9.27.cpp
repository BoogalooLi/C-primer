#include<forward_list>
#include<iostream>

using namespace std;

int main(){
	forward_list<int> fls= {1,2,3,4,5,6,7,8,9,0};
	auto ele =  fls.begin();
	auto bf_ele = fls.before_begin();
	while(ele != fls.end()){
		if(*ele % 2)
			ele = fls.erase_after(bf_ele);
		else{
			bf_ele = ele;
			++ele;
		}
	}
	for(auto c :fls)
		cout<<c<<endl;
		
}
