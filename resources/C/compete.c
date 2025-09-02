#include <stdio.h>

int main()
{
    char A, B, C;
    for (A = 'X'; A <= 'Z'; A++)
    {
        for (B = 'X'; B <= 'Z'; B++)
        {
            for (C = 'X'; C <= 'Z'; C++)
            {
                if (A != 'X' && C != 'X' && C != 'Z' && A!= B && B != C && A != C)
                {
                    printf("A-%c;B-%c;C-%c\n", A, B, C);
                }
            }
        }
    }
}
