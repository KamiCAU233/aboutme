#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int counter = 0;
    int total = 0;
    int i = 1;
    while (i <= 20)
    {
        int j = 1;
        while (j <= 20)
        {
            int k = 1;
            while (k <= 20)
            {
                int l = 1;
                while (l <= 20)
                {
                    int m = 1;
                    while (m <= 20)
                    {
                        if (i + j + k + m + l == n)
                        {
                            counter++;
                        }
                        total++;
                        m++;
                    }
                    l++;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    printf("%.2f\n", 1.0 * counter / total);
}
