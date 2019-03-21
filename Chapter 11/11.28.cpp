#include<string>
#include <vector>
#include <utility>
#include <map>
#include<algorithm>
#include <iostream>

using namespace std;

int main(){
	std::map<string, vector<int> > map;
	auto mp = map.find("good");
	cout<<(mp == map.end());
}
