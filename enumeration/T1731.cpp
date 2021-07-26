#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int x[1005];
int y[1005];

int main(void)
{
	int n;
	long long ans = 0x7fffffffffff;

	cin >> n;

	if (n == 1) {
		cout << 0.00;
		return 0;
	}

	cin >> x[1] >> y[1];
	for (int i = 2; i <= n; i++) {
		cin >> x[i] >> y[i];
		for (int j = i - 1; j >= 1; j--) {
			long long dx, dy, t;
			dx = x[i] - x[j];
			dy = y[i] - y[j];
			t = dx * dx + dy * dy;
			if (ans > t)
				ans = t;
		}
	}

	cout << fixed << setprecision(2);
	cout << 2 * ans * 3.141592653;
	return 0;
}
