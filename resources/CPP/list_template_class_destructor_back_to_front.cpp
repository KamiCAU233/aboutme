//StudybarCommentBegin
#include"iostream"
using namespace std;

template <typename T>
class List {
	private:
		T data;
		List *link;
	public:
		List();
		~List();  //这个析构有陷阱，有可能发生递归析构，请注意。
		void append(const T& val);	// 链尾增加一个元素
        void insertElement(int pos, const T& val);	// 在指定位置val后添加一个元素
        void deleteElement(const T& val);	// 删除所有值为val的元素 ， 有析构函数侯，这个delete也可能引起析构函数的调用。
        void travalList()const;	// 从头节点遍历输出链表

};

class Point{
private:
	int x,y;
public:
	Point(int nx=0,int ny=0){
		x=nx;y=ny;
		cout<<"\nPoint("<<x<<","<<y<<") is called!";
	}
	~Point(){
		cout<<"\n~Point("<<x<<","<<y<<") is called!";
	}
	friend ostream &operator<<(ostream& out,const Point &p);
	bool operator==( const Point &p)
	{
		if (x!=p.x || y!=p.y) return false;
		return true;
	}
};
//StudybarCommentEnd

ostream& operator<<(ostream& out, const Point& p) {
    out << '('<< p.x << ',' << p.y << ')';
    return out;
}

#define nullptr NULL

template <class T>
List<T>::List() {
    link = nullptr;
}


template <class T>
void List<T>::append(const T& val) {
    // HEAD: this
    List<T>* p = this;
    while (p->link != nullptr) {
        p = p->link;
    }
    p->link = new List();
    p->link->data = val;
}

template <class T>
void List<T>::insertElement(int pos, const T& val) {
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
void List<T>::deleteElement(const T& val) {
    // HEAD: this
    int count = 0;
    for (List<T>* p = this; p != nullptr; ) {
        if (p->link == nullptr) {
            if (count == 0) cout << endl << "Element "<< val << " not Found.";
            return;
        }
        if (p->link->data == val) {
            List<T>* next = p->link->link;
            p->link->link = nullptr;
            delete p->link;
            p->link = next;
            count++;
        } else p = p->link;
        // 若两个相同的要去除的数挨在一起，会跳过一个，所以必须在if不满足的情况下更新p
    }
    if (count == 0) cout << endl << "Element "<< val << " not Found.";
}

template <class T>
void List<T>::travalList() const {
    // const List* p 代表指针所指的地址可以改变，但是指针所指的内容不可以改变，可看作 (const List)* p
    cout << endl;
    for (const List<T>* p = this->link; p != nullptr; p = p->link) {
        // 不要管 this->data 里面的内容了，沟槽的构造函数没初始化
        cout << "->" << p->data;
    }
}


template <typename T>
List<T>::~List() {
    // Iterate to the end of the list first
    // while (this->link != nullptr) {
    //     List<T>* p = this;
    //     while (p->link != nullptr) {
    //         p = p->link;
    //     }
    //     delete p;
    //     p = nullptr;
    // }
    // delete this;
    delete link;
}

//StudybarCommentBegin
int main(void)
{
	List<Point> list;
	list.append(Point(1,2));
	list.append(Point(2,3));
	list.append(Point(3,4));
	list.append(Point(5,6));
    list.append(Point(1,2));
	list.travalList();

	list.insertElement(1, Point(7,8));
	list.travalList();
	list.insertElement(0, Point(1,2));
	list.travalList();
	list.insertElement(5, Point(1,2));
	list.travalList();
	list.insertElement(2, Point(7,8));

	list.travalList();
	list.deleteElement(Point(1,2));
    list.travalList();

    list.deleteElement(Point(7,8));
	list.travalList();
	list.deleteElement(Point(9,0));
}
//StudybarCommentEnd
