//StudybarCommentBegin
#include <iostream>
#include <cstring>
using namespace std;
//StudybarCommentEnd

class MyString {
private:
    char* str;
    long size;
public:
    MyString(long n) : size(n) {
        if (n > 10000) {
            cout << "Constructor abnormal." << endl;
        } else {
        cout << "Constructing..." << endl;
        try {
            str = new char[size + 1];
            if (!str) {
                throw 'e';
            }
            str[0] = '\0';
            cout << "Construction finished." << endl;
        } catch (const bad_alloc&) {
            throw "Constructor abnormal.";
        }
    } }

    ~MyString() {
        if (str) {
            delete[] str;
            cout << "Destruction finished." << endl;
        }
    }

    void ShowStr() {
        if (!str) throw 'e';
        cout << str << endl;
    }
};

//StudybarCommentBegin
int main(){
	long a;
	cin >> a;
	try{
		if (a > 0){
			MyString str1(a);   //生成容纳a个字符的字符串
			str1.ShowStr();
		}
		else
                 {
                     char *c="Array length error.";
                     throw c;
                   //  throw "Array length error.";   work in VC not GCC

                 }
	}
	catch (char* c){
		cout << c << endl;
	}
	catch (...){
		cout << "Other failures." << endl;
	}
	cout << "Main finished." << endl;
	return 0;
}
//StudybarCommentEnd
