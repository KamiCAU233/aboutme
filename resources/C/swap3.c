#include <stdio.h>
#include <string.h>

void swap(char *p1, char *p2);

int main()
{
    char a[100];
    char b[100];
    char c[100];

    fgets(a, 100, stdin);
    fgets(b, 100, stdin);
    fgets(c, 100, stdin);

    char* arr[3] = {a, b, c};
    for (int i = 0; i < 3; i++)
    {
        for (int j  = 0; j < 3; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0 && i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int p = 0; p < 3; p++)
    {
        printf("%s\n", arr[p]);
    }
}

void swap(char *p1, char *p2)
{
    char temp[100];
    strcpy(temp, p1);
    strcpy(p1, p2);
    strcpy(p2, temp);
}
