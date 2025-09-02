#include <stdio.h>
#include <string.h>

int upper(char p[]);
int lower(char p[]);
int space(char p[]);
int other(char p[]);
int num(char p[]);

int main()
{
    char p1[100], p2[100], p3[100];
    fgets(p1, 100, stdin);
    fgets(p2, 100, stdin);
    fgets(p3, 100, stdin);
    int uppers = upper(p1) + upper(p2) + upper(p3);
    int lowers = lower(p1) + lower(p2) + lower(p3);
    int spaces = space(p1) + space(p2) + space(p3);
    int nums = num(p1) + num(p2) + num(p3);
    int others =  other(p1) + other(p2) + other(p3) - 2; // Minus 2 for handling the character'\n';
    printf("Daxie=%i\nXiaoxie=%i\nShuzi=%i\nKongge=%i\nQita=%i\n", uppers, lowers, nums, spaces, others);
}

int upper(char p[])
{
    int count = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        if (p[i] >= 'A' && p[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}

int lower(char p[])
{
    int count = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            count++;
        }
    }
    return count;
}

int num(char p[])
{
    int count = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        if ((p[i] >= '1' && p[i] <= '9') || p[i] == '0')
        {
            count++;
        }
    }
    return count;
}

int space(char p[])
{
    int count = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        if (p[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int other(char p[])
{
    int others = strlen(p) - upper(p) - lower(p) - num(p) - space(p);
    return others;
}
