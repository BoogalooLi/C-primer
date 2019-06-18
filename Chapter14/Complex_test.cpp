#include"Complex.h"

using namespace std;

int main(){
    Complex c(3,4);
    // >> (3,4)
    // cin>>c;
    // <<
    cout<<c<<endl;
    //Conjuate()
    auto c1 = Conjuate(c);
    cout<<c1<<endl;
    //-
    auto c2 = -c;
    cout<<c2<<endl;
    //abs
    cout<<abs(c)<<endl;
    //=
    auto c4 = c;
    cout<<c4<<endl;
    // == !=
    auto a = c1 == c;
    auto b = c1 != c;
    cout<<a<<endl
        <<b<<endl;
    // + -
    auto c5 = c4 + c;
    auto c6 = c4 - c;
    auto c7 = c + 100;
    auto c8 = 100 + c;
    auto c9 = 100 - c;
    auto c10 = c - 100;
    cout<<c5<<endl
        <<c6<<endl
        <<c7<<endl
        <<c8<<endl
        <<c9<<endl
        <<c10<<endl;
    // *
    auto c11 = c * c;
    auto c12 = c * 2;
    auto c13 = 2 * c;
    cout<<c11<<endl
        <<c12<<endl
        <<c13<<endl;
    // /
    auto c14 = c / c;
    auto c15 = c / 2;
    auto c16 = 2 / c;
    cout<<c14<<endl
        <<c15<<endl
        <<c16<<endl;
    // +=
    c15 += c;
    c16 += 5;
    cout<<c15<<endl
        <<c16<<endl;
    // -=
    c15 -= c;
    c16 -= 5 ;
    cout<<c15<<endl
        <<c16<<endl;
    // *=
    c15 *= c;
    c16 *= 5;
    cout<<c15<<endl
        <<c16<<endl;
    // /=
    c15 /= c;
    c16 /= 5;
    cout<<c15<<endl
        <<c16<<endl;
}
/*
expected output
(3,4)
(3,-4)
(-3,-4)
5
(3,4)
0
1
(6,8)
(0,0)
(103,4)
(103,4)
(97,-4)
(-97,4)
(-7,24)
(6,8)
(6,8)
(-3.57143,-0)
(1.5,2)
(-0.857143,-1.14286)
(4.5,5)
(4.14286,-1.14286)
(1.5,1)
(-0.857143,-1.14286)
(0.5,5)
(-4.28571,-5.71429)
(-1.16216,-0.836594)
(-0.857143,-1.14286)
*/
