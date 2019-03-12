#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<iterator> 

using namespace std;

int main(){
	istream_iterator<int> in(cin);
	vector<int> v;
	istream_iterator<int> end;
	while(in != end)
		v.push_back(*in++);
		
	sort(v.begin(), v.end()); // const iterator is WRONG here, because of sorting
	ostream_iterator<int> out(cout, " ");
	for(auto c : v)
		*out++ = c;
	cout<<endl;
	copy(v.cbegin(), v.cend(), out);
	cout<<endl;
	
}
