#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Rectangle {
    private:
        double coord[4][2];
        int parallel_index = 0;
        int vertical_index = 0;
        int diagonal_index = 0;
    public:
        Rectangle(double coords[4][2]) {
            setCoords(coords);
        }
        bool setCoords(double coords[4][2]) {
            // Take coords[0][0] for example
            for (int i = 0; i < 4; i++) {
                if (coords[i][0] > 20.0 || coords[i][0] < 0) {
                    cout << "第" << i + 1 << "个点的横坐标值无效,被置为0"<< endl;
                    coords[i][0] = 0;
                }
                if (coords[i][1] > 20.0 || coords[i][1] < 0) {
                    cout << "第" << i + 1 << "个点的纵坐标值无效,被置为0" << endl;
                    coords[i][1] = 0;
                }
            }
            for (int i = 1; i < 4; i++) {
                if (coords[i][0] == coords[0][0] && parallel_index != i) {
                    vertical_index = i;
                }
                if (coords[i][1] == coords[0][1] && vertical_index != i) {
                    parallel_index = i;
                }
            }
            for (int i = 1; i < 4; i++) {
                if (coords[i][0] == coords[parallel_index][0] &&
                    coords[i][1] == coords[vertical_index][1]) {
                        diagonal_index = i;
                }
            }
            if (parallel_index && vertical_index && diagonal_index) {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        coord[i][j] = coords[i][j];
                    }
                }
            } else {
                cout << "不能构成长方形！" << endl;
                exit(1);
                return false;
            }
            return true;
        }

        double length() {

            double possible_l1 = coord[0][0] - coord[parallel_index][0];
            double possible_l2 = coord[0][1] - coord[vertical_index][1];
            return max(abs(possible_l1), abs(possible_l2));
        }

        double width() {
            double possible_l1 = coord[0][0] - coord[parallel_index][0];
            double possible_l2 = coord[0][1] - coord[vertical_index][1];
            return min(abs(possible_l1), abs(possible_l2));
        }

        double perimeter() {
            return 2 * (width() + length());
        }

        double area() {
            return width() * length();
        }

        bool square() {
            return (width() == length());
        }
};

//StudybarCommentBegin
int main()
{
    double rect[4][2];
    int i;

    for(i=0;i<4;i++)
    {
//        cout<<"请输入第"<<i+1<<"个点的横纵坐标（大于0且小于20）,以空格分隔：";
        cin>>rect[i][0]>>rect[i][1];
    }

    Rectangle myRect(rect);
    cout<<"长度为："<<myRect.length()<<endl;
    cout<<"宽度为："<<myRect.width()<<endl;
    cout<<"周长为："<<myRect.perimeter()<<endl;
    cout<<"面积为："<<myRect.area()<<endl;

    if(myRect.square())
        cout<<"此长方形是一个正方形"<<endl;
    else
        cout<<"此长方形不是一个正方形"<<endl;

    return 0;
}
//StudybarCommentEnd
