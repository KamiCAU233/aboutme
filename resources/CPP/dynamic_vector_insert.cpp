#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>

class DynamicVector
{
    public:
    T* array; // pointer to the items
    unsigned mallocSize; // number of allocated spaces
    unsigned numofItems; // number of items
    int virtualZero; // virtual zero

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

    bool operator== (const  DynamicVector<T>& dv) const {
    	for (int i = 0; i < numofItems; i++) {
    		if (dv.array[i] != (array[i])) {
    			return false;
    		}
    	}
    	return this->firstIndex() == dv.firstIndex();
    }
    void insert(int Vindex, const T& val) {
    	Vindex = Vindex - virtualZero;
    	if (mallocSize < numofItems + 1) {
    		mallocSize = numofItems + 1;
    	}
    	T* temp_arr = new T[mallocSize];
    	for (int i = 0; i < Vindex; i++) {
    		temp_arr[i] = array[i];
    	}
    	temp_arr[Vindex] = val;
    	numofItems++;
    	for (int i = Vindex; i < numofItems; i++)
    	{
    		temp_arr[i + 1] = array[i];
    	}
    	delete[] array;
    	array = temp_arr;
    }

	friend ostream& operator<< (ostream& os, const DynamicVector<T>& dv) {
		if (dv.numofItems == 0) {
			os << "The arrray is empty." << endl;
		}
		else {
			for (int i = 0; i < dv.numofItems; i++)
			{
				os << dv.array[i] << ' ';
			}
		}
		// os << endl;
		return os;
	}

	void remove() {
		numofItems--;
	}

	void remove(int Vindex) {
		Vindex = Vindex - virtualZero;
		for (int i = Vindex; i < numofItems - 1; i++)
		{
			array[i] = array[i + 1];
		}
		numofItems--;
	}

	void remove(int Vfirst, int Vlast) {
		Vfirst -= virtualZero;
		Vlast -= virtualZero;
		mallocSize = numofItems;
		numofItems -= (Vlast - Vfirst);
		T* temp_arr = new T[mallocSize];
		for (int i = 0; i < Vfirst; i++)
		{
			temp_arr[i] = array[i];
		}
		for (int i = Vfirst; i < numofItems; i++)
		{
			temp_arr[i] = array[i + (Vlast - Vfirst)];
		}
		delete[] array;
		array = temp_arr;

	}
    void swap(DynamicVector<T>& dv) {
        DynamicVector<T> temp(*this);
        *this = dv;
        dv = temp;
    }
    DynamicVector<T> operator() (int Vfirst, int Vlast) const {
        int start = Vfirst - virtualZero;
        int end = Vlast - virtualZero;
        int numElements = end - start;
        DynamicVector<T> subVector(Vfirst);
        subVector.mallocSize = numElements;
        subVector.numofItems = numElements;
        subVector.array = new T[numElements];

        for (int i = 0; i < numElements; i++) {
            subVector.array[i] = array[start + i];
        }
        return subVector;
    }

    T* begin() const {
        return array;
    }

    T* end() const {
        return array + numofItems;
    }
    DynamicVector(T* const first, T* const last, int Vindex = 0) {
        int eleCount = distance(first, last);
        virtualZero = Vindex;
        mallocSize = eleCount + 1;
        numofItems = eleCount;
        array = new T[eleCount + 1];
        for (int i = 0; i < eleCount; i++) {
            array[i] = *(first + i);
        }
    }

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

    DynamicVector<int> ra(-2);


    int i,n;
    cin>>n;

    cout<<ra;

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
    for ( i = -2; i < n+1; i++)
    {
      cout<<ra[i]<<" ";
    }
    cout<<endl;
    DynamicVector<int> raCopy(ra);
    cout<<"\n malloSize is "<<raCopy.capacity();
    cout<<"\n numofItems is "<<raCopy.length();
    cout<<"\n StartIndex is " << raCopy.firstIndex()<<endl;
    cout<<endl;
    for ( i = -2; i < n+1; i++)
    {   cout<<++ra[i]<<" ";
    }
    cout<<endl;
    for ( i = -2; i < n+1; i++)
    {   cout<<raCopy[i]<<" ";
    }

    raCopy=ra;
    if (ra==raCopy)  cout<<"\n ra == raCopy";
    else cout<<"\n ra != raCopy";


    ra[-2]=100;

    if (ra==raCopy)  cout<<"\n ra == raCopy";
    else cout<<"\n ra != raCopy";

    raCopy.push_back(ra);
    cout<<endl;
    int firstI=raCopy.firstIndex();
    for ( i = 0; i < raCopy.length() ; i++)
    {   cout<<raCopy[i+firstI ]<<" ";
    }
    cout<<endl;
    raCopy.insert(-2,6);
    raCopy.insert(-1,7);
    cout<<raCopy;


  return 0;
}
//StudybarCommentEnd
