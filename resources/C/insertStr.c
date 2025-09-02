#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    char b[100];
    fgets(a, 100, stdin);   // 从标准输入流(stdin)中读取一行字符串，最多读取100个字符，存储到字符数组a中
    fgets(b, 100, stdin);
    if (a[strlen(a) - 1] == '\n')    // strlen()函数返回的是字符串的长度，不包括字符串结尾的'\0'字符
    {
        a[strlen(a) - 1] = 0;    // 把字符串a的最后一个字符'\n'替换为字符串结尾的'\0'(也就是0号字符)字符
    }
    if (b[strlen(b) - 1] == '\n')
    {
        b[strlen(b) - 1] = 0;
    }
    char max = 0;
    int maxindex = 0;
    for (int i = 0; a[i] != 0; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            maxindex = i;
        }
    }
    int strlenb = 0;
    for (int j = 0; b[j]!= 0; j++)
    {
        strlenb++;
    }
    for (int k = 1; k <= strlenb; k++)
    {
        a[maxindex + strlenb + k] = a[maxindex + k];
    }
    for (int w = 0; w < strlenb; w++)
    {
        a[maxindex + w + 1] = b[w];
    }
    printf("%s\n", a);

}
