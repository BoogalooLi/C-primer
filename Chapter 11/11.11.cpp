#include<string>
#include<set>
#include "Sales_data.h"

using namespace std;

int main(){
	bool compareISBN(const Sales_data& s1, const Sales_data& s2){
		return s1.isbn() < s2.isbn();
	}
	bool (*pf) (const Sales_data& s1, const Sales_data& s2) = compareISBN;
	multiset<Sales_data, pf> bookstore(compareISBN);
 }
