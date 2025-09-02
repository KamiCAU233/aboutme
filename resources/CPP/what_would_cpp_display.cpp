#include <iostream>
#include <string>
using namespace std;

class student_card
{
    private:
        int money; // 学生卡余额
        string holder; // 学生卡持有者
        bool isValid; // 学生卡是否有效；若有效，值为true；
    public:
        student_card()
        {
            money = 0;
            holder = "";
            isValid = true;
        }
        student_card(int initial_money, string initial_holder) // 初始化学生卡
        {
            money = initial_money;
            holder = initial_holder;
            isValid = true;
        }
        int getBalance() // 获取余额
        {
            return money;
        }
        void reportLoss() // 挂失卡片
        {
            isValid = false;
        }
        void reportFound() // 找回卡片
        {
            isValid = true;
        }
        void setHolder(string new_holder)
        {
            holder = new_holder;
        }
        void buy(int price) // 购买
        {
            if (money >= price && isValid == true)
            {
                money = money - price;
            }
        }
        void charge(int amount) // 充值
        {
            if (isValid == true)
            {
                money = money + amount;
            }
        }
};

以下 main 函数能够成功运行的是。

int main()
{
    student_card myCard(100, "Jack");
    cout << myCard.getBalance();
    myCard.buy(20);
    myCard.reportLoss();
    myCard.isValid = true;
    myCard.charge(100);
}

int main()
{
    student_card myCard("Jack");
    myCard.charge(100);
    myCard.buy(50);
}

int main()
{
    student_card myCard;
    myCard.reportLoss();
    myCard.reportFound();
    myCard.setHolder("Alice");
}

int main()
{
    student_card myCard(100, "Alice");
    student_card.getBalance();
    student_card.buy(30);
}
