#include <iostream>
using namespace std;

class Cmytime
{
    private:
        int h, m, s;
    public:
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
    Cmytime t1(3, 2, 1);
    t1.Show();
    cout << "\n";
    t1.Set(h, m, s);
    t1.Show();
    return 0;
}
//StudybarCommentEnd
