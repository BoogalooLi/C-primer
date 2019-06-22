#include"Sales_data.h"

std::istream &read(std::istream &is, Sales_data &item){//此时item常量和对象都可以使用，方便 
	double price = 0.0;
	is>>item.bookNo>>item.units_sold>>price;
	item.revenue = item.units_sold * price;
	return is;
}
