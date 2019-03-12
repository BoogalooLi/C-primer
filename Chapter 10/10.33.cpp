#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<iterator> 
#include<fstream>

using namespace std;

int main(){
	ifstream input("numbers.txt");
	istream_iterator<int> in(input);
	vector<int> numbers, odds, evens;
	istream_iterator<int> end;
	ofstream output_odds("odds.txt"), output_evens("evens.txt");
	while(in != end)
		numbers.push_back(*in++);
	for(auto c : numbers){
		if(c%2)
			odds.push_back(c);
		else
			evens.push_back(c);
	}
	ostream_iterator<int> out1(output_odds, " "), out2(output_evens, " ");
	for(auto c : odds)
		*out1++ = c;
	for(auto c : evens)
		*out2++ = c;
	
}
