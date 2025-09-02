#include <stdio.h>

int step = 0;

int main()
{
    void hanoi(int n, int start, int end, int aux);
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    printf("%d\n", step);
}

void hanoi(int n, int start, int end, int aux)
{
    void move(int a, int b);
    if (n == 1)
    {
        move(start, end);
    }
    else
    {
        hanoi(n - 1, start, aux, end);
        move(start, end);
        hanoi(n - 1, aux, end, start);
    }
}

void move(int a, int b)
{
    step++;
}
