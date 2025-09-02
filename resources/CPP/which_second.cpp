//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
//StudybarCommentEnd

class Time {
    public:
        Time(int hh = 0, int mm = 0, int ss = 0) : h(hh), m(mm), s(ss) {}
        void printTime();
        void setTime(int hh, int mm, int ss) {
            h = hh; m = mm; s = ss;
        }
        Time& operator++() {
            *this = 1 + *this;
            return *this;
        }
        Time& operator--() {
            *this = (-1) + *this;
            return *this;
        }
        Time operator++(int) {
            Time temp = *this;
            *this = 1 + *this;
            return temp;
        }
        Time operator--(int) {
            Time temp = *this;
            *this = (-1) + *this;
            return temp;
        }

        friend Time operator+(int increase, Time time) {
            if (increase < 0)
            {
                return (-increase - time);
            }
            int news = time.s, newm = time.m, newh = time.h;
            news = time.s + increase;

            if (news >= 60)
            {
                newm = time.m + news / 60;
                news = news % 60;
                if (newm >= 60)
                {
                    newh = time.h + newm / 60;
                    if (newh == 24)
                    {
                        newh = 0;
                    }
                    newm = newm % 60;
                }
            }
            return Time(newh, newm, news);
        }
        friend Time operator-(int decrease, Time time) {
            // 这里由于减数和被减数的顺序弄反了，那么后面就都反过来了；
            int news = time.s, newm = time.m, newh = time.h;
            news = time.s - decrease;
            if (news < 0)
            {
                newm = time.m - ((decrease) / 60 + 1);
                news = 60 - (-news) % 60;

                if (newm < 0)
                {
                    newh = time.h - (-newm) / 60;
                    newm = 60 - (-newm) % 60; newh--;
                    if (newh < 0)
                    {
                        newh = 24 - (-newh / 24 + 1);
                    }
                }
            }
            return Time(newh, newm, news);
        }
    private:
        int h, m, s;
};

void Time::printTime()
{
    cout << setfill('0') << setw(2) << h
         << ":" << setw(2) << m << ":"
         << setw(2) << s << endl;
}



//StudybarCommentBegin
int main()
{
    int hour,minute,second;
    int number;
    Time t1(23,45,0),t2,t3(t1),t4;
    cin>>hour>>minute>>second>>number;
    t1.setTime(hour,minute,second);
    t2=t1--;
    t2.printTime();
    t1.printTime();
    t3=--t1;
    t3.printTime();
    t4=number+t1;
    t4.printTime();
}
//StudybarCommentEnd
