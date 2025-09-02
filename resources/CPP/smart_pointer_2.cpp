
//StudybarCommentBegin
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
inline void SAFE_DELETE(T * & p) //&不能省略，否则 p=NULL无效。 但#define 那种宏替换可以，因为是字符替换。这也是inline 和#define的区别的重要案例
{  if (p !=NULL )
	{ delete p; p = NULL; }
}
//KRefCount是一个多线程安全的计数器对象，大家仅关注其外部接口（功能），不用关心内部实现。
class KRefCount
{
public:
    KRefCount():m_nCount(0){}

public:
	long AddRef(){ return InterlockedIncrement(&m_nCount); }  //给m_nCount加一，用InterlockedIncrement是多线程安全。
	long Release(){ return InterlockedDecrement(&m_nCount); }  //给m_nCount减一，用InterlockedIncrement是多线程安全。
    void Reset(){ m_nCount = 0; }

private:
    volatile  long m_nCount;   //volatile 告诉编译器， m_nCount 这个变量不允许做寄存器优化。
};

template <typename T>
class SmartPtr
{
private:
    KRefCount* m_pReference;
    T* m_pData;
public:
    SmartPtr(T* pValue);
    ~SmartPtr(void);
    inline T& operator*();
    inline T* operator->();
};
//StudybarCommentEnd


template <typename T>
SmartPtr<T>::SmartPtr(T* pValue) {
    m_pData = pValue;
    m_pReference = new KRefCount();
    m_pReference->AddRef();  // 初始引用计数为 1
}

template <typename T>
SmartPtr<T>::~SmartPtr(void) {
    if (m_pReference && m_pReference->Release() == 0) {
        SAFE_DELETE(m_pData);        // 释放指向的数据对象
        SAFE_DELETE(m_pReference);   // 释放计数器本身
    }
}

template <typename T>
inline T& SmartPtr<T>::operator*() {
    return *m_pData;
}

template <typename T>
inline T* SmartPtr<T>::operator->() {
    return m_pData;
}



//StudybarCommentBegin
class CTest
{
public:
	CTest(int b) : a(b) {cout<<"\n CTest("<<a<<" ) is called";}
	~CTest()  {cout<<"\n ~CTest("<<a<<") is called";}
	void ShowAddOne() {cout<<"\n++a= "<<++a;}
private:
	int a;
};

int main()
{   int x;
    cin >>x;
	SmartPtr<CTest> pSmartPtr1(new CTest(x));
	SmartPtr<CTest> pSmartPtr2=new CTest(20);
	CTest *p=new CTest(30);
	pSmartPtr1->ShowAddOne();
	(*pSmartPtr2).ShowAddOne();
}
//StudybarCommentEnd
