//StudybarCommentBegin

#include <stdio.h>
#include <math.h>
int main()
{
	void primes(int a, int b);
	int a, b;
	scanf("%d%d", &a, &b);
	primes(a, b);
	return 0;
}
//StudybarCommentEnd

void primes(int a, int b)
{
    int count = 0;
    int isPrime(int x);
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            printf("%i ", i);
            count++;
        }
    }
    printf("\n%i\n", count);
}

int isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
