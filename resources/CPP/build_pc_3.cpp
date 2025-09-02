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

class Builder
{
public:
    virtual void ProduceCPU() = 0;
    virtual void ProduceHardDisk() = 0;
    virtual void ProduceMainBoard() = 0;
    virtual void ProducePC()=0;

    virtual PC* GetPC()=0;
};

class DellBuilder:public Builder
{
public:
    virtual void ProduceCPU() {//根据输入创建一个CPU对象，然后加入到机箱中。下同
        string n;
        double p;
        cin >> n >> p;
        HardWare* cpu = new CPU(n, p);
        GetPC()->AddToPC(cpu);
    }
    virtual void ProduceHardDisk() {
        string n;
        double p;
        cin >> n >> p;
        HardWare* hd = new HardDisk(n, p);
        GetPC()->AddToPC(hd);
    }
    virtual void ProduceMainBoard() {
        string n;
        string t;
        cin >> n >> t;
        HardWare* mb = new MainBoard(n, t);
        GetPC()->AddToPC(mb);
    }
    virtual void ProducePC() {
        m_PC = new PC();
    }

    PC* GetPC() {
        return m_PC;
    }; //返回一个机箱对象
private:
    PC* m_PC; //生产的机箱
};

class IBMBuilder:public Builder
{
public:
    virtual void ProduceCPU() {//根据输入创建一个CPU对象，然后加入到机箱中。下同
        string n;
        double p;
        cin >> n >> p;
        HardWare* cpu = new CPU(n, p);
        GetPC()->AddToPC(cpu);
    }
    virtual void ProduceHardDisk() {
        string n;
        double p;
        cin >> n >> p;
        HardWare* hd = new HardDisk(n, p);
        GetPC()->AddToPC(hd);
    }
    virtual void ProduceMainBoard() {
        string n;
        string t;
        cin >> n >> t;
        HardWare* mb = new MainBoard(n, t);
        GetPC()->AddToPC(mb);
    }
    virtual void ProducePC() {
        m_PC = new PC();
    }

    PC* GetPC() {
        return m_PC;
    }; //返回一个机箱对象
private:
    PC* m_PC; //生产的机箱
};



//StudybarCommentBegin
int main()
{
    cout<<"\nBuilding Dell Computer\n";

    Builder* pDell = new DellBuilder(); //创建一个Dell厂家
    pDell->ProducePC();  //Dell厂家生产机箱
    pDell->ProduceCPU(); //Dell厂家生产CPU并装入机箱
    pDell->ProduceHardDisk();//Dell厂家生产硬盘并装入机箱
    pDell->ProduceMainBoard();//Dell厂家生产主板并装入机箱
    pDell->GetPC()->Work();  //GetPC返回Dell厂商生产的机器，并把该机器工作状态输出。

    cout<<"\nBuilding IBM Computer\n";

    IBMBuilder* pIBM = new IBMBuilder();
    pIBM->ProducePC();
    pIBM->ProduceCPU();
    pIBM->ProduceHardDisk();
    pIBM->ProduceMainBoard();
    pIBM->GetPC()->Work();


}

//StudybarCommentEnd
