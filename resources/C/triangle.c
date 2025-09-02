#include <stdio.h>

double cosine(double A, double *a);
int equal(double a, double b);

int main()
{
    double a[3];
    scanf("%lf,%lf,%lf", &a[0], &a[1], &a[2]);
    double cos[3];
    for (int var = 0; var < 3; var++)
    {
        if (a[var] <= 0)
        {
            printf("不是三角形\n");
            return -1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cos[i] = cosine(a[i], a);
    }
    int isRight = 0;
    for (int j = 0; j < 3; j++)
    {
        if (equal(cos[j], 0))
        {
            isRight = 1;
            break;
        }
    }
    int isIsoceles = 0;
    int isEquilateral = 0;
    for (int p = 0; p < 3; p++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (equal(cos[p], cos[j]) && p != j)
            {
                isIsoceles = 1;
                break;
            }
        }
    }
    for (int w = 0; w < 3; w++)
    {
        if (cos[w] > 1 || cos[w] < -1)
        {
            printf("不是三角形\n");
            return -1;
        }
    }
    if (isIsoceles)
    {
        printf("等腰");
    }
    if (isRight)
    {
        printf("直角");
    }
    if (isRight + isIsoceles == 0)
    {
        printf("一般");
    }
    printf("三角形\n");
}

double cosine(double A, double *a)
{
    int b, c;
    if (A == *a)
    {
        b = *(a + 1);
        c = *(a + 2);
    }
    if (A == *(a + 1))
    {
        b = *a;
        c = *(a + 2);
    }
    if (A == *(a + 2))
    {
        b = *(a + 1);
        c = *a;
    }
    double cosine = (b * b + c * c - A * A) / (2 * b * c);
    return cosine;
}

int equal(double a, double b)
{
    double difference;
    if (a > b)
    {
        difference = a - b;
    }
    else
    {
        difference = b - a;
    }
    return (difference < 1e-4);
}
