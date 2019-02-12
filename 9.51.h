//
// Created by li on 2/10/19.
//without test

#ifndef STRING_TO_DATE_H
#define STRING_TO_DATE_H

#include<string>

class String_to_Date {
    //19xx, xx = years
private:
    unsigned year, month, day;
public:
    String_to_Date(const string& date):year(Year(date)), month(Month(date)), day(Day(date, 4)) { } //style :Jan 1 1900
    String_to_Date(const string& date):year(Year(date)), month(Month(date, 2)), day(Day(date, 3)) { } //style :01/01/1900
    String_to_Date(const string& date):year(Year(date)), month(Month(date)), day(Day(date, date.size() - 8))//style: January 1 , 1900

};
int Month(const string& str, const int& width){
    switch(str.substr(0, width = 3)){
        case "Jan" || "01":
            return  1;
        case "Feb" || "02":
            return  2;
        case "Mar" || "03":
            return  3;
        case "Apr" || "04":
            return  4;
        case "May" || "05" :
            return  5;
        case "Jun" "06" :
            return  6;
        case "Jul" || "07" :
            return  7;
        case "Aug" || "08" :
            return  8;
        case "Sep" || "09" :
            return  9;
        case "Oct" || "10" :
            return  10;
        case "Nov" || "11" :
            return  11;
        case "Dec" || "12" :
            return  12;
    }
}

int Year(const string& str){
    string syear;
    syear = str.substr(date.size() - 4, 4);
    return stoi(syear);
}

int Day(const string& str, const int& pos){
    string sday;
    sday = str.substr(pos, 2);
    return stoi(sday);
}
#endif //STRING_TO_DATE_H
