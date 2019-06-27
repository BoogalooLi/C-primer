#ifndef QUERY_H
#define QUERY_H

#include<string>
using std::string;
#include<memory>
using std::shared_ptr;
#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<vector>
using std::vector;
#include<fstream>
using std::ifstream;
#include<map>
using std::map;
#include<set>
using std::set;
#include<sstream>
using std::istringstream;
using line_no = vector<string>::size_type;
using Riterator = set<line_no>::iterator;
using std::make_shared;
#include<algorithm>

class QueryResult;
class TextQuery{
	public:
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_no>>> wm;		
};

TextQuery::TextQuery(ifstream& is) : file(new vector<string>){
	string text;
	while(getline(is, text)){
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line>>word){
			auto& lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult{
	friend ostream& operator<<(ostream&, const QueryResult&);
	public:
		QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : 
			sought(s), lines(p), file(f) { }
		shared_ptr<vector<string>> get_file() const { return file; } 
		Riterator begin() const { return lines->begin(); }
		Riterator end() const { return lines->end(); }
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string& sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

string make_plural(size_t ctr, const string& word, const string& ending){
	return (ctr == 1) ? word :word + ending;
}

ostream& operator<<(ostream& os, const QueryResult& qr){
	os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
		<<make_plural(qr.lines->size(), "time", "s")<<endl;
	for(auto num : *qr.lines)
		os<<"\t(line"<<num + 1<<")"<<*(qr.file->begin() + num)<<endl;
	return os;
}
class Query_base{
	friend class Query;
	protected:
		virtual ~Query_base() = default;
	private:
		//no definition for pure virtual functions
		virtual QueryResult eval(const TextQuery&) const = 0 ;
		virtual string rep() const = 0 ;
};

class Query{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	public:
		Query(const string&);
		QueryResult eval(const TextQuery& t) const { cout<<"Query eval()"<<endl; return q->eval(t); }
		string rep() const { cout<<"Query rep()"<<endl; return q->rep(); }
	private:
		Query(shared_ptr<Query_base> query) : q(query){ }
		shared_ptr<Query_base> q;
};

ostream& operator<<(ostream& os, const Query& query){
	return os<<query.rep();
}

class WordQuery : public Query_base{
	friend class Query;
	WordQuery(const string& s) : query_word(s) { cout<<"WordQuery constructor"<<endl;; }
	QueryResult eval(const TextQuery& t) const { return t.query(query_word); }
	string rep() const { cout<<"WordQuery eval()"<<endl; return query_word; }
	string query_word;
};

inline Query::Query(const string& s) : q(new WordQuery(s)) { cout<<"Query constructor"<<endl;}

class NotQuery : public Query_base{
	friend Query operator~(const Query&);
	NotQuery(const Query& q) : query(q) { }
	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator~(const Query& operand){
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base{
	protected:
		BinaryQuery(const Query& l, const Query& r, string s) : lhs(l), rhs(r), opSym(s) { cout<<"BinaryQuery constructor"<<endl; }
		string rep() const {
			return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
		}
		Query lhs, rhs;
		string opSym;
};

class AndQuery : public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") { cout<<"AndQuery constructor"<<endl; }
	QueryResult eval(const TextQuery&) const ;
};

inline Query operator&(const Query& lhs, const Query& rhs){
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery{
	friend Query operator|(const Query& ,const Query&);
	OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") { cout<<"OrQuery constructor"<<endl; }
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs){
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), ret_lines->begin());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& text) const {
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size();
	for(auto n = 0; n != sz; ++n){
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
#endif
