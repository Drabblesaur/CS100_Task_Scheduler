#include <string>
class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year);
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
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
            return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
        };
        
};