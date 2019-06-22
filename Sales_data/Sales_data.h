#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include<iostream>
class Sales_data{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, const Sales_data&);
	
	private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
	
	public:
	std::string isbn() const{return bookNo;	}
	Sales_data & combine(const Sales_data&);
	
	Sales_data() = default;
	explicit Sales_data(const std::string &s) : bookNo(s){}
	Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n){} 
	Sales_data(std::istream &);
};
#endif

	//非成员接口函数
	Sales_data add(const Sales_data&, const Sales_data&);
	std::ostream &print(std::ostream&, const Sales_data&);
	std::istream &read(std::istream&, const Sales_data&); 
	
inline double Sales_data::avg_price() const{
	if(units_sold)
		return revenue / units_sold;
	else
		return 0;
} 

Sales_data& Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
inline Sales_data::Sales_data(std::istream &is){ read(is, *this); } 

