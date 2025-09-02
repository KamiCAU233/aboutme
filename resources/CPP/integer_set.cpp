#include <iostream>
using namespace std;

class Cassemblage {
    private:
        int count = 0;
        int arr[100] = {0};
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

        void Set(int ori[], int ele) {
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
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            for (int i = 0; i < count; i++) {
                cout << arr[i] << " ";
            }
        }

        bool includes(int x) {
            for (int i = 0; i < count; i++) {
                if (arr[i] == x) {
                    return true;
                }
            }
            return false;
        }

        void eliminate(int x) {
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
	int i, n1, n2, a1[1000], a2[1000];

	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a1[i];
	}
                   z1.Set(a1, n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a2[i];
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
