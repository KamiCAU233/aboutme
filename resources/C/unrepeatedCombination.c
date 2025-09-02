#include <stdio.h>

int main()
{
    for (int hundreds = 1; hundreds <= 4; hundreds++)
    {
        for (int tens = 1; tens <= 4; tens++)
        {
            for (int ones = 1; ones <= 4; ones++)
            {
                if (ones != tens && tens != hundreds && ones != hundreds)
                {
                    printf("%i\n", hundreds * 100 + tens * 10 + ones);
                }
            }
        }
    }
}
