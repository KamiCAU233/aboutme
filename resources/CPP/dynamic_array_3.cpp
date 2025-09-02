#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* array; // pointer  ，一个T类型的指针
    unsigned int mallocSize; // 分配空间的大小。

public:
    // Constructors
    DynamicArray(unsigned int length, const T& content) ; // mallocSize=length; 设置每个元素的初始内容是 content；

    // Copy Constructor
    // cout<<endl<< "Copy Constructor is called";
    DynamicArray(const DynamicArray<T>& anotherDA);


    // Destructors
    ~DynamicArray();

    // return the this->mallocSize
    unsigned int capacity() const;

    // for the array[i]=someT.
    const T& operator[](unsigned int i) const;
    T& operator[](unsigned int i);
    DynamicArray& operator=(const DynamicArray& x);
};

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& anotherDA) {
    cout << endl << "Copy Constructor is called";
    this->mallocSize = anotherDA.mallocSize;
    this->array = new T[this->mallocSize];
    for (int i = 0; i < mallocSize; i++) {
        array[i] = anotherDA.array[i];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(unsigned int length, const T& content) {
    mallocSize = length;
    array = new T[mallocSize];
    for (int i = 0; i < mallocSize; i++) {
        array[i] = content;
    }
    cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
    cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
}


template <typename T>
unsigned int DynamicArray<T>::capacity() const {
    return this->mallocSize;
}

template <typename T>
const T& DynamicArray<T>::operator[](unsigned int i) const {
    return this->array[i];
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int i) {
    return this->array[i];
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& x) {
    cout << endl << "operator = is called";
    if (this == &x) {
        // 避免出现 a = a 的赋值情况
        return *this;
    }bb

    delete[] this->array;
    this->mallocSize = x.mallocSize;
    this->array = new T[this->mallocSize];
    for (int i = 0; i < x.mallocSize; i++) {
        array[i] = x.array[i];
    }
    return *this;
}


//StudybarCommentBegin
int main()
{
    int length,i;
    cin >> length;

    DynamicArray<int> iarray(length, -1);

    DynamicArray<int> iarray2(iarray), iarray3(iarray2);

    cout << endl;
    for(i = 0; i < length; i++) {
        cout << iarray3[i] << " ";
        iarray[i] = i * 1.1;
    }
    iarray3 = iarray2 = iarray;
    cout << endl;
    for(i = 0; i < length; i++) {
        cout << iarray3[i] << " ";
    }

    return 0;
}
//StudybarCommentEnd
