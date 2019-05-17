#ifndef HASPTR_H
#define HASPTR_H

#include<string>

//using std::string;


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

//动态内存管理 
HasPtr& HasPtr::operator=(const HasPtr& rhs){
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
} 

#endif
