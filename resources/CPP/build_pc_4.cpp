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



class Client
{
    public:
        Client(Builder* pBuilder) { //客户指定某个厂商
            m_pBuilder = pBuilder;
        }
        PC* CreatePC() {   //生产一台电脑
            m_pBuilder->ProducePC();
            m_pBuilder->ProduceCPU(); // 厂家生产CPU并装入机箱
            m_pBuilder->ProduceHardDisk();// 厂家生产硬盘并装入机箱
            m_pBuilder->ProduceMainBoard();// 厂家生产主板并装入机箱
            return m_pBuilder->GetPC();
        }
    private:
        Builder* m_pBuilder;
};


//StudybarCommentBegin
int main()
{

    cout<<"\nBuilding Dell Computer\n";

    Builder* pDell = new DellBuilder(); //创建Dell厂商
    Client* pClient1 = new Client(pDell); //创建一个用户，并使用dell厂商
    PC* pPC1 = pClient1->CreatePC();  // 生产一台电脑
    pPC1->Work();  //显示电脑的工作状态

    cout<<"\nBuilding IBM Computer\n";

    IBMBuilder* pIBM = new IBMBuilder();
    Client* pClient2 = new Client(pIBM);
    PC* pPC2 = pClient2->CreatePC();
    pPC2->Work();

    return 0;
}
//StudybarCommentEnd
