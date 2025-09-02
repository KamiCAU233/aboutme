//StudybarCommentBegin
#include <iostream>
#include <iterator>
using namespace std;
class MyLess {
public:
    bool operator() (int a1,int a2) {
        if( ( a1 % 10 ) < (a2 % 10) )
            return true;
        else
            return false;
    }
};

bool MyCompare(int a1, int a2)
{
    if( ( a1 % 10 ) < (a2 % 10) )
        return false;
    else
        return true;
}
//StudybarCommentEnd

// 修改 MyMax 为模板函数，支持任意可调用对象
template <typename Compare>
int* MyMax(int* begin, int* end, Compare Function) {
    int* max = begin;
    for (int i = 0; (begin + i) != end; i++) {
        if (!Function(*(begin + i), *max)) {
            max = begin + i;
        }
    }
    return max;
}

//StudybarCommentBegin
int main()
{
    int a[] = {35,7,13,19,12};
    cout << *MyMax(a, a + 5, MyLess()) << endl;
    cout << *MyMax(a, a + 5, MyCompare) << endl;
    return 0;
}
//StudybarCommentEnd
