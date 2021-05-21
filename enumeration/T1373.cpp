#include <iostream>

using namespace std;
bool f = false;

int main(void)
{
	int n, a, b, c;

	cin >> n;

	for (a = 0; a <= n; a++) {
		for (b = 0; b <= n; b++) {
			c = 6 * a + 3 * b;
			if (a + b + c == n) {
				f = true;
				cout << a << ' ' << b << ' ' << c << '\n';
			}
		}
	}
	if (f == false)
		cout << "No Answer.";

	cout << endl;
	return 0;
}
