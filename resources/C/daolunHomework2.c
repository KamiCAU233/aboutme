#include <stdio.h>

int main() {
    int x = 0xFFFF0006;
    short y = 0xDFFC;
    unsigned long long tempz = 0xFFFFFFFFFFFFFFFA;
    unsigned z = tempz;
    char c = 0x2A;
    union {
        unsigned int ui;
        float f;
    } u;
    u.ui = 0xC4480000;
    float a = u.f;
    union {
        unsigned long long ull;
        double d;
    } v;
    v.ull = 0xC024800000000000;
    double b = v.d;

    printf("int x: %d\n", x);
    printf("short y: %d\n", y);
    printf("unsigned z: %u\n", z);
    printf("char c: %c\n", c);
    printf("float a: %f\n", a);
    printf("double b: %lf\n", b);

    return 0;
}
