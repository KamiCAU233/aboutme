//StudybarCommentBegin
#include <iostream>
using namespace std;
//StudybarCommentEnd


int middle(int a[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a[1];
}

double middle(double a[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i] > a[j])
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a[1];
}

unsigned middle(unsigned a[])
{
    for (unsigned i = 0; i < 3; i++)
    {
        for (unsigned j = 0; j < 3; j++)
        {
            if (a[i] > a[j])
            {
                unsigned temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a[1];
}

//StudybarCommentBegin
int main()
{
	int iNumber[3]={45,3,89};
	double dNumber[3]={12.4,6,55.8};
	unsigned uNumber[3]={345,776,565};

	cout<<"\nThe numbers are ";
	for(int i=0;i<3;i++)
		cout<<iNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(iNumber)<<endl;

	cout<<"\nThe numbers are ";
	for(int i=0;i<3;i++)
		cout<<dNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(dNumber)<<endl;

	cout<<"\nThe numbers are ";
	for(int i=0;i<3;i++)
		cout<<uNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(uNumber)<<endl;

	return 0;
}
//StudybarCommentEnd
