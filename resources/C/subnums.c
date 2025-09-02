#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int sum[n];
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0;
    }
    int k = 0;
    int j = 0;
    while (k < n)
    {
        if (nums[k] < 0)
        {
            j++;
        }
        else if (nums[k] > 0)
        {
            sum[j] = sum[j] + nums[k];
        }
        k++;
    }
    for (int m = 0; m < n; m++)
    {
        for (int t = 0; t < n; t++)
        {
            if (sum[m] < sum[t] && m < t)
            {
                int tmp = sum[m];
                sum[m] = sum[t];
                sum[t] = tmp;
            }
        }
    }
    printf("%d\n", sum[0]);
}
