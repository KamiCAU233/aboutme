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
    strcpy(sPtr, t);
    length = strlen(t);
    return *this;
}

String& String::operator=(const String& t) {
    strcpy(sPtr, t.sPtr);
    length = t.length;
    return *this;
}

String& String::operator+=(const String& t) {
    strcat(sPtr, t.sPtr);
    length = length + t.length;
    return *this;
}

//StudybarCommentBegin
int main()
{
	char msg[1000];
	cin>>msg;
	String a("This"), b(a), c(msg);
	cout<<a<<"\na=c is "<<(a=c)<<"\nb+=c is "<<(b+=c)<<endl;
	cout<<(b=msg)<<endl;
}
//StudybarCommentEnd
