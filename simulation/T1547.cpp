// 2/4+6/4
// 1/2+1/2
// 3/2-1/2
// 1/2-1/2

#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	int t;

	if (b > a) {
		t = b;
		b = a;
		a = t;
	}
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void)
{
	int a, b, c, d, e, f;
	string str;
	bool first = true;

	while (cin >> str) {
		if (first == false)
			cout << '\n';
		else
			first = false;
		a = str[2] - '0';
		b = str[6] - '0';
		c = str[0] - '0';
		d = str[4] - '0';
		e = a * b;
		if (str[3] == '+') {
			b = a * d + b * c;
			if (b % e == 0) {
				cout << b / e;
			} else {
				f = gcd(b, e);
				cout << b / f << '/' <<  e / f;
			}
		} else {
			b = b * c - a * d;
			if (b % e == 0) {
				cout << b / e;
			} else if (b > 0) {
				f = gcd(e, b);
				cout << b / f << '/' <<  e / f;
			} else {
				f = gcd(-1 * b, e);
				cout << b / f << '/' <<  e / f;
			}
		}
	}
	return 0;
}
