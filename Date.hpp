#ifndef __DATE_HPP__
#define __DATE_HPP__
#include <string>
class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date() {
            month = day = year = 0;
        }
        Date(int m, int d, int y){
            month = m;
            day = d;
            year = y;
        }
        void setDay(int d){
            day = d;
        }
        void setMonth(int m){
            month = m;
        }
        void setYear(int y){
            year = y;
        }
        int getDay(){
            return day;
        }
        int getMonth(){
            return month;
        }
        int getYear(){
            return year;
        }
        std::string toString(){
            return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
        }
        
};
#endif