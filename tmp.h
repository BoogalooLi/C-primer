#ifndef BLOB_H
#define BBLOB_H

#include<vector>
using std::vector;
#include<memory>
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;
using std::weak_ptr;
#include<string>
using std::string;
using std::move;
 

template <typename T>
class Blob{
	public:
		using size_type = typename vector<T>::size_type;
		Blob();
		Blob(initializer_list<T> il);
		
		size_type size() const { return data->size(); }
		bool enpty() const { return data->empty(); }
		
		void push_back(T&& t) { data->push_back(move(t)); }
		void push_back(const T& t){ data->push_back(t); }
		void pop_back();
		
		T& back();
		T& operator[](size_type i);
		const T& operator[](size_type i) const;
	private:
		shared_ptr<vector<T>> data;
		void check(size_type i, const string& msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const string& msg) const {
	if(i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back(){
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i){
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back(){
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()){ }

template <typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) { }

template <typename T>
class BlobPtr{
	public:
		
	private:
		shared_ptr<vector<T>> check(size_t i, const string&) const;
		weak_ptr<vector<T>> wptr;
		size_t curr;
};
#endif 
