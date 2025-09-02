//StudybarCommentBegin
#include <stdio.h>

#define M 2
#define N 3

int main()
{
    double mean(double a[M][N], int m, int n);
	double a[M][N] = {{1, 2, 3}, {4, 5, 6}};
	printf("%lf\n", mean(a, 2, 3));
	return 0;
}
//StudybarCommentEnd

double mean(double a[M][N], int m, int n)
{
    int sum = 0;
    for (int r = 0; r < M; r++)
    {
        for (int c = 0; c < N; c++)
        {
            sum = sum + a[r][c];
        }
    }
    double result = 1.0 * sum / M / N;
    return result;
}
