#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N 50000
#define MAX_STUDENTS 366  // 假设最多有366个不同的生日（包括闰年）

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > MAX_STUDENTS) {
        printf("n should be less than or equal to %d\n", MAX_STUDENTS);
        return 1;
    }
    srand(time(NULL));
    int* birth = (int*)malloc(n * sizeof(int));
    if (birth == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int birth_count[366] = {0};
        for (int j = 0; j < n; j++)
        {
            birth[j] = rand() % 365 + 1;
            birth_count[birth[j] - 1]++;
        }
        int sum = 0;
        for (int j = 0; j < 366; j++)
        {
            int count_j = birth_count[j];
            sum += count_j * (count_j - 1) / 2;  // 使用组合数学计算匹配的对数
        }
        if (sum >= m)
        {
            count++;
        }
    }
    double p = 1.0 * count / N;
    printf("%.2lf\n", p);
    free(birth);
    return 0;
}
