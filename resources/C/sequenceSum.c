//StudybarCommentBegin
#include <stdio.h>
int main()
{
    double equation(double x, int n);
    int n;
    double x;
    scanf("%lf%d", &x, &n);
    printf("%.4f\n", equation(x, n));
    return 0;
}
//StudybarCommentEnd

double fact(int n)
{
    double fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac = fac * i;
    }
    return fac;
}

double mypow(double x, int n)
{
    double pow = 1;
    for (int i = 0; i < n; i++)
    {
        pow = pow * x;
    }
    return pow;
}

double equation(double x, int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        double a_n = mypow(-1, i - 1) * mypow(x, i) / (double)fact(i);
        sum = sum + a_n;
    }
    return sum;
}
