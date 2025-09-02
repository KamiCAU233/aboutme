#include <iostream>
using namespace std;

class Animal {
    public:
        unsigned int Age;  // NEW!

        Animal(unsigned int age = 1) : Age(age) {} // NEW!

        virtual void bark() const {
            cout << "Animal::bark()" << endl;
        }

        int TellAge() const { // NEW!
            cout << "The animal's age is " << Age << endl;
            return Age;
        }
};


class Cat: public Animal {
    public:
        void bark() const {
            cout << "miaomiao" << endl;
        }
};

class Dog: public Animal {
    public:
        virtual void bark() const {
            cout << "wangwang" << endl;
        }

};

class Duck: public Animal {
    public:
        void bark() {
            cout << "gaga" << endl;
        }
};

class Bird: public Animal { // NEW!
    public:
        unsigned int WingNum;
        Bird(unsigned int age, unsigned int wingnum = 2) : Animal(age), WingNum(wingnum) {}
        void bark() const { // override
            cout << "jiji" << endl;
        }
        int TellAge() const { // override
            cout << "I am a bird with " << WingNum << " Wings, my age is " << Age << endl;
            return Age;
        }
};

void AnimalBark_Ref(Animal& animal) {
    animal.bark();
}

void AnimalBark_Pointer(Animal* animal) {
    animal->bark();
    animal->TellAge();
}

void AnimalBark_var(Animal animal) {
    animal.bark();
}

//StudybarCommentBegin
int main()
{
    Cat c;
	Dog d;
	Duck du;
	Bird *pbird = new Bird(3); // pbird 指向一只3岁的鸟

    cout<<"This sizeof(Animal):"<<sizeof(Animal)<<endl;
    cout<<"This sizeof(c):"<<sizeof(c)<<endl;
    cout<<"This sizeof(d):"<<sizeof(d)<<endl;
    cout<<"This sizeof(du):"<<sizeof(du)<<endl;
    cout<<"This sizeof(Bird):"<<sizeof(Bird)<<endl;
    cout<<"This sizeof(int *):"<<sizeof(int *)<<endl;

    cout<<"--by Pointer:"<<endl;
	AnimalBark_Pointer( &c);
	AnimalBark_Pointer( &d);
	AnimalBark_Pointer( &du);
	AnimalBark_Pointer( pbird);
	pbird->TellAge();

	return 0;
}
//StudybarCommentEnd
