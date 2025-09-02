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
        Time operator++() {
            *this = 1 + *this;
            return *this;
        }
        friend Time operator+(int increase, Time time) {
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
	int hour, minute, second;
	int increase;
	Time t1(23,45,0), t2, t3(t1);
	cin>>hour>>minute>>second>>increase;
	t1.setTime(hour,minute,second);
	t1.printTime();
	t2=++t1;
	t2.printTime();
	t3=increase+t1;
	t3.printTime();
    return 0;
}
//StudybarCommentEnd

