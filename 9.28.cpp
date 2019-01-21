#include<forward_list>
#include<iostream>
#include<string>

using namespace std;

void Insert(forward_list<string> &fls, string a, string b){
	for(auto it = fls.begin(); it != fls.end(); ++it){
		if((*it) == a){
			fls.insert_after(it,b);
			return ;
		}
	}
	fls.insert_after(fls.cend(),b);
}

int main(){
	forward_list<string> fls = {"ab", "bc", "cd", "de"};
	string a, b;
	a = "cd";
	b = "find";
	Insert(fls, a, b);
	for(auto c: fls)
		cout<<c<<endl;
		
	return 0;
}
