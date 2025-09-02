#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>

class DynamicVector
{
    public:
    T* array; // pointer to the items 指向分配空间的指针
    unsigned mallocSize; // number of allocated spaces 分配空间的大小
    unsigned numofItems; // number of items 向量内已经存储的元素数量
    int virtualZero; // virtual zero 数组起始下标，C语言中通常数组下标是从0开始， 这个数据属性可以让数组的下标从-10或2等等整数开始 ，让数组更加灵活。


    DynamicVector (int);

    DynamicVector(const DynamicVector& d) {
        mallocSize = d.mallocSize;
        numofItems = d.numofItems;
        virtualZero = d.virtualZero;
        array = new T[mallocSize];
        for (int i = 0; i < numofItems; i++) {
            array[i] = d.array[i];
        }
    }

    ~DynamicVector();

    DynamicVector& operator=(const DynamicVector<T>& d) {
        mallocSize = d.mallocSize;
        numofItems = d.numofItems;
        virtualZero = d.virtualZero;
        array = new T[mallocSize];
        for (int i = 0; i < numofItems; i++) {
            array[i] = d.array[i];
        }
        return *this;
    }

    inline void push_back (const T&);

    void push_back(const DynamicVector<T>& dv) {
        int new_size = mallocSize + dv.mallocSize;
        T* temp_arr = new T[new_size];
        for (int i = 0; i < numofItems; i++) {
            temp_arr[i] = array[i];
        }
        for (int p = numofItems; p < numofItems + dv.numofItems; p++) {
            temp_arr[p] = dv.array[p - numofItems];
        }
        array = temp_arr;
        mallocSize = new_size;
        numofItems = numofItems + dv.numofItems;
    }

     T& operator[] (int Vindex);
     const T& operator[] (int Vindex) const;

    unsigned length() const;

    unsigned capacity() const;

    int firstIndex() const;
};

template <class T>
DynamicVector<T>::DynamicVector(int Vindex)
{
    array = NULL;
    numofItems = 0;
    mallocSize = 0;
    virtualZero = Vindex;
}

template <class T>
 T& DynamicVector<T>::operator[] (int Vindex)
{
    int _entry = Vindex - virtualZero;
    if (_entry < 0 || _entry >= numofItems)
    {
    cout<<endl<<"Out Of Range";
    exit(1);
    }
    return array[_entry];
}

template <class T>
const T& DynamicVector<T>::operator[] (int Vindex) const
{
    int _entry = Vindex - virtualZero;
    if (_entry < 0 || _entry >= numofItems)
    {
    cout<<endl<<"Out Of Range";
    exit(1);
    }
    return array[_entry];
}
template <class T>
unsigned DynamicVector<T>::length() const
{
    return numofItems;
}

template <class T>
unsigned DynamicVector<T>::capacity() const
{
    return this->mallocSize;
}

template <class T>
int DynamicVector<T>::firstIndex() const
{
    return this->virtualZero;
}

template <class T>
DynamicVector<T>::~DynamicVector() {
    delete[] array;
}

template <class T>
inline void DynamicVector<T>::push_back(const T& newItem) {
    if (numofItems < mallocSize) {
        this->array[numofItems] = newItem;
        numofItems++;
    }
    else if (numofItems == mallocSize) {
        mallocSize = 2 * mallocSize + 1;
        T* temp_arr = new T[mallocSize];
        for (int i = 0; i < numofItems; i++) {
            temp_arr[i] = array[i];
        }
        temp_arr[numofItems] = newItem;
        numofItems++;
        delete[] array;
        array = temp_arr;
        for (int i = 0; i < numofItems; i++) {
            array[i] = temp_arr[i];
        }
    }
}

//StudybarCommentBegin
int main()
{
    int i,n;
    DynamicVector<int> ra(-2);

    cin>>n;
    ra.push_back(-3);
    ra.push_back(-2);
    ra.push_back(-1);
    for ( i = 0; i < n; i++)
    {
      ra.push_back(i);
    }
    cout<<"\n malloSize is "<<ra.capacity();
    cout<<"\n numofItems is "<<ra.length();
    cout<<"\n StartIndex is " << ra.firstIndex()<<endl;
    for ( i = -2; i < n+3; i++)
    {
      cout<<ra[i]<<" ";
    }


  return 0;
}

//StudybarCommentEnd
