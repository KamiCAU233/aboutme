#include <vector>
#include <iostream>
#include <string>
using namespace std;

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

class PC {
    public:
        vector<HardWare*> parts;
        PC() {};
        void AddToPC(HardWare* hwp) {
            parts.push_back(hwp);
        }
        void Work() {
            for (int i = 0; i < parts.size(); i++) {
                parts[i]->Work();
            }
            cout << "PC Work" << endl;
        }
};

//StudybarCommentBegin
int main()
{
    PC *p = new PC(); //创建机箱
    HardWare *p1 = new CPU("Intel",4.5); //CPU品牌Intel，主频4.5GHz
    HardWare *p2 = new CPU("AMD",3.8); //CPU品牌AMD，主频3.8GHz
    HardWare *p3 = new MainBoard("ASUS","ATX");//主板品牌ASUS，板型ATX
    HardWare *p4 = new HardDisk("Seagate",500);//硬盘品牌Seagate，容量500G
    HardWare *p5 = new HardDisk("Sumsang",1000);//硬盘品牌Sumsang，容量1000G

    //把5个硬件依次装入机箱
    p->AddToPC(p1);
    p->AddToPC(p2);
    p->AddToPC(p3);
    p->AddToPC(p4);
    p->AddToPC(p5);

    p->Work();  //输出各个部件的状态

}

//StudybarCommentEnd
