#include <iostream>
using namespace std;


template <class T, int numberOfElements> // 非常量参数，要求用户编译时传入一个常量值
class Array {
    private:
        T ptr[numberOfElements]; // ptr指向数组的起始位置
        int size; // 数组大小，即为numberOfElements
        static int arrayCount;  // 生成的类对象的总数
    public:
        int getSize() const {return size;}
        static int getArrayCount() {return arrayCount;}

        Array() : size(numberOfElements) {arrayCount++;}

        friend istream& operator>>(istream& is, Array<T, numberOfElements>& arr) {
            for (int i = 0; i < numberOfElements; i++) {
                is >> arr.ptr[i];
            }
            return is;
        }

        friend ostream& operator<<(ostream& os, const Array<T, numberOfElements>& arr) {
            for (int i = 0; i < numberOfElements; i++) {
                os << arr.ptr[i] << ' ';
            }
            return os;
        }
};


template <class T, int numberOfElements>
int Array<T, numberOfElements>::arrayCount = 0;


//StudybarCommentBegin
int main()
{
    // create intArray object
    Array< int, 5 > intArray1;

    // initialize intArray with user input values
    cin >> intArray1;

    // create intArray object
    Array< int, 5 > intArray2;

    // initialize intArray with user input values
    cin >> intArray2;

    // create floatArray
    Array< float, 5 > floatArray;

    cin >> floatArray;

    // output intArray1
    cout << "\nIntArray1 contains " << intArray1.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray1;

    // output intArray2
    cout << "\nIntArray2 contains " << intArray2.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray2;

    // output floatArray
    cout << "\nDoubleArray contains " << floatArray.getSize() << " Elements.\n";
    cout << "The values in the doubleArray are:\n";
    cout << floatArray;

    cout << "\nThere are " << Array<int,5>::getArrayCount() << " Array<int,5> objects.\n";
    cout << "\nThere are " << Array<float,5>::getArrayCount() << " Array<float,5> objects.\n";

    return 0;

} // end main


//StudybarCommentEnd
