#include <iostream>
#include <string>
using namespace std;

// Intel CPU Work with 4.5GHz
// ASUS MainBoard Work with ATX
// Seagate HardDisk Work with 500G

class HardWare {
    public:
        string name;
        double param;
        string type;
        HardWare(string n, double p, string t) {
            name = n;
            param = p;
            type = t;
        }
        virtual void Work() = 0;
};

class CPU : public HardWare {
    public:
        CPU(string n, double p) : HardWare(n, p, "") {}
        void Work() {
            cout << name << " CPU Work with "<< param << "GHz" << endl;
        }
};

class MainBoard : public HardWare {
    public:
        MainBoard(string n, string p) : HardWare(n, 0, p) {}
        void Work() {
            cout << name << " MainBoard Work with "<< type << endl;
        }
};

class HardDisk : public HardWare {
    public:
        HardDisk(string n, double p) : HardWare(n, p, "0") {}
        void Work() {
            cout << name << " HardDisk Work with "<< param << "G" << endl;
        }
};



//StudybarCommentBegin
int main()
{
    HardWare *p1 = new CPU("Intel",4.5); //CPU品牌Intel，主频4.5GHz
    HardWare *p2 = new MainBoard("ASUS","ATX");//主板品牌ASUS，板型ATX
    HardWare *p3 = new HardDisk("Seagate",500);//硬盘品牌Seagate，容量500G
    p1->Work(); //输出CPU的信息
    p2->Work();//输出主板的信息
    p3->Work();//输出硬盘的信息
}
//StudybarCommentEnd
