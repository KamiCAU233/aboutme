#include <stdio.h>

int notRepeated(int[5]);

int main()
{
    int self[5];
    int others[5]; // B E D C A
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &self[i]);
        scanf("%d", &others[i]);
    }
    for (int a = 1; a <= 5; a++)
    {
        for (int b = 1; b <= 5; b++)
        {
            for (int c = 1; c <= 5; c++)
            {
                for (int d = 1; d <= 5; d++)
                {
                    for (int e = 1; e <= 5; e++)
                    {
                        int rankings[5] = {a, b, c, d, e};
                        if (notRepeated(rankings))
                        {
                            if ((self[0] == a) + (others[0] == b) == 1)
                            {
                                if ((self[1] == b) + (others[1] == e) == 1)
                                {
                                    if ((self[2] == c) + (others[2] == d) == 1)
                                    {
                                        if ((self[3] == d) + (others[3] == c) == 1)
                                        {
                                            if ((self[4] == e) + (others[4] == a) == 1)
                                            {
                                                printf("A的名次是：%d\n", a);
                                                printf("B的名次是：%d\n", b);
                                                printf("C的名次是：%d\n", c);
                                                printf("D的名次是：%d\n", d);
                                                printf("E的名次是：%d\n", e);
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Can't found!\n");
}

int notRepeated(int x[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i != j && x[i] == x[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
