// 参考教程视频中的代码实现

#include <iostream>
#include <queue>
#include <random>
#include <ctime>
using namespace std;

const int MIN_TIME = 500;
const int MAX_TIME = 2000;

class Cell;
priority_queue<Cell> cellQueue;

class Cell {
    private:
    int id;
    int time;
    public:
        static int count;
        Cell(int birth) : id(count++) {
            time = birth + (rand() % (MAX_TIME - MIN_TIME) + MIN_TIME);
        }
        int getID() const {return id;}
        int getTime() const {return time;}
        bool operator<(const Cell& s) const {
            return time > s.time;
        }
        void split() const {
            Cell child1(time), child2(time);
            cellQueue.push(child1);
            cellQueue.push(child2);
        }
};

int Cell::count = 0;

int main(void) {
    srand(time(0));
    int t;
    cin >> t;
    int result = 0;
    for (int i = 0; i < 3000; i++) {
        cellQueue.push(Cell(0));
        while (cellQueue.top().getTime() <= t) {
            cellQueue.top().split();
            cellQueue.pop();
        }
        result += Cell::count;
        Cell::count = 0;
    }
    cout << result / 3000 / 2;
}

