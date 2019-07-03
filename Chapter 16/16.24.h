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
 
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> 
class Blob{
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	public:
		using size_type = typename vector<T>::size_type;
		Blob();
		Blob(initializer_list<T> il);
		template <typename It>
		Blob(It b, It e);
		
		size_type size() const { return data->size(); }
		bool enpty() const { return data->empty(); }
		
		void push_back(T&& t) { data->push_back(move(t)); }
		void push_back(const T& t) { data->push_back(t); }
		void pop_back();
		
		T& back();
		const T& back() const;
		T& front();
		const T& front() const;
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
const T& Blob<T>::back() const{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::front(){
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T& Blob<T>::front() const{
	check(0, "front on empty Blob");
	return data->front();
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
		BlobPtr() : curr(0) { }
		BlobPtr(Blob<T>& a, size_t sz = 0) : wptr(a.data), curr(sz) { }
		T& operator*() const{
			auto p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		BlobPtr& operator++();
		BlobPtr& operator--();
		BlobPtr& operator++(int);
		BlobPtr& operator--(int);
	private:
		shared_ptr<vector<T>> check(size_t i, const string&) const;
		weak_ptr<vector<T>> wptr;
		size_t curr;
};

template <typename T> template <typename It>
Blob<T>::Blob(It b, It e) : data(make_shared<vector<T>>(b,e)) { }

#endif 
