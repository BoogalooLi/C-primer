#include"Sales_data.h"

std::ostream &print(std::ostream &os, const Sales_data &item){//��ʱitemֻ���ó����������ö��� 
	os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
	return os; 
}
