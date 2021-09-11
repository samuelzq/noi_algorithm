#include <iostream>

using namespace std;

int main(void)
{
	long long m, n, a, x;

	cin >> m >> n;

	x = 0;
	while (n) {
		x++;
		n--;
		cin >> a;
		m = m - a;

		if (m <= 0) {
			while (n) {
				cin >> a;
				n--;
			}
			break;
		} else {
			m = 2 * m;
		}
	}
	if (m <= 0)
		cout << -1 * x;
	else
		cout << m;
	return 0;
}
