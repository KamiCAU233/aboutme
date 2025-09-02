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
        T remove();
        void clear();
        const T& getFront() const;
        int getLength() const;
        bool isEmpty() const;
        bool isFull() const;
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
T Queue<T>::remove() {
    if (count == 0) {
        cout << "The queue is empty" << endl;
        exit(1);
    }
    count--;
    T deque_value = array[0];
    for (int i = 0; i < count; i++) {
        array[i] = array[i + 1];
    }
    return deque_value;
}

template <class T>
void Queue<T>::clear() {
    SIZE = 0;
    count = 0;
}

template <class T>
const T& Queue<T>::getFront() const {
    if (count == 0) {
        cout << "The queue is empty" << endl;
        exit(1);
    }
    return array[0];
}

template <class T>
int Queue<T>::getLength() const {
    return count;
}

template <class T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <class T>
bool Queue<T>::isFull() const {
    return count == SIZE;
}

template <class T>
ostream& operator<<(ostream& os, const Queue<T>& obj) {
    for (int i = 0; i < obj.count; i++) {
        os << obj.array[i] << ' ';
    }
    os << endl;
    return os;
}


//StudybarCommentBegin
int main()
{
	Queue<double> z1;
	double num[5]={2.53,4.3,6.75,8.9};
	int i;
	double x;
	cin>>x;
	for(i=0;i<4;i++)
	{
		z1.insert(num[i]);
	}
	cout<<z1.getLength();  //初始定义的数组长度

	cout<<endl;

	z1.insert(x);         //插入一个double类元素

	cout<<z1.isFull()<<endl;   //判断是否为满

	cout<<z1.getLength(); //插入元素后的长度

	cout<<endl;

	cout<<z1.getFront();  //初始队首元素值

	cout<<endl;

	z1.remove();    //删掉队首元素

	cout<<z1.getFront();  //删除后的队首元素

	cout<<endl;

	cout<<z1;              //输出现在z1中的各元素值

	z1.clear();            //清空z1

	cout<<z1.isEmpty()<<endl;    //判断是否为空

	z1.getFront();         // 访问队首元素

	return 0;
}
//StudybarCommentEnd
