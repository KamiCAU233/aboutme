#include <stdio.h>

#define max_rabbits 10000

int main()
{
    int lifespan[max_rabbits] = {0};
    lifespan[0] = 1;
    for (int i = 0; i < 20; i++)
    {
        int count = 0;
        for (int j = 0; j < max_rabbits; j++)
        {
            if (lifespan[j] != 0)
            {
                count++;
            }
        }
        int new_birth = 0;
        for (int k = 0; k < max_rabbits; k++)
        {
            if (lifespan[k] >= 3)
            {
                lifespan[count + new_birth] = 1;
                new_birth++;
            }
            if (lifespan[k] != 0)
            {
                lifespan[k]++;
            }
        }
        count += new_birth;
        printf("%i ", count);
    }
    printf("\n");
}

