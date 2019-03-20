#include<string>
#include <vector>
#include <utility>
#include <map>
#include<algorithm>
#include <iostream>

using namespace std;

int main(){
	std::map<string, int> ml = {{"list", 1}} ;
	auto mlit = ml.begin();
	cout<<mlit->first<<" "<<mlit->second<<endl;
	mlit->second = 100;
	cout<<mlit->first<<" "<<mlit->second<<endl;
}
