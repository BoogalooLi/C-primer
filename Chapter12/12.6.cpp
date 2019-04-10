#include<iostream>
#include<memory>
#include<vector>

using namespace std;

vector<int>* Newvec(){
	return new vector<int> ;
} 

void Read(vector<int>* v){
	int i;
	while(cin>>i)
		v->push_back(i);
}

void Print(vector<int>* v){
	for(const auto c : *v)
		cout<<c<<" ";
	cout<<endl;
}

int main(){
	auto vec = Newvec();
	Read(vec);
	Print(vec);
	delete vec;
}
