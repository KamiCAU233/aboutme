#include <stdio.h>

double getPi(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            return (getPi(n - 1) - 1.0 / (2 * n - 1));
        }
    }
    return (getPi(n - 1) + 1.0 / (2 * n - 1));
}


double calculatePi(int n)
{
    return 4 * getPi(n);
}

//StudybarCommentBegin
int main()
{
    int n;
    scanf("%d", &n);
    double pi = calculatePi(n);
    printf("%.5lf", pi);
    return 0;
}
//StudybarCommentEnd
