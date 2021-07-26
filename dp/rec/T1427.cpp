#include <iostream>

using namespace std;

int main(void)
{
	int n;
	long long a, b, c, d;

	while (cin >> n && n) {
		a = 1;
		d = c = b = 0;
		for (int i = 1; i < n; i++) {
			long long t = a + b;
			a += b;
			b = c;
			c = d;
			d = t;
			//cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
		}
		cout << a + b + c + d << '\n';
	}
}