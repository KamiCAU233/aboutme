#include <stdio.h>

int main()
{
    for (int i = 1; i < 100; i++)
    {
        int d;
        if (i < 10) d = 10;
        else d = 100;

        if ((i * i - i) % d == 0 )
        {
              if (i != 1) printf(" ");
              printf("%i", i);
        }
    }
    printf("\n");
}
