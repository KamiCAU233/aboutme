#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int total = 0;
    for (int i = 0; i < 1000000; i++)
    {
        int sum = 0;
        while (sum <= 50)
        {
            int num = rand() % n + 1;
            sum = sum + num;
        }
        total = total + sum;
    }
    printf("%.1f\n", 1.0 * total / 1000000);
}
