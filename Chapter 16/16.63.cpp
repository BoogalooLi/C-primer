#include<iostream>
#include<vector> 

using namespace std;

template <typename T>
int find(const vector<T>& vt, const T& t){
	static int ans = 0;
	for(const auto c : vt)
		if(t == c)
			++ans;
	return ans;
}
 
int main(){
	vector<int> vi = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5};
	vector<double> vd = {1.0,2.1,3.2,4.3,5.4,6.5,7.6,8.7,9.8,0.9,1.0};
	cout<<find(vi, 5)<<endl;
	cout<<find(vd, 1.0)<<endl;
} 
