#include<string>
#include <vector>
#include <utility>
#include <map>
#include<algorithm>

using namespace std;

void Add_info(std::map<string, std::vector<pair<string, string>>> &fam_info,const string &lm,const string &fm,const string &bd){
	pair<string, string> p = {fm, bd};
    vector<pair<string, string>> info;
	info.push_back(p);
	fam_info.insert({lm, info});
}

int main(int argc, char const *argv[])
{
	std::map<string, std::vector<pair<string, string>>> fam_info;

	return 0;
}
