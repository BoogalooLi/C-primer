#ifndef LWINDOW_MGR_H
#define LWINDOW_MGR_H

#include "Lscreen.h"
#include<vector>
#include<string>

class LWindow_mgr{
	public:
		using ScreenIndex = std::vector<Lscreen>::size_type;
		void clear(ScreenIndex);
	private:
		std::vector<Lscreen> screens{Lscreen(24, 80, ' ')};
};
void LWindow_mgr::clear(ScreenIndex i){
	Lscreen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}
#endif
