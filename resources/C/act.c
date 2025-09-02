//StudybarCommentBegin
#include <stdio.h>
#include <math.h>
int main()
{
	void act(int n);
	int n;
	scanf("%d", &n);
	act(n);
	return 0;
}
//StudybarCommentEnd

void act(int n)
{
    int prime[] = {47, 41, 37, 31, 29, 19, 17, 13, 11, 7, 5, 3, 2};
    int i = 0;
    while(n != 1)
    {
        if (n % prime[i] == 0)
        {
            printf("%d", prime[i]);
            n /= prime[i];
            if (n != 1)
            {
                printf(" ");
            }
        }
        else
        {
            i++;
        }
    }
    printf("\n");
}
