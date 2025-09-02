#include <stdio.h>
#include <string.h>
int main()
{
    char x[200];
    fgets(x, 200, stdin);
    // Find the fifth comma;
    *strchr(x, ',') = 'x';
    *strchr(x, ',') = 'x';
    char *p_start = strchr(x, ',');
    *strchr(x, ',') = 'x';
    char *p_end = strchr(x, ',');
    printf("纬度为");
    for (char *k = p_start + 1; (long) k < (long) p_end; k++)
    {
        printf("%c", *k);
    }
    *strchr(x, ',') = 'x';
    p_start = strchr(x, ',');
    *strchr(x, ',') = 'x';
    p_end = strchr(x, ',');
    printf("\n经度为");
    for (char *k = p_start + 1; (long) k < (long) p_end; k++)
    {
        printf("%c", *k);
    }
    printf("\n");
}
