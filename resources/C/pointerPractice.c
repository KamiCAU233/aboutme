#include <stdio.h>

void swap(int *ptr1, int *ptr2);

int main()
{
    int num1 = 1;
    int num2 = 2;
    swap(&num1, &num2);
    printf("%d %d\n", num1, num2);
}

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
