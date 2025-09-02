#include <stdio.h>

void move(int a, int b, int step);
void hanoi(int n, int start, int end, int aux, int step);

int count = 0;

int main()
{
    int n, step;
    scanf("%d%d", &n, &step);
    hanoi(n, 1, 3, 2, step);
}


void hanoi(int n, int start, int end, int aux, int step)
{
    if (n == 1)
    {
        move(start, end, step);
    }
    else
    {
        hanoi(n - 1, start, aux, end, step);
        move(start, end, step);
        hanoi(n - 1, aux, end, start, step);
    }
}

void move(int a, int b, int step)
{
    char sequence[3] = "abc";
    if (count + 1 == step)
    {
        printf("%c->%c\n", sequence[a - 1], sequence[b - 1]);
    }
    count++;
}
