#include <stdio.h>

int main()
{
    int array[5];
    scanf("%i", array);
    for (int i = 0; i < 5; i++)
        printf("%i", &array[i]);
}
