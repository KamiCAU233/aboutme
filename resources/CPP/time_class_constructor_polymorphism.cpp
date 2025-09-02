#include <iostream>
using namespace std;

class Cmytime
{
    private:
        int h, m, s;

    public:
        Cmytime()
        {
            h = 0;
            m = 0;
            s = 0;
        }
        Cmytime(int hh)
        {
            h = hh;
            m = 0;
            s = 0;
        }
        Cmytime(int hh, int mm, int ss)
        {
            h = hh;
            m = mm;
            s = ss;
        }
        void Set(int hh, int mm, int ss)
        {
            h = hh;
            m = mm;
            s = ss;
        }
        void Show()
        {
            cout << h << ':' << m << ':' << s;
        }

};



//StudybarCommentBegin
int main(void)
{
    int h, m, s;
    cin >> h >> m >> s;
    Cmytime t1(3, 2, 1), t2, t3(5);
    t1.Show();
    cout << "\n";
    t1.Set(h, m, s);
    t1.Show();
    cout << "\n";
    t2.Show();
    cout << "\n";
    t3.Show();
    return 0;
}

//StudybarCommentEnd
