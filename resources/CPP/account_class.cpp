#include <iostream>
using namespace std;

class Account {
    private:
        double balance;
    public:
        Account(double b) {
            if (b < 0) {
                cout << endl <<  "Error:Initial balance cannot be negative." << endl;
                b = 0;
            }
            balance = b;
        }
        void credit(double depositAmount) {
            balance += depositAmount;
        }
        void debit(double withdrawalAmount) {
            if (withdrawalAmount > balance) {
                cout << endl << "Debit amount exceeded account balance." << endl;
            } else {
                balance -= withdrawalAmount;
            }
        }
        double getBalance() {
            return balance;
        }

};
//StudybarCommentBegin
int main()
{
    Account account1(50.0);

    double withdrawalAmount;
//    cout<<"\nEnter withdrawal amount for account1:";
    cin>>withdrawalAmount;
    cout<<"\nattempting to subtract "<<withdrawalAmount<<" from account1 balance\n";

    account1.debit(withdrawalAmount);
    cout<<"account1 balance:$"<<account1.getBalance()<<endl;

    Account account2(-2);
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;
    account2.credit(156.4);
    cout<<"\nattempting to add "<<156.4<<" to account2\n";
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;

    return 0;
}
//StudybarCommentEnd
