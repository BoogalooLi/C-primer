#include<tuple>
#include"Sales_data.h"
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

using matches = tuple<vector<Sales_data>::size_type,
                      vector<Sales_data>::const_iterator,
                      vector<Sales_data>::const_iterator>;
vector<matches>
    findBook(const vector<vector<Sales_data>>& files, const string& book){
        vector<matches> ret;
        for(auto it = files.cbegin(); it != files.cend(); ++it){
            auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
            if(found.first != found.second)
                ret.push_back(make_tuple(it-files.cbegin(), found.first, found.second));
        }
        return ret;
    }

void reportResults(istream& is, ostream& os, const vector<vector<Sales_data>>& files){
    string s;
    while(is>>s){
        auto trans = findBook(files,s);
        if(trans.empty()){
            cout<<s<<" not found in any stores"<<endl;
            contiue;
        }
        for(const auto& store : trans)
            os<<"store "<<get<0>(store)<<" sales: "
              <<accumulate(get<1>(store), get<2>(store),Sales_data(s))<<endl;
    }
}
