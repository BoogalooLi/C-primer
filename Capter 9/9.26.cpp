#include<list>
#include<vector>
#include<iostream>

using namespace std;

int main(){
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	list<int> lst;
	vector<int> vec; 
	for(int i = 0; i < 11; ++i){
		lst.push_back(ia[i]);
		vec.push_back(ia[i]);
	}
	auto l = lst.begin();
	while(l != lst.end()){
		if(*l % 2)
			l = lst.erase(l);
		else
			++l;
	}
	auto v = vec.begin();
	while(v != vec.end()){
		if(!(*v % 2))
			v = vec.erase(v);
		else
			++v;	
	}
	for(auto c : vec){
		cout<<c<<endl;
	}
	for(auto c : lst){
		cout<<c<<endl;
	}
}
