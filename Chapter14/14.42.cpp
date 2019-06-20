#include<algorithm>
#include<functional>
#include<string>
#include<iostream>

using namespace std;

int main(){
	vector<int> v = {1032,1,2,3,43213,5,6,7,8,9,0,6,5246,5346,5216,5324,63215,6324,5126,5324,6,546,3,45,2,543,54};
	vector<string> s = {"pooff", "asdfasdf"};
	
	greater<int> G;
	int big = 0;
	for(const auto& i : v)
		if(G(i, 1024))
			++big;
	cout<<big<<endl;
	
	not_equal_to<string> net;
	for(const auto& i : s)
		if(net(i, "pooh")){
			cout<<i<<endl;
			break;
		}
	
	for(auto& i : v){
		multiplies<int> ml;
		i = ml(i,2);
		cout<<i<<" ";
	}
	cout<<endl;	
}
