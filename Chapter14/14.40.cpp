#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

struct Compare1{
	bool operator()(const string& s1, const string& s2) const {
		return s1.size() < s2.size();
	}
};

class Compare2{
	private:
		size_t sz;
	public:
		Compare2(size_t s) : sz(s){ }
		bool operator()(const string& s) const {
			return s.size() >= sz;
		} 
};

struct Read{
	void operator()(const string& s){
		cout<<s<<" ";
	}
};
void elimDups(vector<string>& word){
	sort(word.begin(), word.end());
	auto end_unique = unique(word.begin(), word.end());
	word.erase(end_unique, word.end()); 
} 

string make_plural(size_t sz, const string& word, const string& ending){
	return (sz > 1) ? word + ending : word;
}
void biggies(vector<string>& word, vector<string>::size_type sz){
	elimDups(word);
	
	stable_sort(word.begin(), word.end(), Compare1());
	
	auto wc = find_if(word.begin(), word.end(), Compare2(sz));
	
	auto count = word.end() - wc;
	cout<<count<<" "<<make_plural(count, "word", "s")
		<<" of length "<<sz<<" or longer"<<endl;
	Read read;
	for_each(wc, word.end(), read);
	cout<<endl;
}
