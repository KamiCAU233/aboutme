#include <iostream>
using namespace std;


class Point {
    private:
        int x = 0, y = 0;
    public:
        Point(int xx = 0, int yy = 0) : x(xx), y(yy) {
            cout << "\nPoint is called!";
        }
        ~Point() {
            cout << "\n~Point is called!";
        }


        friend ostream& operator<<(ostream& os, const Point &p) {
            os << '(' << p.x << ',' << p.y << ')';
            return os;
        }
};

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

    int resize(unsigned int newSize, const T& ValOfNewItems) {
        cout << "\nresize is called";
        if (newSize > this->mallocSize) {
            T* temp_arr = new T[newSize];
            for (int i = 0; i < mallocSize; i++) {
                temp_arr[i] = array[i];
            }
            for (int i = this->mallocSize; i < newSize; i++) {
                temp_arr[i] = ValOfNewItems;
            }
            delete[] array;
            array = temp_arr;
            this->mallocSize = newSize;
            return 1;
        }
        else if (newSize == this->mallocSize) {
            return 0;
        }
        else {
            T* temp_arr = new T[newSize];
            for (int i = 0; i < newSize; i++) {
                temp_arr[i] = this->array[i];
            }
            delete[] this->array;
            this->array = temp_arr;
            this->mallocSize = newSize;
            return -1;
        }
    }
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
    cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
    array = new T[mallocSize];
    for (int i = 0; i < mallocSize; i++) {
        array[i] = content;
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
    delete[] array;
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
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& anotherDA) {
    cout << endl << "operator = is called";
    if (this != &anotherDA) {
        delete[] array;
        mallocSize = anotherDA.mallocSize;
        array = new T[mallocSize];
        for (int i = 0; i < mallocSize; i++) {
            array[i] = anotherDA.array[i];
        }
    }
    return *this;
}



//StudybarCommentBegin
int main()
{
    int length, i;
    cin >> length;

    DynamicArray<Point> iarray(length, Point(3));
    DynamicArray<Point> iarray2(iarray), iarray3(iarray2);
    cout << endl;
    for (i = 0; i < length; i++) {
        cout << iarray3[i] <<" ";
        iarray[i] = Point(i, i + 1);
    }
    iarray3 = iarray2 = iarray;
    cout << endl;
    for(i = 0; i < length; i++) {
        cout << iarray3[i] <<" ";
    }

    return 0;
}
//StudybarCommentEnd
