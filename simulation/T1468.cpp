#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int m, n;
	double h, d;

	cin >> m >> n;

	h = m;
	d = 0;
	for (int i = 0; i < n; i++) {
		d += h;
		h /= 2.0;
		d += h;
	}
	cout << fixed << setprecision(2) << h << ' ' << d;
	return 0;
}
