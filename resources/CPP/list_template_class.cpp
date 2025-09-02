// NEW: CLASS TEMPLATE!

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class List
{
private:
	T data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
    List(const T);
    List(const List<T>& cp);
    List(const vector<T>& vt);
    List(const T*, int len);
	void append(T val);	// 链尾增加一个元素
	void insertElement(int pos, T val);	// 在指定位置后添加一个元素
	void deleteElement(T val);	// 删除元素
	void travalList() const;	// 从头节点遍历输出链表
    int getLength() const;
    int length() const;
    bool isEqual(const List<T>& other) const;
    void connect(const List<T>& other);
};

#define nullptr NULL

template <class T>
List<T>::List() {
    link = nullptr;
}

template <class T>
List<T>::List(const T d) {
    data = d;
    link = nullptr;
}

template <class T>
List<T>::List(const List<T>& cp) {
    this->data = cp.data;
    if (cp.link == nullptr) {
        this->link = nullptr;
        return;
    }
    List<T>* p = new List(*(cp.link));
    this->link = p;
}

template <class T>
List<T>::List(const vector<T>& vt) {
    List<T>* p = this;
    for (int i = 0; i < vt.size(); i++) {
        p->link = new List(vt[i]);
        p = p->link;
    }
}

template <class T>
List<T>::List(const T* array, int len) {
    List<T>* p = this;
    for (int i = 0; i < len; i++) {
        p->link = new List(array[i]);
        p = p->link;
    }
}

template <class T>
void List<T>::append(T val) {
    // HEAD: this
    List<T>* p = this;
    while (p->link != nullptr) {
        p = p->link;
    }
    p->link = new List();
    p->link->data = val;
}

template <class T>
void List<T>::insertElement(int pos, T val) {
    // HEAD: this->link 基于测试用例给出
    List<T>* p = this->link;
    for (int i = 0; i < pos; i++) {
        p = p->link;
    }
    List<T>* inserted_list_ptr = new List();
    inserted_list_ptr->data = val;
    inserted_list_ptr->link = p->link;
    p->link = inserted_list_ptr;
}

template <class T>
void List<T>::deleteElement(T val) {
    // HEAD: this
    int count = 0;
    for (List<T>* p = this; p != nullptr; p = p->link) {
        if (p->link == nullptr) {
            if (count == 0) cout << "Element "<< val << " not Found." << endl;
            return;
        }
        if (p->link->data == val) {
            p->link = p->link->link;
            count++;
        }
    }
    if (count == 0) cout << "Element "<< val << " not Found." << endl;
}

template <class T>
void List<T>::travalList() const {
    // const List* p 代表指针所指的地址可以改变，但是指针所指的内容不可以改变，可看作 (const List)* p
    for (const List<T>* p = this->link; p != nullptr; p = p->link) {
        // 不要管 this->data 里面的内容了，沟槽的构造函数没初始化
        cout << "->" << p->data;
    }
    cout << endl;
}

template <class T>
int List<T>::getLength() const {
    // cout << "The length of this List is " << length() << '.' << endl;
    return length();
}

template <class T>
int List<T>::length() const {
    int length = 0;
    for (const List<T>* p = this->link; p != nullptr; p = p->link) {
        length++;
    }
    return length;
}

template <class T>
bool List<T>::isEqual(const List<T>& other) const {
    // const List* p 代表指针所指的地址可以改变，但是指针所指的内容不可以改变，可看作 (const List)* p
    const List<T>* p = this->link;
    const List<T>* q = other.link;
    while (p != nullptr && q != nullptr) {
        if (p->data != q->data) {
            return false;
        }
        p = p->link;
        q = q->link;
    }
    return (this->length() == other.length());
}

template <class T>
void List<T>::connect(const List<T>& other) {
    List<T>* p = this;
    while (p->link != nullptr) {
        p = p->link;
    }
    p->link = other.link;
    // cout << "After connect:" << endl;
}


//StudybarCommentBegin
int main()
{
	int a, i, lengthA, lengthB;
	int in1[100], in2[100];

	for (i = 0, lengthA = 1; cin >> a; i++, lengthA++){
                in1[i] = a;
                if('\n' == getchar()){
                    break;
                }
	}
	for (i = 0, lengthB = 1; cin >> a; i++, lengthB++){
                in2[i] = a;
                if('\n' == getchar()){
                    break;
                }
	}
	List<int> listA(in1, lengthA), listB(in2,lengthB);

	listA.travalList();
	listB.travalList();
	if (listA.isEqual(listB))
		cout << "They are the same LinkList." << endl;
	else
		cout << "They are different LinkList." << endl;
	listA.connect(listB);
        cout << "After connect:" << endl;
	cout << "The length of this List is " << listA.getLength() << "." <<endl;
	listA.travalList();
}
//StudybarCommentEnd
