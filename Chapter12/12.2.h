#ifndef STRBLOB_H
#define STRBLOB_H

#include<string>
#include<initializer_list>
#include<memory>
#include<vector>
#include<stdexcept>

class StrBlob{
	public:
		using sz = std::vector<std::string>::size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		
		sz size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		
		void push_back(const std::string& t){
			data ->push_back(t);
		}
		void pop_back();
		
		std::string& front();
		std::string& back();
		
		const std::string& front() const;
		const std::string& back() const;
		
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(sz i, const std::string &msg) const;
}; 

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)){}

void StrBlob::check(sz i, const std::string& msg)const{
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

#endif
