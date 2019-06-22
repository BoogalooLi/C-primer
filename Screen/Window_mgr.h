#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include<vector>
#include"Screen.h"

class Window_mgr{
	public:
		using ScreenIndex = std::vector<Screen>::size_type;
		
		ScreenIndex addScreen(const Screen&); 
		void clear(ScreenIndex);
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
		
};

void Window_mgr::clear(ScreenIndex i){
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');	
}
Window_mgr::ScreenIndex

Window_mgr::addScreen(const Screen& s){
	screens.push_back(s);
	return screens.size() - 1;
}

#endif 
