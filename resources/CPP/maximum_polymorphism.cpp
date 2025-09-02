#include <iostream>
using namespace std;

double maxinum(double a, double b, double c)
{
    double max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if (c > max)
    {
        return c;
    }
    return max;
}


int maxinum(int a, int b, int c)
{
    int max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if (c > max)
    {
        return c;
    }
    return max;
}

char maxinum(char a, char b, char c)
{
    char max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if (c > max)
    {
        return c;
    }
    return max;
}


//StudybarCommentBegin
int main()
{
    int b1, b2, b3;
	float c1, c2, c3;
	char a1, a2, a3;
	cin >> b1 >> b2 >> b3 >> c1 >> c2 >> c3>> a1 >> a2 >> a3;
	cout << maxinum(b1, b2, b3) << ' ' << maxinum(c1, c2, c3) << ' ' << maxinum(a1, a2, a3);
	return 0;
}
//StudybarCommentEnd
