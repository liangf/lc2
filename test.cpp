#include <iostream>
using namespace std;

class Person {
public:
	int age;
};

int main() 
{
	int x = 2;
	int &y = x;

	cout << x << " " << y << endl;
	x = 3;
	y = 4;
	cout << x << " " << y << endl;

	Person p1;
	Person &p2 = p1;
	p1.age = 123;

	cout << p1.age << " " << p2.age << endl;
}
