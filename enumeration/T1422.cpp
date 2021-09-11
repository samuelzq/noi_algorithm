#include <iostream>
#include <cmath>

using namespace std;

double x[102], y[102];

int main(void)
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k <= n; k++) {
				double x1, x2, x3, y1, y2, y3;
				double k1, k2;

				x1 = x[i]; y1 = y[i];
				x2 = x[j]; y2 = y[j];
				x3 = x[k]; y3 = y[k];
				k1 = (y2 - y1)/(x2 - x1);
				k2 = (y3 - y1)/(x3 - x1);

				if (abs(k1 - k2) < 0.00001)
					goto found;
			}
		}
	}
	cout << "NO" << endl;
	return 0;

found:
	cout << "YES" << endl;
	return 0;
}
