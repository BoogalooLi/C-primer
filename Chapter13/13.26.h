#ifndef STRBLOB_H
#define STRBLOB_H

#include<string>
#include<initializer_list>
#include<memory>
#include<vector>
#include<stdexcept>

class StrBlobPtr;

class StrBlob{
	friend class StrBlobPtr;
	
	public:
		StrBlobPtr begin();
		StrBlobPtr end();
		
		using size_type = std::vector<std::string>::size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		
		void push_back(const std::string& t){
			data ->push_back(t);
		}
		void pop_back();
		
		std::string& front();
		std::string& back();
		
		const std::string& front() const;
		const std::string& back() const;
		
		StrBlob(const StrBlob& sb): data(std::make_shared<std::vector<std::string>>(*sb.data)){ } 
		StrBlob& operator=(const StrBlob&);
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type i, const std::string &msg) const;
}; 

StrBlob& StrBlob::operator=(const StrBlob& sb){
	data = std::make_shared<std::vector<std::string>>(*sb.data);
	return *this;
}

class StrBlobPtr{
	public:
		StrBlobPtr() :curr(0){ }
		StrBlobPtr(StrBlob &a, std::size_t sz = 0):wptr(a.data), curr(sz){ }
		std::string& deref() const;
		StrBlobPtr& incr();
	
	private:
		std::shared_ptr<std::vector<std::string>> 
			check(std::size_t, const std::string&) const;
		std::weak_ptr<std::vector<std::string>> wptr;
		std::size_t curr;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)){}

void StrBlob::check(size_type i, const std::string& msg)const{
	if(i >= data->size())
		throw std::out_of_range(msg);
} 

void StrBlob::pop_back(){
	check(0, "pop back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front(){
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back(){
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

std::shared_ptr<std::vector<std::string>>
	StrBlobPtr::check(std::size_t i, const std::string &msg) const{
	auto ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
	}
	
std::string& StrBlobPtr::deref() const{
	auto p = check(curr, "derefence past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this);}

StrBlobPtr StrBlob::end(){
			auto ret = StrBlobPtr(*this, data->size());
			return ret;
		}
#endif
