#include <iostream>
#include <cassert>
using namespace std;

class Point {
public:
    Point() : x(0), y(0) {
        cout<<"Default Constructor called."<<endl;
    }
    Point(int x, int y) : x(x), y(y) {
        cout<< "Constructor called."<<endl;
    }
    ~Point() { cout<<"Destructor called."<<endl; }
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }
private:
    int x, y;
};


class ArrayOfPoints { //动态数组类
public:
ArrayOfPoints(int size) : size(size) {
    points = new Point[size];
}
ArrayOfPoints(ArrayOfPoints& other) {
    size = other.size;
    points = new Point[size];
    for (int i = 0; i < size; i++) {
        points[i] = other.points[i];
    }
}
~ArrayOfPoints() {
    cout << "Deleting..." << endl;
    delete[] points;
}
Point& element(int index) {
    return points[index];
}
private:
    Point *points; //指向动态数组首地址
    int size; //数组大小
};

int main() {
    int count;
    cout << "Please enter the number of points: " << endl;
    cin >> count;
    ArrayOfPoints pointsArray1(count); //创建对象数组
    pointsArray1.element(0).move(5,10);
    pointsArray1.element(1).move(15,20);
    ArrayOfPoints pointsArray2(pointsArray1); //创建副本
    cout << "Copy of pointsArray1:" << endl;
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "
         << pointsArray2.element(0).getY() << endl;
    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "
         << pointsArray2.element(1).getY() << endl;
    pointsArray1.element(0).move(25, 30);
    pointsArray1.element(1).move(35, 40);
    cout <<"After the moving of pointsArray1:"<<endl;
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "
         << pointsArray2.element(0).getY() << endl;
    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "
         << pointsArray2.element(1).getY() << endl;
    return 0;
}
