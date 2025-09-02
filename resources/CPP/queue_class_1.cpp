#include <iostream>
using namespace std;

template <class T>
class Queue {
    private:
        T* array;
        int count;
        int SIZE;
    public:
        Queue();
        ~Queue();
        void insert(const T&);
        template <typename U>
        friend ostream& operator<<(ostream& os, const Queue<U>& obj);
};

template <class T>
Queue<T>::Queue() {
    count = 0;
    SIZE = 0;
    array = NULL;
}

template <class T>
Queue<T>::~Queue() {
    delete[] array;
}

template <class T>
void Queue<T>::insert(const T& obj) {
    if (SIZE == 0) {
        SIZE = 1;
        array = new T[SIZE];
        array[0] = obj;
        count = 1;
    } else if (count == SIZE) {
        SIZE = SIZE * 2;
        T* temp = new T[SIZE];
        for (int i = 0; i < count; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        array[count] = obj;
        count++;
    } else {
        array[count] = obj;
        count++;
    }
}

template <class T>
ostream& operator<<(ostream& os, const Queue<T>& obj) {
    for (int i = 0; i < obj.count; i++) {
        os << obj.array[i] << ' ';
    }
    return os;
}



//StudybarCommentBegin
int main()
{
	Queue<int> z1;
	int num[5]={2,4,6,8};
	int i,x;
	cin>>x;
	for(i=0;i<4;i++)
	{
		z1.insert(num[i]);
	}
	z1.insert(x);
	cout<<z1;
	return 0;
}
//StudybarCommentEnd
