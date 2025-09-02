#include <stdio.h>

void GetTumourInfo(int image[][100], int N, int *perimeter, int *area)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (image[i][j] <= 50)
            {
                (*area)++;
                if (i * j == 0 || i == N - 1 || j == N - 1)
                {
                    (*perimeter)++;
                }
                else
                {
                    int evaluation = (image[i][j - 1] <= 50) + (image[i][j + 1] <= 50) + (image[i - 1][j] <= 50) + (image[i + 1][j] <= 50);
                    if (evaluation < 4)
                    {
                        (*perimeter)++;
                    }
                }
            }
        }
    }
}
//StudybarCommentBegin
int main()
{
        int image[100][100], i, j, N, perimeter = 0, area = 0;
        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                    scanf("%d", &image[i][j]);
        }
        GetTumourInfo(image, N, &perimeter, &area);
        printf("%d ", area);
        printf("%d", perimeter);
        return 0;
}
//StudybarCommentEnd
