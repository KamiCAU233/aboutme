#include <iostream>
using namespace std;

bool isLeap(int);

class date {
    private:
        int y, m, d;
    public:
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

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


//StudybarCommentBegin
int main(void) {
    // using std::cin;
    // using std::cout;
    // using std::endl;

    date D1,D2;
    int year;
    int month;
    int day;
    cin>>year>>month>>day; //shu ru di yi ge ri qi
    D1=date(year,month,day);
    cin>>year>>month>>day;  //shu ru di er ge ri qi
    D2=date(year,month,day);
    cout<<D2-D1<<endl;
    cin>>day;  //shu ru yao jia jian de tian shu,
    D1+=day;
    D2-=day;
    cout<<D1.year()<<" "<<D1.month()<<" "<<D1.day()<<endl;
    cout<<D2.year()<<" "<<D2.month()<<" "<<D2.day()<<endl;
    return 0;
}

//StudybarCommentEnd
