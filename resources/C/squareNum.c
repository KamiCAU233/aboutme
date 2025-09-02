#include <stdio.h>
#include <math.h>

int isSquare(int x);

int main()
{
    int num;
    int count = 0;
    scanf("%d", &num);
    for (int i = 0; i <= num; i++)
    {
        if (isSquare(i + 100) && isSquare(i + 268))
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
}

int isSquare(int x)
{
    int n = (int)sqrt(x);
    return (n * n == x);
}
