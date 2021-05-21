#include <iostream>

using namespace std;

int main(void)
{
	bool f = false;
	int n, a, b, c;

	cin >> n;

	for (a = 0; a <= n; a++) {
		for (b = 0; b + a <= n; b++) {
			for (c = 0; a + b + c <= n; c++) {
				if (a +b + c != n)
					continue;
				if (a * 15 + b * 9 + c == 3 * n) {
					cout << a << ' ' << b << ' ' << c << '\n';
					f = true;
				}
			}
		}
	}
	if (f == false)
		cout << "No Answer.";

	cout << endl;
	return 0;
}
