#include<string>
#include <vector>
#include <utility>

using namespace std;

void MP(string &s, int &i){
	std::vector<pair<string, int> > v;

	auto p1 = make_pair(s, i);//solution 1
	v.push_back(p1);

	pair<string, int> p2(s, i);//solution 2
	v.push_back(p2);

	pair<string, int> p3 = {s, i};

	v.push_back(p3);
	
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
