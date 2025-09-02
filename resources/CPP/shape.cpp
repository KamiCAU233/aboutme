// 注意这道题里 << 是怎么实现虚函数的！

#include <iostream>
#define M_PI 3.14159
using namespace std;

class Shape {
public:
    double center_x, center_y;
    Shape(double x = 0, double y = 0) : center_x(x), center_y(y) {}
    virtual ~Shape() {}; // 虚析构函数能让 Shape 变为多态类型，不然没法进行 dynamic_cast
    virtual void displayInfo() const {
        cout << "Shape at (" << center_x << ", " << center_y << ")";
    }
};

class TwoDimensionalShape : public Shape {
public:
    TwoDimensionalShape(double x = 0, double y = 0) : Shape(x, y) {}
    virtual double getArea() = 0;
};

class ThreeDimensionalShape : public Shape {
public:
    ThreeDimensionalShape(double x = 0, double y = 0) : Shape(x, y) {}
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};

class Circle : public TwoDimensionalShape {
public:
    double radius;
    Circle(double r, double x = 0, double y = 0) : TwoDimensionalShape(x, y), radius(r) {}
    double getArea() {
        return M_PI * radius * radius;
    }
    void displayInfo() const {
        cout << "Circle with radius " << radius << "; center at ("
             << center_x << ", " << center_y << ")";
    }

};

class Square : public TwoDimensionalShape {
public:
    double side_length;
    Square(double s, double x = 0, double y = 0) : TwoDimensionalShape(x, y), side_length(s) {}
    double getArea() {
        return side_length * side_length;
    }
    void displayInfo() const {
        cout << "Square with side length " << side_length << "; center at ("
             << center_x << ", " << center_y << ")";
    }
};

class Cube : public ThreeDimensionalShape {
public:
    double side_length;
    Cube(double s, double x = 0, double y = 0) : ThreeDimensionalShape(x, y), side_length(s) {}
    double getArea() {
        return 6 * side_length * side_length;
    }
    double getVolume() {
        return side_length * side_length * side_length;
    }
    void displayInfo() const {
        cout << "Cube with side length " << side_length << "; center at ("
             << center_x << ", " << center_y << ")";
    }
};

class Sphere : public ThreeDimensionalShape {
public:
    double radius;
    Sphere(double r, double x = 0, double y = 0) : ThreeDimensionalShape(x, y), radius(r) {}
    double getArea() {
        return 4 * M_PI * radius * radius;
    }
    double getVolume() {
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }
    void displayInfo() const override {
        cout << "Sphere with radius " << radius << "; center at ("
             << center_x << ", " << center_y << ")";
    }
};

ostream& operator<<(ostream& os, const Shape& shape) {
    shape.displayInfo();
    return os;
}

//StudybarCommentBegin
int main()
{
   Shape * shapes[4];

    // initialize vector with Shapes
    shapes[ 0 ] = new Circle( 3.5, 6, 9 );
    shapes[ 1 ] = new Square( 12, 2, 2 );
    shapes[ 2 ] = new Sphere( 5, 1.5, 4.5 );
    shapes[ 3 ] = new Cube( 2.2 );

    // output Shape objects and display area and volume as appropriate
    for ( int i = 0; i < 4; i++ )
    {
        cout << *( shapes[ i ] ) << endl;

        // downcast pointer
        TwoDimensionalShape *twoDimensionalShapePtr =
            dynamic_cast < TwoDimensionalShape * > ( shapes[ i ] );
        // dynamic_cast<目标类型>(表达式);

        // if Shape is a TwoDimensionalShape, display its area
        if ( twoDimensionalShapePtr != 0 )
            cout << "Area: " << twoDimensionalShapePtr->getArea() << endl;

        // downcast pointer
        ThreeDimensionalShape *threeDimensionalShapePtr =
        dynamic_cast < ThreeDimensionalShape * > ( shapes[ i ] );

        // if Shape is a ThreeDimensionalShape, display its area and volume
        if ( threeDimensionalShapePtr != 0 )
            cout << "Area: " << threeDimensionalShapePtr->getArea()
            << "\nVolume: " << threeDimensionalShapePtr->getVolume()
            << endl;

        cout << endl;
    } // end for
    return 0;
} // end main

//StudybarCommentEnd
