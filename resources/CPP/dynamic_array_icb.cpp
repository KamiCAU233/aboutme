#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
    private:
        unsigned int size;
        T* array;
    public:
        // Constructor
        DynamicArray() {
            this->size = 0;
            this->array = NULL;
        }

        DynamicArray(unsigned int length, const T& content) {
            this->size = length;
            cout << endl << "new T[" << this->size << "] malloc " << this->size << "*"
                 << sizeof(T) << "=" << this->size * sizeof(T) << " bytes memory in heap";
            this->array = new T[size];
            for (int i = 0; i < length; i++) {
                array[i] = content;
            }
        }

        // Copy Constructor
        DynamicArray(const DynamicArray<T>& anotherDA) {
            cout << endl << "Copy Constructor is called";
            this->size = anotherDA.size;
            this->array = new T[this->size];
            for (int i = 0; i < this->size; i++) {
                array[i] = anotherDA.array[i];
            }
        }

        // Destructor
        ~DynamicArray() {
            cout << endl << "delete[] array free " << this->size << "*" << sizeof(T)
                 << "=" << this->size * sizeof(T) << " bytes memory in heap";
            delete[] array;
        }

        // Deep Copy with =
        DynamicArray<T>& operator=(const DynamicArray<T>& anotherDA) {
            // Stuck here for quite a long time: The argument MUST BE const to enable "a[i] = 2"
            cout << endl << "operator = is called";
            if (this != &anotherDA) {
                size = anotherDA.size;
                delete[] array;
                array = new T[size];
                for (int i = 0; i < size; i++) {
                    array[i] = anotherDA.array[i];
                }
            }
            return *this;
        }

        int resize(unsigned int newSize, const T& ValOfNewItems) {
            cout << "\nresize is called";
            if (newSize > size) {
                T* temp_arr = new T[newSize];
                for (int i = 0; i < size; i++) {
                    temp_arr[i] = array[i];
                }
                for (int i = size; i < newSize; i++) {
                    temp_arr[i] = ValOfNewItems;
                }
                delete[] array;
                array = temp_arr;
                size = newSize;
                return 1;
            }
            else if (newSize == size) {
                return 0;
            }
            else {
                T* temp_arr = new T[newSize];
                for (int i = 0; i < newSize; i++) {
                    temp_arr[i] = array[i];
                }
                delete[] array;
                array = temp_arr;
                size = newSize;
                return -1;
            }

        }

        T& operator[](int index) {
            return array[index];
        }

        const T& operator[](int index) const {
            return array[index];
        }

        unsigned int capacity() const {
            return size;
        }
};

//StudybarCommentBegin
int main()
{
	int i,j;
	DynamicArray<int>  a(20, 0);
	DynamicArray< DynamicArray<int> > b(10, a);
	b[0].resize(30, 1);
	b[5].resize(10, 5);
	for(i=0;i<10;i++)
	{	cout<<"\n";
		for(j=0;j<b[i].capacity();j++)
		{	cout<<" "<<b[i][j] ;}
	}
	return 0;
}
//StudybarCommentEnd
