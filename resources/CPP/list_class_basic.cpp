//StudybarCommentBegin
#include <iostream>
using namespace std;

class List
{
private:
	int data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
	void append(int val);	// 链尾增加一个元素
	void insertElement(int pos, int val);	// 在指定位置后添加一个元素
	void deleteElement(int val);	// 删除元素
	void travalList() const;	// 从头节点遍历输出链表
};
//StudybarCommentEnd

#define nullptr NULL
// 前缀代码里定义的构造器好难用！

List::List() {
    link = nullptr;
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
        // 不要管 this->data 里面的内容了，沟槽的构造函数每没初始化
        cout << "->" << p->data;
    }
    cout << endl;
}



//StudybarCommentBegin
int main(void)
{
	List list;
	list.append(10);
	list.append(8);
	list.append(12);
	list.append(100);
	list.travalList();
	list.insertElement(0, 20);
	list.travalList();
	list.deleteElement(2);
	list.deleteElement(10);
	list.travalList();
}
//StudybarCommentEnd
