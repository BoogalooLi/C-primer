#include"Sales_data.h"

std::istream &read(std::istream &is, Sales_data &item){//��ʱitem�����Ͷ��󶼿���ʹ�ã����� 
	double price = 0.0;
	is>>item.bookNo>>item.units_sold>>price;
	item.revenue = item.units_sold * price;
	return is;
}
