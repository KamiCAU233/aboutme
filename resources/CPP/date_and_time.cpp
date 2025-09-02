//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
//StudybarCommentEnd

bool isLeap(int);

class date {
    public:
        int y, m, d;
        date(int year = 0, int month = 0, int day = 0) : y(year), m(month), d(day) {}

        int year() const {return y;}
        int month() const {return m;}
        int day() const {return d;}

        date operator++(int) {
            date temp = *this;
            int days_of_the_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (isLeap(y)) days_of_the_month[1] = 29;
            if (d < days_of_the_month[m - 1]) {
                *this = date(y, m, d + 1);
            } else if (d == days_of_the_month[m - 1]) {
                if (m == 12) {
                    *this = date(y + 1, 1, 1);
                } else {
                    *this = date(y, m + 1, 1);
                }
            }
            return temp;
        }

        date operator--(int) {
            date temp = *this;
            int days_of_the_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (isLeap(y)) days_of_the_month[1] = 29;
            if (d > 1) {
                d--;
            } else if (d == 1) {
                if (m == 1) {
                    y--;
                    m = 12;
                    d = 31;
                } else {
                    m--;
                    d = days_of_the_month[m - 1];
                }
            }
            return temp;
        }

        bool operator==(date other) const {
            return d == other.d && m == other.m && y == other.y;
        }

        bool operator!=(date other) const {
            return d != other.d || m != other.m || y != other.y;
        }

        int operator-(date other) const {
            int i = 0;
            while (other != *this) {
                other++;
                i++;
            }
            return i;
        }

        date operator+=(int days) {
            for (int i = 0; i < days; i++) {
                (*this)++;
            }
            return *this;
        }

        date operator-=(int days) {
            for (int i = 0; i < days; i++) {
                (*this)--;
            }
            return *this;
        }
};

class Time : public date {
    private:
        int hr, min, sec;
    public:
        Time(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0)
            : date(year, month, day), hr(hour), min(minute), sec(second) {}

        void printTime() {
            cout << y << "/" << m << "/" << d << " " << setfill('0') << setw(2) << hr
                 << ":" << setw(2) << min << ":" << setw(2) << sec << endl;
        }

        void setTime(int year, int month, int day, int hour, int minute, int second) {
            y = year;
            m = month;
            d = day;
            hr = hour;
            min = minute;
            sec = second;
        }
        Time& operator++() {
            if (sec != 59) {
                sec++;
            } else if (min != 59) {
                sec = 0;
                min++;
            } else if (hr != 23) {
                min = 0;
                sec = 0;
                hr++;
            } else {
                hr = 0;
                min = 0;
                sec = 0;
                (*this).date::operator++(0); // Calling the postfix ++ of date class
            }
            return *this;
        }
        Time operator--(int) {
            Time temp = *this;
            if (sec != 0) {
                sec--;
            } else if (min != 0) {
                sec = 59;
                min--;
            } else if (hr != 0) {
                sec = 59;
                min = 59;
                hr--;
            } else {
                sec = 59;
                min = 59;
                hr = 23;
                (*this).date::operator--(1);
            }
            return temp;
        }
        Time operator+(int increase) const {
            Time temp = *this;
            for (int i = 0; i < increase; i++) {
                ++temp;
            }
            return temp;
        }
        Time operator-(int decrease) const {
            Time temp = *this;
            for (int i = 0; i < decrease; i++) {
                temp--;
            }
            return temp;
        }
        int operator-(const Time other) const {
            date this_day = date(y, m, d);
            date other_day = date(other.y, other.m, other.d);
            int day_difference = this_day - other_day;
            int this_sec = 3600 * hr + 60 * min + sec;
            int other_sec = 3600 * other.hr + 60 * other.min + other.sec;
            return day_difference * 3600 * 24 + (this_sec - other_sec);
        }
        bool operator==(const Time other) const {
            return y == other.y && m == other.m && d == other.d && hr == other.hr && min == other.min && sec == other.sec;
        }
};



bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


//StudybarCommentBegin
int main()
{

	int year,month,day;
	int hour,minute,second;
	int increase;
	int capacity=0;
	Time t1(2016,3,31,23,45,0),t2,t3(t1),t4;
	cin>>year>>month>>day>>hour>>minute>>second;
	t1.setTime(year,month,day,hour,minute,second);
	cin>>year>>month>>day>>hour>>minute>>second;
	t2.setTime(year,month,day,hour,minute,second);
	cin>>increase;
	t1.printTime();
	t2.printTime();
	t3=++t1;
	t3.printTime();
	t4=t1+increase;
	t4.printTime();
	capacity = t2-t1;
	cout<<capacity<<endl;
}
//StudybarCommentEnd
