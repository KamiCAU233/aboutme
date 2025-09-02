//StudybarCommentBegin
#include <iostream>
#include <cstring> // strcpy and strcat prototypes
using namespace std;


class String
{
public:
    String( const char * = "" ); // 输出"Conversion (and default) constructor: "
    String( const String & ); //输出 "Copy constructor: "
    ~String(); // 输出"Destructor: "

    bool operator==( const String & ) const; // test s1 == s2
    operator  char*(){ return this->sPtr; }; //转换函数
    friend ostream &operator<<( ostream &out, const String &t );

    String& operator=( const char *t);
    String& operator=( const String &t );
    String& operator+=( const String &t );

    char& operator[]( int i);
    bool operator<=( const String &right ) const;
    bool operator!() const;  //如果是空串返回 true
    friend String operator+( const String &a, const String &b );

private:
    int length; // string length (not counting null terminator)
    char *sPtr; // pointer to start of pointer-based string
};
//StudybarCommentEnd


String::String(const char* s) {
    cout << "Conversion (and default) constructor: " << s << endl;
    length = strlen(s);
    sPtr = new char[length + 1];
    strcpy(sPtr, s);
}

String::String(const String& str) {
    cout << "Copy constructor: " << str << endl;
    length = str.length;
    sPtr = new char[length + 1];
    strcpy(sPtr, str.sPtr);
}

String::~String() {
    cout << "Destructor: " << sPtr << endl;
    delete[] sPtr;
}

ostream& operator<<(ostream &out, const String &t) {
    out << t.sPtr;
    return out;
}

bool String::operator==(const String& str) const {
    return (strcmp(str.sPtr, sPtr) == 0);
}

String& String::operator=(const char* t) {
    delete[] sPtr;
    length = strlen(t);
    sPtr = new char[length + 1];
    strcpy(sPtr, t);
    return *this;
}

String& String::operator=(const String& t) {
    delete[] sPtr;
    length = t.length;
    sPtr = new char[length + 1];
    strcpy(sPtr, t.sPtr);
    return *this;
}

String& String::operator+=(const String& t) {
    strcat(sPtr, t.sPtr);
    length = length + t.length;
    return *this;
}

char& String::operator[](int index) {
    if (index >= length) {
        throw -1;
    }
    return sPtr[index];
}

bool String::operator<=(const String& right) const {
    return (strcmp(sPtr, right.sPtr) <= 0);
}

bool String::operator!() const {
    return length == strlen("");
}

String operator+(const String &a, const String &b) {
    String p = a;
    p += b;
    return p;
}


//StudybarCommentBegin
int main()
{
	char msg[1000];
	cin >> msg;
	try {
		String a("This"), b(a), c(msg),d;
		cout<< (a+"add"+b )<<endl;
		cout<<(b=msg)<<endl;
		cout<<(a<=c)<<endl;
		cout<<b[20]<<endl;
		if (!d)
				d = "I love String";
		else
				cout << d;
	}
	catch (int x)
	{
		if (-1==x)
		{
			cout<<"Subindex is out of Range!";
		}
	}
	return 0;
}
//StudybarCommentEnd
