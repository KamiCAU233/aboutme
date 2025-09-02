//StudybarCommentBegin
#include <stdio.h>

int main()
{
	void Calculate(int a, int b);
	int a, b;
	scanf("%d%d", &a, &b);
	Calculate(a, b);
	return 0;
}
//StudybarCommentEnd

void Calculate(int a, int b)
{
    printf("%i\n%i\n%i\n", a + b, a - b, a * b);
    if (b == 0)
    {
        printf("error\n");
    }
    else
    {
        printf("%.2f", 1.0 * a / b);
    }
}
