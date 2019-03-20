#include<string>
#include <vector>
#include <utility>
#include <map>
#include<algorithm>
#include <iostream>

using namespace std;

int main(){
	multimap<string, std::vector<string> > family;
	for(string fn, ln; cin>>fn>>ln;){
		if(family.find(ln) == family.end()){
			vector<string> fns;
			fns.push_back(fn);
			family.insert({ln, fns});
		}
		else{
			auto it = family.find(ln);
			it->second.push_back(fn);

		}
	}
    return 0;
}
