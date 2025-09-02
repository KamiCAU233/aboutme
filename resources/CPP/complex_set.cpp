#include <iostream>
#include <cmath>
using namespace std;

class Cmycomplex {
    private:
        int real, imag;
    public:
        // Constructor:
        Cmycomplex(int r = 0, int i = 0) : real(r), imag(i) { }

        // Operator Override
        Cmycomplex operator+(const Cmycomplex other) {
            return Cmycomplex(real + other.real, imag + other.imag);
        }
        Cmycomplex operator-(const Cmycomplex other) {
            return Cmycomplex(real - other.real, imag - other.imag);
        }
        Cmycomplex operator*(const Cmycomplex other) {
            int new_real = real * other.real - imag * other.imag;
            int new_imag = real * other.imag + imag * other.real;
            return Cmycomplex(new_real, new_imag);
        }
        Cmycomplex operator/(const Cmycomplex other) {
            int new_real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
            int new_imag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
            return Cmycomplex(new_real, new_imag);
        }
        bool operator>(const Cmycomplex other) {
            int self_modulus = real * real + imag * imag;
            int other_modulus = other.real * other.real + other.imag * other.imag;
            return (self_modulus > other_modulus);
        }
        bool operator==(const Cmycomplex x) {
            return (x.real == real) && (x.imag == imag);
        }
        // IO Override
        friend istream& operator>>(istream& is, Cmycomplex& self) {
            is >> self.real >> self.imag;
            return is;
        }
        friend ostream& operator<<(ostream& os, const Cmycomplex& self) {
            os << '(' << self.real << ((self.imag >= 0) ? '+' : '-') << abs(self.imag) << "i)";
            return os;
        }

        void Set(int r, int i) {
            real = r;
            imag = i;
        }


};



class Cassemblage {
    private:
        int count = 0;
        Cmycomplex arr[100] = {0};
    public:
        // Constructor
        Cassemblage() {
            count = 0;
        }
        // Operator Overrides
        Cassemblage operator+(Cassemblage x) {
            Cassemblage t;
            t.Set(arr, count);
            for (int i = 0; i < x.count; i++) {
                if (!includes(x.arr[i])) {
                    t.arr[t.count] = x.arr[i];
                    t.count++;
                }
            }
            return t;
        }

        Cassemblage operator&(Cassemblage x) {
            Cassemblage result;
            for (int i = 0; i < x.count; i++) {
                if (includes(x.arr[i]) && !result.includes(x.arr[i])) {
                    result.arr[result.count] = x.arr[i];
                    result.count++;
                }
            }
            return result;
        }

        Cassemblage operator-(Cassemblage x) {
            Cassemblage result;
            result.Set(arr, count);
            for (int i = 0; i < x.count; i++) {
                if (includes(x.arr[i])) {
                    // Eliminate x.arr[i] out of result.arr[]
                    result.eliminate(x.arr[i]);
                }
            }
            return result;
        }

        void Set(Cmycomplex ori[], int ele) {
            count = ele;
            for (int i = 0; i < ele; i++) {
                arr[i] = ori[i];
            }
        }
        void Show() {
            if (count == 0) {
                cout << "empty" << endl;
                return;
            }
            for (int i = 0; i < count; i++) {
                for (int j = i; j < count; j++) {
                    if (arr[i] > arr[j]) {
                        Cmycomplex temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            for (int i = 0; i < count; i++) {
                cout << arr[i] << " ";
            }
        }

        bool includes(Cmycomplex x) {
            for (int i = 0; i < count; i++) {
                if (arr[i] == x) {
                    return true;
                }
            }
            return false;
        }

        void eliminate(Cmycomplex x) {
            if (!includes(x)) {
                return;
            } else {
                for (int i = 0; i < count; i++) {
                    if (arr[i] == x) {
                        for (int p = i; p < count - 1; p++) {
                            arr[p] = arr[p + 1];
                        }
                        count--;
                    }
                }
                eliminate(x);
            }
        }
};

//StudybarCommentBegin
int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	Cmycomplex a1[1000], a2[1000];
	int i, n1, n2;
	double a11[1000], a12[1000], a21[1000], a22[1000];

	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a11[i] >> a12[i];
		a1[i].Set(a11[i], a12[i]);
	}
       z1.Set(a1, n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a21[i] >> a22[i];
		a2[i].Set(a21[i], a22[i]);
	}
	z2.Set(a2, n2);

	x1=z1+z2;
	x1.Show();
	cout << endl;

	x2=z1&z2;
	x2.Show();
	cout << endl;

	x3=z1-z2;
	x3.Show();


	return 0;
}

//StudybarCommentEnd
