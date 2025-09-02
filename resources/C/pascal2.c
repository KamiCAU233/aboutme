#include <stdio.h>

int getPascal(int row, int index); // all zero-based index

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%5i", getPascal(i, j));
        }
        printf("\n");
    }
}

int getPascal(int row, int index) // all zero-based index
{
    if (index == 0 || index == row)
    {
        return 1;
    }
    else if (index > 0 && index < row)
    {
        return (getPascal(row - 1, index - 1) + getPascal(row - 1, index));
    }
    return 0;
}
