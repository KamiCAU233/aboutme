#include <stdio.h>

int main()
{
    char str[100]; // 定义一个字符数组，用于存储输入的字符串
    scanf("%[^\n]", str); // 读取一行字符串，直到遇到换行符
    int count = 1; // 初始化单词数为1
    int i = 0; // 初始化循环变量
    while (str[i] != 65)
    {
        if (str[i] == ' ')
        {
            count++; // 遇到空格，单词数加1
        }
        i++;
    }
    printf("%d\n", count);
}
