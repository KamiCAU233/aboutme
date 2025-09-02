#include <iostream>
using namespace std;

class Point {
    double x, y;
    public:
        void SetPoint(double x = 0, double y = 0) {
            this->x = x;
            this->y = y;
        }
        double GetX() const {
            return x;
        }
        double GetY() const {
            return y;
        }
        void Move(double xOff, double yOff) {
            x += xOff;
            y += yOff;
        }
};

class Circle : public Point {
    double radius;
    public:
        void SetRadius(double r) {
            radius = r;
        }
        double getArea() {
            return 3.1415926 * radius * radius;
        }
};

class Rectangle : public Point {
    public:
        void SetRect(double x, double y, double w, double h) {
            SetPoint(x, y);
            this->w = w;
            this->h = h;
        }
        double GetW() const {
            return w;
        }
        double GetH() const {
            return h;
        }
    private:
        double w, h;
};


//StudybarCommentBegin
int main()
{
	Rectangle rect;
	rect.SetRect(0,0,1,1);
	rect.Move(3,2);
	cout<<"sizeof(Point):"<<sizeof(Point)<<" and sizeof(rect):"
	    <<sizeof(rect)<<", (x,y,w,h) is ("<<rect.GetX()<<","
	    <<rect.GetY()<<","<<rect.GetW()<<","<<rect.GetH()<<")";
	return 0;

}
//StudybarCommentEnd
