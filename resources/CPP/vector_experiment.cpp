#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define auto vector<Review>::iterator


class Review {
public:
    Review(){}
    bool fillReview();
    void showReview();
private:
    string title;
    int rating;
};

bool Review::fillReview()
{
  //  cout << "Enter book title (quit to quit): ";
    getline(cin,title);
    if (title == "quit")
        return false;

   // cout << "Enter book rating: ";
    cin >> rating;
    if (!cin)
        return false;

    // get rid of rest of input line
    while (cin.get() != '\n')
        continue;
    return true;
}

void Review::showReview()
{
    cout << rating << "\t" <<title << endl;
}



int main()
{
    vector<Review> books;
    Review temp;
    while (temp.fillReview())
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n"
        << "Rating\tBook\n";
        //使用下标，输出所有图书信息
        for (int i = 0; i < num; i++) {
            books[i].showReview();
        }
        cout << "Reprising:\n"
        << "Rating\tBook\n";
        vector<Review>::iterator pr;
        //使用迭代器，输出所有图书信息
        for (pr = books.begin(); pr != books.end(); pr++) {
            pr->showReview();
        }
        vector <Review> oldlist(books);     // copy constructor used
        if (num > 3)
        {
            // 删除第2和第3两条记录

            books.erase(books.begin() + 1);
            books.erase(books.begin() + 1);
            cout << "After erasure:\n";
            //使用迭代器，输出所有图书信息
            for (auto iter = books.begin(); iter != books.end(); iter++) {
                iter->showReview();
            }
            // 将原来的（存储在oldlist中的）第2条记录插入到
            books.insert(books.begin(), oldlist[1]);
            cout << "After insertion:\n";
            //使用迭代器，输出所有图书信息
            for (auto it = books.begin(); it != books.end(); it++) {
                it->showReview();
            }
        }
        //利用oldlist恢复book中的信息。
        swap(oldlist, books);
        cout << "Swapping oldlist with books:\n";
        //使用迭代器，输出所有图书信息
        for (auto iter2 = books.begin(); iter2 != books.end(); iter2++) {
            iter2->showReview();
        }
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    return 0;
}
