#include<stdio.h>
#include<string.h>
int main()
{
	char str1[30], str2[30];
	char ch;
	scanf("%s\n", str1);
	scanf("%c", &ch);
	int i, n;
	n = 0;
	for (i = 0; i <= strlen(str1); i++)
	{
		if(str1[i] == ch)
		{
			continue;
		}
		str2[n] = str1[i];
		n++;
	}
	printf("%s", str2);
}
I~love~C~language~programming.
~
