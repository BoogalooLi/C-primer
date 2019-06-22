#include"Sales_data.h"

std::ostream &print(std::ostream &os, const Sales_data &item){//此时item只能用常量，不能用对象 
	os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
	return os; 
}
