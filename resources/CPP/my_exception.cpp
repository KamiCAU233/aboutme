//StudybarCommentBegin
#include <iostream>
using namespace std;
//StudybarCommentEnd

class MyException {
public:
    int no;
    MyException(int n) {
        no = n;
    }
    void Reason() {
        if (no == 1) cout << "Exception:1" << endl;
        else if (no == 2) cout << "Exception:2" << endl;
        else if (no == 3) cout << "Exception:3" << endl;
    }

    void func(int x) {
        MyException* t = new MyException(x);
        throw t;
    }
};


void fn1(int excpNo) {
    MyException e(excpNo);
    e.func(excpNo);
}

//StudybarCommentBegin
int main(){
    int excpNo;
	cin >> excpNo;
	try{
		if (excpNo > 3 || excpNo < 1)
			throw 1;
		fn1(excpNo);
	}
	catch (MyException* e){
		e->Reason();
	}
	catch (...){
		cout << "Other error." << endl;
	}
        return 0;
}
//StudybarCommentEnd
