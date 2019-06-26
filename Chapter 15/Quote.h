#ifndef QUOTE_H 
#define QUOTE_H

#include<string>
#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::size_t;
using std::move;

#include<memory>
#include<set>
#include<iostream>
#include"Quote.h"
using std::shared_ptr;
using std::multiset;


class Quote{
	public:
	//constructors
		Quote() = default;
		Quote(const string& book, double sales_price):
			bookNo(book), price(sales_price){cout<<"Quote constrcutor"<<endl; }
	//copy and move	
Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) { }
Quote(Quote&& q) noexcept : bookNo(q.bookNo), price(q.price){
	q.bookNo = "";
	q.price = 0.0;
}
Quote& operator=(const Quote& q) {
	bookNo = q.bookNo;
	price = q.price;
	return *this;
}
Quote& operator=(Quote&& q) noexcept {
	if(this != &q){
		bookNo = q.bookNo;
		price = q.price;
		q.bookNo = "";
		q.price = 0.0;
	}
	return *this;
}
	//member functios
		string isbn() const { return bookNo; }
		virtual double net_price(size_t n) const { return n * price; }
		virtual void debug() const; 
	//destructor
		virtual	~Quote() = default;
	//clone	
		virtual Quote* clone() const& { return new Quote(*this);}
		virtual Quote* clone() && { return new Quote(move(*this));}
	private:
		string bookNo;
	protected:
		double price = 0.0;
};
void Quote::debug() const {
	cout<<isbn()<<endl;
	cout<<price<<endl;
	cout<<endl;
}

double print_total(ostream &os, const Quote& item, size_t n){
	double ret = item.net_price(n);
	os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<"total due: "<<ret<<endl;
	return ret;
}

class Disc_quote : public Quote{
	public:
		Disc_quote() = default;
		Disc_quote(const string& book, double price, size_t qty, double disc):
			Quote(book, price), quantity(qty), discount(disc){cout<<"Disc_quote constructor"<<endl; }
			
Disc_quote(const Disc_quote& dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount){ }
Disc_quote(Disc_quote&& dq) noexcept : Quote(move(dq)), quantity(dq.quantity), discount(dq.discount){
	dq.quantity = 0;
	discount = 0.0;
}
Disc_quote& operator=(const Disc_quote& dq){
	Quote::operator=(dq);
	quantity = dq.quantity;
	discount = dq.discount;
	return *this;
}
Disc_quote& operator=(Disc_quote&& dq) noexcept{
	if(this != &dq){
		Quote::operator=(dq);
		quantity = dq.quantity;
		discount = dq.discount;
		dq.quantity = 0;
		dq.discount = 0.0;
	}
	return *this;
}
		~Disc_quote() override = default;
		double net_price(size_t) const = 0;
	protected:
		size_t quantity = 0;
		double discount = 0.0; 
}; 

class Bulk_quote : public Disc_quote{
	public:
		Bulk_quote() = default;
		Bulk_quote(const string& book, double p, size_t qty, double disc)
		 : Disc_quote(book, p, qty, disc){cout<<"Bulk_quote constructor"<<endl; }
		 
Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq) { }
Bulk_quote(Bulk_quote&& bq) noexcept : Disc_quote(move(bq)) { }
Bulk_quote& operator=(const Bulk_quote& bq){ Disc_quote::operator=(bq); return *this;}
Bulk_quote& operator=(Bulk_quote&& bq){
	if(this != &bq)
		Disc_quote::operator=(bq);
	return *this;
}
		Bulk_quote* clone() const& override { return new Bulk_quote(*this);}
		Bulk_quote* clone() && override { return new Bulk_quote(move(*this));}
		double net_price(size_t) const override;
		void debug() const override;
	private:
		size_t min_qty = 0;
		double discount = 0.0;
}; 
double Bulk_quote::net_price(size_t cnt) const {
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
void Bulk_quote::debug() const {
	Quote::debug();
	cout<<min_qty<<endl;
	cout<<discount<<endl;
	cout<<endl;
}

class Own_quote : Disc_quote{
	public:
		Own_quote() = default;
		Own_quote(const string& book, double p, size_t qty, double disc)
		 : Disc_quote(book, p, qty, disc){cout<<"Own_quote constructor"<<endl;}
		 
Own_quote(const Own_quote& oq) : Disc_quote(oq) { }
Own_quote(Own_quote&& oq) noexcept : Disc_quote(move(oq)) { }
Own_quote& operator=(const Own_quote& oq){ Disc_quote::operator=(oq); return *this;}
Own_quote& operator=(Own_quote&& oq) noexcept 	{
	if(this != &oq)
		Disc_quote::operator=(oq);
	return *this;		
}
		Own_quote* clone() const& override { return new Own_quote(*this);}
		Own_quote* clone() && override { return new Own_quote(move(*this));}
		double net_price(size_t) const override;
		void debug() const override;
	private:
		size_t max_qty = 0;
		double discount = 0.0;
};
double Own_quote::net_price(size_t cnt) const {
	if(cnt <= max_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
void Own_quote::debug() const {
	Quote::debug();
	cout<<max_qty<<endl;
	cout<<discount<<endl;
	cout<<endl;
}

class Basket{
	public:
		void add_item(const Quote& sale){ items.insert(shared_ptr<Quote>(sale.clone())); }
		void add_item(Quote&& sale){ items.insert(shared_ptr<Quote>(move(sale).clone())); }
		double total_receipt(ostream&) const;
	private:
		static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs){ return lhs->isbn() < rhs->isbn(); }
		multiset<shared_ptr<Quote>, decltype(compare)*>items{compare};
};

double Basket::total_receipt(ostream& os) const{
	double sum = 0.0;
	for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
		sum += print_total(os, **iter, items.count(*iter));
	}
	os<<"Total sale: "<<sum<<endl;
	return sum;
}

#endif

