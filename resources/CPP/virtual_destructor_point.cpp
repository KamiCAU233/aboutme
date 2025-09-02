#include <iostream>
using namespace std;

class Point {
    private:
        double x, y;
    public:
        Point(double x = 0, double y = 0) : x(x), y(y) {
            cout << "Point Object Constructed." << endl;
        }
        virtual ~Point() {
            cout << "Point Object Destructed." << endl;
        }
        virtual void Show() {
            cout << "x=" << this->x << ",y=" << this->y << endl;
        }
};

//StudybarCommentBegin
class Circle: public Point {
	private:
		double radius;
	public:
		Circle(double x=0,double y=0,double radius=0):Point(x,y){
			this->radius=radius;
			cout<<"Circle Object Constructed."<<endl;
		}
		~Circle(){
			cout<<"Circle Object Destructed."<<endl;
		}
		void Show(){Point::Show();cout<<"radius="<<radius<<endl;}
};

Point *shape() {
	Circle shape1(1,2,3);
	shape1.Show();

	Point *shape2=new Circle(4,5,6);
	shape2->Show();
	return shape2;
}

int main()
{
	Point *p=shape();
	delete p;
	return 0;
}
//StudybarCommentEnd
