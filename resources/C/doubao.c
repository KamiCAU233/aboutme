#include <stdio.h>
#include <string.h>

// 找到字符串中最大元素（按照ASCII码值比较）的位置
int findMaxIndex(char *str) {
    int maxIndex = 0;
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        if (str[i] > str[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    char a[100];  // 存储输入的字符串a，假设最大长度为100，可根据实际情况调整
    char b[100];  // 存储输入的字符串b，假设最大长度为100，可根据实际情况调整

    // 输入字符串a
    scanf(" %s", a);
    // 输入字符串b
    scanf(" %s", b);

    int maxIndex = findMaxIndex(a);
    int lenA = strlen(a);
    int lenB = strlen(b);
    // 创建一个新的字符数组来存储最终结果，长度为字符串a和b长度之和再加1（用于存放字符串结束标志'\0'）
    char result[lenA + lenB + 1];

    // 先将字符串a中最大元素之前的部分复制到结果数组
    for (int i = 0; i <= maxIndex; i++) {
        result[i] = a[i];
    }
    // 再将字符串b复制到结果数组
    for (int i = 0; i < lenB; i++) {
        result[maxIndex + 1 + i] = b[i];
    }
    // 最后将字符串a中最大元素之后的部分复制到结果数组
    for (int i = maxIndex; i < lenA; i++) {
        result[lenB + maxIndex + 1 + (i - maxIndex)] = a[i];
    }
    result[lenA + lenB] = '\0';

    printf("%s\n", result);

    return 0;
}
