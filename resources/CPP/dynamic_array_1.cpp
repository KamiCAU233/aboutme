#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* array; //pointer  ，一个T类型的指针
    unsigned int mallocSize; //分配空间的大小。

public:
    // Constructors

    DynamicArray(unsigned length, const T &content) ; // mallocSize=length; 设置每个元素的初始内容是 content；

    // Destructors
    ~DynamicArray()
    {
        delete[] array;
        cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
    }

    // return the this->mallocSize
    unsigned int capacity() const;

    // for the array[i]=someT.
    const T& operator[](unsigned int i) const;
    T& operator[](unsigned int i);
};

template <typename T>
DynamicArray<T>::DynamicArray(unsigned length, const T& content) {
    mallocSize = length;
    array = new T[mallocSize];
    for (int i = 0; i < mallocSize; i++) {
        array[i] = content;
    }
    cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
}

template <typename T>
unsigned int DynamicArray<T>::capacity() const {
    return this->mallocSize;
}

template <typename T>
const T& DynamicArray<T>::operator[](unsigned int i) const {
    return array[i];
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int i) {
    return array[i];
}

//StudybarCommentBegin
int main()
{
    int length,i;
    cin >> length;

    DynamicArray<int> iarray(length,-1);
    DynamicArray<double> darray(length,-2.1);

    cout<<endl<<"capacity:"<<iarray.capacity()<<endl;

    for(i=0;i<length;i++) {
    cout << iarray[i] <<" ";
    iarray[i] = i*1.1;
    }
    cout<<endl;
    for(i=0;i<length;i++) {
    cout << darray[i] <<" ";
    darray[i] = i*1.1;
    }
    cout<<endl;
    for(i=0;i<length;i++) {
    cout << iarray[i] <<" ";
    iarray[i] = i*1.1;
    }
    cout<<endl;
    for(i=0;i<length;i++) {
    cout << darray[i] <<" ";
    }
}
//StudybarCommentEnd
