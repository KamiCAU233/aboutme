//StudybarCommentBegin
#include <iostream>
using namespace std;
void swap(int *, int *);
int main()
{
     int i, j;
	 cin >> i >>j ;
     swap(&i, &j);
     cout<< i << " " << j << endl;
     return 0;
}
//StudybarCommentEnd


void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
