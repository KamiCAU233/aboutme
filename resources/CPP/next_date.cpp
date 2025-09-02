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

};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
//StudybarCommentBegin
int main(void)
{
	// using std::cin;
	// using std::cout;
	// using std::endl;

	date D1,D2;

	int year;
	int month;
	int day;

	cin>>year>>month>>day; //shu ru di yi ge ri qi
	D1=date(year,month,day);

	D2=D1++;

	cout<<D1.year()<<" "<<D1.month()<<" "<<D1.day()<<endl;
	cout<<D2.year()<<" "<<D2.month()<<" "<<D2.day()<<endl;
	return 0;
}

//StudybarCommentEnd
