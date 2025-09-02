// NEW: isEqual() method, connect() method

#include <iostream>
#include <vector>
using namespace std;

class List
{
private:
	int data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
    List(const int);
    List(const List& cp);
    List(const vector<int>& vt);
	void append(int val);	// 链尾增加一个元素
	void insertElement(int pos, int val);	// 在指定位置后添加一个元素
	void deleteElement(int val);	// 删除元素
	void travalList() const;	// 从头节点遍历输出链表
    void getLength() const;
    int length() const;
    bool isEqual(const List& other) const;
    void connect(const List& other);
};

#define nullptr NULL
List::List() {
    data = -1;
    link = nullptr;
}

List::List(const int d) {
    data = d;
    link = nullptr;
}

List::List(const List& cp) {
    this->data = cp.data;
    if (cp.link == nullptr) {
        this->link = nullptr;
        return;
    }
    List* p = new List(*(cp.link));
    this->link = p;
}

List::List(const vector<int>& vt) {
    List* p = this;
    for (int i = 0; i < vt.size(); i++) {
        p->link = new List(vt[i]);
        p = p->link;
    }
}

void List::append(int val) {
    // HEAD: this
    List* p = this;
    while (p->link != nullptr) {
        p = p->link;
    }
    p->link = new List();
    p->link->data = val;
}

void List::insertElement(int pos, int val) {
    // HEAD: this->link 基于测试用例给出
    List *p = this->link;
    for (int i = 0; i < pos; i++) {
        p = p->link;
    }
    List* inserted_list_ptr = new List();
    inserted_list_ptr->data = val;
    inserted_list_ptr->link = p->link;
    p->link = inserted_list_ptr;
}

void List::deleteElement(int val) {
    // HEAD: this
    int count = 0;
    for (List *p = this; p != nullptr; p = p->link) {
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

void List::travalList() const {
    // const List* p 代表指针所指的地址可以改变，但是指针所指的内容不可以改变，可看作 (const List)* p
    for (const List* p = this->link; p != nullptr; p = p->link) {
        // 不要管 this->data 里面的内容了，沟槽的构造函数没初始化
        cout << "->" << p->data;
    }
    cout << endl;
}

void List::getLength() const {
    cout << "The length of this List is " << length() << '.' << endl;
}

int List::length() const {
    int length = 0;
    for (const List* p = this->link; p != nullptr; p = p->link) {
        length++;
    }
    return length;
}

bool List::isEqual(const List& other) const {
    // const List* p 代表指针所指的地址可以改变，但是指针所指的内容不可以改变，可看作 (const List)* p
    const List* p = this->link;
    const List* q = other.link;
    while (p != nullptr && q != nullptr) {
        if (p->data != q->data) {
            return false;
        }
        p = p->link;
        q = q->link;
    }
    return (this->length() == other.length());
}

void List::connect(const List& other) {
    List* p = this;
    while (p->link != nullptr) {
        p = p->link;
    }
    p->link = other.link;
    cout << "After connect:" << endl;
}


//StudybarCommentBegin
int main(void)
{
	int a;
	vector<int> in1, in2;
	while (cin >> a)
	{
		in1.push_back(a);
		if (getchar() == '\n')
			break;
	}
	while (cin >> a)
	{
		in2.push_back(a);
		if (getchar() == '\n')
			break;
	}
	List listA(in1), listB(in2);
	listA.travalList();
	listB.travalList();
	if (listA.isEqual(listB))
		cout << "They are the same LinkList." << endl;
	else
		cout << "They are different LinkList." << endl;
	listA.connect(listB);
	listA.getLength();
	listA.travalList();
}
//StudybarCommentEnd
