#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Cassemblage {
    private:
        int count = 0;
        T arr[100] = {0};
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

        void Set(T ori[], int ele) {
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
                        T temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            for (int i = 0; i < count; i++) {
                cout << arr[i] << " ";
            }
        }

        bool includes(T x) {
            for (int i = 0; i < count; i++) {
                if (arr[i] == x) {
                    return true;
                }
            }
            return false;
        }

        void eliminate(T x) {
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

int get_gcd(int a, int b)
{
    for (int i = a; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return -1;
}

class Fraction {
    public:
        Fraction(int up = 1, int low = 1) : upper(up), lower(low) {}

        Fraction operator-(const Fraction a) const {
            int new_upper = upper * a.lower - lower * a.upper;
            int new_lower = a.lower * lower;
            return Fraction(new_upper, new_lower);
        }
        friend bool operator==(Fraction a, Fraction b) {
            return a.upper * b.lower == a.lower * b.upper;
        }
        friend bool operator!=(Fraction a, Fraction b);
        friend bool operator>(Fraction a, Fraction b);
        friend ostream& operator<<(ostream& os, const Fraction& self);
        friend istream& operator>>(istream& is, Fraction& self);
    private:
        int upper, lower;
};

bool operator!=(Fraction a, Fraction b) {
    return (b.upper * a.lower - b.lower * a.upper != 0);
}
bool operator>(Fraction a, Fraction b) {
    return (a.upper / a.lower) > (b.upper / b.lower);
}
ostream& operator<<(ostream& os, const Fraction& self) {
    int sign = (self.upper * self.lower) > 0 ? 1 : (-1);
    int gcd = get_gcd(abs(self.upper), abs(self.lower));
    int new_upper = self.upper / gcd;
    int new_lower = self.lower / gcd;
    os << sign * abs(new_upper) << '/' << abs(new_lower);
    return os;
}
istream& operator>>(istream& is, Fraction& self) {
    int up, low;
    is >> up >> low;
    self.upper = up;
    self.lower = low;
    return is;
}

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


// int main(int argc, char* argv[])
// {
// 	Cassemblage <Fraction> z1, z2, x1;
// 	Fraction a1[1000], a2[1000];
// 	int i, n1, n2;
// 	char op;
// 		cin >> n1;
// 	for(i=0; i<n1; i++)
// 	{
// 		cin>>a1[i];
// 	}
//        z1.Set(a1, n1);

// 	cin >> n2;
// 	for(i=0; i<n2; i++)
// 	{
// 		cin>>a2[i];
// 	}
// 	z2.Set(a2, n2);
//     cin>>op;
// 	switch(op)
//     {
//         case '+' :
//           x1=z1+z2;
//           x1.Show();
//             break;
//         case '-' :
//             x1=z1-z2;
//             x1.Show();
//             break;

//         case '&':
//             x1=z1&z2;
//             x1.Show();
//             break;
//         default:
//             cout<<"Invalid operator!";
//     }

// 	return 0;
// }
