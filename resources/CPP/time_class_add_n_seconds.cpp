#include <iostream>
using namespace std;
class Cmytime
{
    private:
        int h, m, s;
    public:
        int Set(int hh, int mm, int ss)
        {
            if ((hh >= 0 && hh <= 23) && (mm >= 0 && mm <= 59) && (ss >= 0 && ss <= 59))
            {
                h = hh;
                m = mm;
                s = ss;
                return 1;
            }
            return 0;
        }
        void Show()
        {
            cout << h << ':' << m << ':' << s << endl;
        }
        void AddOneSecond()
        {
            if (s == 59)
            {
                if (m == 59)
                {
                    if (h == 23)
                    {
                        h = 0;
                        m = 0;
                        s = 0;
                        return;
                    }
                    else
                    {
                        h++;
                        m = 0;
                        s = 0;
                        return;
                    }
                    h++;
                    m = 0;
                    s = 0;
                    return;
                }
                m++;
                s = 0;
            }
            s++;
        }
        int AddNSeconds(int n)
        {
            int day = 0;
            for (int i = 0; i < n; i++)
            {
                AddOneSecond();
                if (h + m + s == 0)
                {
                    day++;
                }
            }
            return day;
        }
};

//StudybarCommentBegin
int main(void)
{
    int h, m, s;
    cin >> h >> m >> s;
    Cmytime t1;
    t1.Set(h, m, s);
    t1.Show();
    cout << endl << t1.Set(24, 0, 0) << "\n";
    t1.Show();
    t1.AddNSeconds(1);
    cout << endl;
    t1.Show();
    cout << endl << t1.AddNSeconds(3600 * 25);
    return 0;
}

//StudybarCommentEnd
