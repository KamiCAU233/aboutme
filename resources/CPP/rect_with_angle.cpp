//StudybarCommentBegin
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
protected:
	double x,y;
public:
	void SetPoint(double x=0,double y=0) {
        this->x=x; this->y=y;
	}
	double GetX() const {return x;}
	double GetY() const {return y;}
	void Move(double xOff, double yOff){
		x+=xOff; y+=yOff;
	}
	double Dist(Point const &p) const {
		double tmpx=x-p.x;
		double tmpy=y-p.y;
		return  ::sqrt(tmpx*tmpx+tmpy*tmpy);
	}
};

class Rectangle: public Point
{
public:
	void SetRect(double x,double y,double w,double h)
		{
            SetPoint(x,y); this->w=w; this->h=h;
		}
	double GetW() const {return w;}
	double GetH() const {return h;}
	double DistOfTwoR(const Rectangle &R) {
		double tmpx=x-R.x;
		double tmpy=y-R.y;
		return  ::sqrt(tmpx*tmpx+tmpy*tmpy);
	}

protected:
	double w,h;
};
//StudybarCommentEnd

class RectWithAngle: public Rectangle {
    private:
        double ang;
    public:
        RectWithAngle(double x, double y, double w, double h, double angle) {
            SetRect(x, y, w, h);
            this->ang = angle;
        }
        bool IsPointInMe(Point p) {
            double x_ori = p.GetX();
            double y_ori = p.GetY();
            double rad = ang * M_PI / 180.0; // 角度转弧度
            double dx = x_ori - GetX();      // 相对x坐标
            double dy = y_ori - GetY();      // 相对y坐标

            // 逆旋转计算（旋转回矩形未旋转时的矩形坐标系，以矩形左上角点为原点）
            double x_rot = dx * cos(rad) + dy * sin(rad);
            double y_rot = dy * cos(rad) - dx * sin(rad);

            // 判断是否在矩形原始边界内（0到w，0到h）
            return (x_rot >= 0) && (x_rot <= GetW()) && (y_rot >= 0) && (y_rot <= GetH());
        }

};





//StudybarCommentBegin
int main()
{
	double angle;
	cin>> angle;
	RectWithAngle  R1(2,3,3,4,angle);
	R1.Move(1,1);
	Point p;
	p.SetPoint(4.5,4);
	cout<< R1.IsPointInMe(p);
	return 0;
}
//StudybarCommentEnd
