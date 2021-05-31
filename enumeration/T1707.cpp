#include <iostream>

using namespace std;

int main()
{
	int n, x, k;
	cin >> n;

	// k是从小到大，开100准够
	for (k = 1; k <= 100; ++k) {        // x是从大到小
		for (x = 100; x > 0; --x) {
			if ((7 * x + 21 * k) * 52 == n) {
				cout << x << endl << k << endl;
				return 0;
			}
		}
	}
}
