#ifndef DEBUGDELETE_H
#define DEUGDELETE_H

#include<iostream>
using std::ostream;
using std::cerr;
using std::endl;
#include<memory>
using std::make_shared;

class DebugDelete{
    public:
        DebugDelete(ostream& s = cerr) : os(s) { }
        template <typename T>
        void operator()(T* p) const
            { os<<"deleting unique_ptr"<<endl; delete p; }
    private:
        ostream& os;
};

#endif

int main() {
    int* p = new int;
    DebugDelete()(p);
}
