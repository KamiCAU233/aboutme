#include <math.h>  //引入头文件以使用sqrt()函数
#include <stdio.h>


int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c); // 获取a, b, c
    if (a == 0 && b == 0)
    {
        printf("Not an equation\n");
    }
    else if (a == 0 && b != 0)
    {
        double x = -c / b;  // 二次项系数为零时的解
        printf("%.2f\n", x);
    }
    else if (b*b - 4*a*c == 0) // 如果判别式为零，只需要打印一个解
    {
        double x = -b / (2*a);
        printf("%.2f\n", x);
    }
    else if (b*b - 4*a*c > 0) // 判别式大于零，直接求根公式
    {
        double x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
        double x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
        if (x1 < x2)
        {
            double tmp  = x1;   // 没法确定x1和x2大小，如果x1小的话，就把x1与x2交换一下：先找一个暂时的变量放一下x1的值，再把x1装上x2的值，最后把x2装上最先暂时变量的值
            x1 = x2;
            x2 = tmp;
        }
        printf("%.2f %.2f\n", x1, x2);
    }
    else
    {
        double delta = b*b - 4*a*c;
        double x = -b / (2*a);
        if (a < 0)  //如果a是负数，那么先输出的变成小的了，得反过来一下
        {
            a = -a;
        }
        double complex = sqrt( -delta) / (2*a); // 虚部
        printf("%.2f+%.2fi %.2f-%.2fi\n", x, complex, x, complex);
    }
}
