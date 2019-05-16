#ifndef HASPTR_H
#define HASPTR_H

#include<string>

class HasPtr{
	public:
		HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0){	}
		HasPtr(const HasPtr& hp): ps(new std::string(*hp.ps)), i(hp.i){ } // 对象是string*； 
		HasPtr& operator=(const HasPtr& hp);
		~HasPtr(){ delete ps;}; 
	private:
		std::string *ps;
		int i;
}; 

HasPtr& HasPtr::operator=(const HasPtr& hp){
	ps = hp.ps;
	i = hp.i;
	return *this;
}

#endif
