// NEW: Copy constructor, getLength() method

#include <iostream>
using namespace std;

class List
{
private:
	int data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
    List(const List& cp);
	void append(int val);	// 链尾增加一个元素
	void insertElement(int pos, int val);	// 在指定位置后添加一个元素
	void deleteElement(int val);	// 删除元素
	void travalList() const;	// 从头节点遍历输出链表
    void getLength() const;
};

#define nullptr NULL
List::List() {
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
    int length = 0;
    for (const List* p = this->link; p != nullptr; p = p->link) {
        length++;
    }
    cout << "The length of this List is " << length << '.' << endl;
}


//StudybarCommentBegin
int main(void)
{
	int n;
	List  listA;

	cin >> n;
	while (n != -1)
	{
		listA.append(n);
		cin >> n;
	}

	listA.travalList();
	List listB(listA);
        listA.append(250);
	listB.getLength();
	listB.travalList();
}
//StudybarCommentEnd
