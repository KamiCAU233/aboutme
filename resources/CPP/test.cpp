class Test

{

private:

int a;

 int b;

const int c;

public:

Test(){a=0;c=0;}                 //(1)

int f(int a) const {this ->a=a;}                 //(2)

void h(int b) {Test::b=b;}                        //(3)

};
