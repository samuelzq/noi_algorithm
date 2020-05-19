#include "hp_template.h"

int main()
{
using namespace std;
	string s1, s2;
	while (cin >> s1 >> s2) {
		class Big a(s1), b(s2), t;
		t = a + b;
		t.print();
		cout << endl;
		t = a - b;
		t.print();
		cout << endl;
		t = a * b;
		t.print();
		cout << endl;
		t = a / b;
		t.print();
		cout << endl;
		t = a ^ b;
		t.print();
		cout << endl;
		t = a ^ 3;
		t.print();
		cout << endl;
		t = a % b;
		t.print();
		cout << endl;
		t = a % 3;
		t.print();
		cout << endl;
	}
	
	return 0;
}
