#include<iostream>
#include<string>
#include<vector>
using std::vector;
using std::istream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class ReadString{
	private:
		istream& is;
		string str;
	public:
		ReadString(istream& i = cin, string s = "") : is(i), str(s){ }
		string operator()(){
			if(is){
				getline(is, str);
				return str;
			}
			else
				return "";
		}
};

int main(){
	ReadString rs;
	auto s = rs();
	vector<string> v;
	v.push_back(s); 
	for(auto c : v)
		cout<<c<<endl;
}

