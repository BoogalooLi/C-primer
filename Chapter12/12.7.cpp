#include<iostream>
#include<memory>
#include<vector>

using namespace std;

shared_ptr<vector<int>> Newvec(){
	return make_shared<vector<int>>();
}

void Read(shared_ptr<vector<int>>& v){
	int i;
	while(cin>>i)
		v->push_back(i);
}

void Print(shared_ptr<vector<int>>& v){
	for(const auto c : *v)
		cout<<c<<" ";
	cout<<endl;
}

int main(){
	auto vec = Newvec();
	Read(vec);
	Print(vec);
}
