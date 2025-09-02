//StudybarCommentBegin
#include <stdio.h>
#include <math.h>

double f2(double x)
{
    return x * x * x * x * x - 20 * x * x - 1;  // 这是要求零点的函数，直接f2(x)就可以算出该函数在x这点的值
}
//StudybarCommentEnd

double bisection(double a, double b)    // 这是我们需要实现的函数 bisection(double a, double b)，意思是在区间(a, b)中寻找函数y = f2(x)的零点
{
	if (fabs(a - b) < 0.000001) // 如果 a 与 b 的区间长度小于这个0.000001 的话
	{
		return (a + b) / 2;  // 直接return a 与 b 的区间中点作为方程的解
	}
	else
	{
		if (f2(a) * f2((a + b) / 2) < 0)  // 如果 a 与区间中点符号相反
		{
			return bisection(a, (a + b) / 2); // 那就再以 a 和 区间中点 为两个端点，寻找这两个端点之间的零点并返回
		}
		else if (f2(b) * f2((a + b) / 2) < 0) // 如果 区间中点 与 b 符号相反
		{
			return bisection((a + b) / 2, b); // 那就再以 区间中点 和 b 为两个端点，寻找这两个端点之间的零点并返回
		}
	}
	return -1; // 非空必须返回一个值，如果上面的路都走不通，那就返回一个-1当作报错吧，后面就可以进行报错的处理。

}


//StudybarCommentBegin
int main(int argc, char* argv[])    // main后面括号内的参数这里是没用的，可以直接删去
{
	printf("\n%.2lf", bisection(0, 10));  // 打印出在0到10之间找到这个函数的零点。
	return 0;
}
//StudybarCommentEnd
