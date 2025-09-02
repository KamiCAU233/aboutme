#include <stdio.h>

int isValid(int r[], int num1, int rank1, int num2, int rank2);

int isDifferent(int r[5]);

int main()
{
    int r[5];
    for (r[0] = 1 ; r[0] <= 5; r[0]++)
    {
        for (r[1] = 1; r[1] <= 5; r[1]++)
        {
            for (r[2] = 1; r[2] <= 5; r[2]++)
            {
                for (r[3] = 1; r[3] <= 5; r[3]++)
                {
                    for (r[4] = 1; r[4] <= 5; r[4]++)
                    {
                        int validity = isValid(r, 2, 2, 1, 3) + isValid(r, 2, 2, 5, 4) + isValid(r, 3, 1, 4, 2) + isValid(r, 3, 5, 4, 3) + isValid(r, 5, 4, 1, 1);
                        if (validity == 5 && isDifferent(r))
                        {
                            printf("A:%i\nB:%i\nC:%i\nD:%i\nE:%i\n", r[0], r[1], r[2], r[3], r[4]);
                        }
                    }
                }
            }
        }
    }
}


int isValid(int r[], int num1, int rank1, int num2, int rank2)
{
    int index1 = num1 - 1;
    int index2 = num2 - 1;
    if ((r[index1] == rank1 && r[index2] != rank2) || (r[index1] != rank1 && r[index2] == rank2))
    {
        return 1;
    }
    return 0;
}

int isDifferent(int r[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (r[i] == r[j] && i != j)
            {
                return 0;
            }
        }
    }
    return 1;
}

 // Iterate over all possible cases and check if pretexts correspond.
