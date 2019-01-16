#include<list>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

bool compare_list_and_vector(const list<int>& lst, const vector<int> &vec){
	if(lst.size() != vec.size()) 
		return false;
	else{
		auto il = lst.cbegin();
		auto iv = vec.cbegin();
		for(iv, il; iv!= vec.cend(); ++iv, ++il){
			if(*(iv) == *(il))
				continue;
			else
				return false;
		}
		return true;
	}
}

int main(){
	list<int> lst = {1,2,3,4,5,6,7,8,9,1};
	vector<int> vec = {1,2,3,4,5,6,7,8,9,0};
	cout<<compare_list_and_vector(lst, vec);
}
