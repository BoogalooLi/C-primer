#ifndef LSCREEN_H
#define LSCREEN_H

#include<string>

class Lscreen{
	friend void Lwindow_mgr::clear(ScreenIndex);
	public:
		using pos = std::string::size_type;
		//constructor
		Lscreen() = default;
		Lscreen(pos ht, pos wd):height(ht), width(wd){}
		Lscreen(pos ht, pos wd, char c):height(ht), width(wd), contents( ht * wd ,c){}
		inline Lscreen &move(pos r, pos c);
		inline Lscreen &set(char c);
		Lscreen &display(std::ostream &os){
			do_display(os);
			return *this;
		}
		const Lscreen &display(std::ostream &os) const {
			do_display(os);
			return *this;
		}
	private:
		pos height = 0;
		pos width = 0;
		std::string contents;
		pos cursor = 0;//¹â±ê 
		void do_display(std::ostream &os) const{ os<<contents; }
}; 

inline Lscreen& Lscreen::move(pos r, pos c){
	pos row = r*width + c;
	return *this;
}

inline Lscreen& Lscreen::set(char c){
	contents[cursor] = c;
	return *this;
}
#endif
