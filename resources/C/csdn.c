#include <stdio.h>
#include <string.h>
int main(){
	char a[50],b[50];
	scanf("%s\n%s", a, b);
	int max = 0;
	int i=0,k=0;
	char p[50];    //p用来存放最大元素后面的所有字符
	while(a[i]!='\0') i++;    //用一个循环先判断字符串的长度
	for(int j = 1;j<i;j++){    //将最大元素的下标赋值给max
		if(a[max]<a[j])
			max = j;
	}

	for(i = max+1;a[i]!='\0';i++,k++){    //把最大元素以后的字符全放入p
		p[k] = a[i];
	}
	p[k]='\0';
	a[max+1]='\0';    //将a最大元素之后全部清空
	//printf("%d\n",max);
	strcat(a,b);    //此时连接a,b
	strcat(a,p);    //再把后面的字符连接回去
	printf("%s\n",a);
}

