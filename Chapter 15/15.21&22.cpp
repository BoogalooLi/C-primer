#ifndef FIGURE_H
#define FIGURE_H

#include<string>
using std::string;
class Figure{
	public:
		virtual	double area() = 0;
		virtual	double circum() = 0;
};

class Figure_2d : public Figure{
	protected:
		string type() const {return "2d";}
};

class Figure_3d : public Figure{
	protected:
		string type() const {return "3d";}
};

class Triangle : public Figure_2d{
	private:
		double a = 0;
		double b = 0;
		double c = 0;
	public:
		double area() override;
		double circum() override;
		bool tri_or_not();
};

class Rectangle : public Figure_2d{
	private:
		double length = 0;
		double width = 0;
	public:
		double area() override;
		double circum() override;
};

class Square : public Figure_2d{
	private:
		double line;
	public:
		double area() override;
		double circum() override;
};

class Circle : public Figure_2d{
	private:
		double radium;
	public:
		double area() override;
		double circum() override;
};

#endif 
