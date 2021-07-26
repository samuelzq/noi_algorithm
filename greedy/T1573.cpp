#include <iostream>

using namespace std;

int main(void)
{
	int n, x, y, w, h;
	char c;

	cin >> n;

	x = y = w = h = 0;
	while (n--) {
		int a, b;
		cin >> c >> a >> b;
		if (c == '+') {
			if (a > b) {
				if (x < a)
					x = a;
				if (y < b)
					y = b;
			} else {
				if (x < b)
					x = b;
				if (y < a)
					y = a;
			}
		} else if (c == '?') {
			if (a > b) {
				if (a >= x && b >= y)
					cout << "YES\n";
				else
					cout << "NO\n";
			} else {
				if (a >= y && b >= x)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}
