#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	double ld, cd, d;
	int n;
	double ans = 2.00;
	cin >> n;
	ld = 1.0;
	d = 2.0;

	for (int i = 1; i < n; i++) {
		cd = d;
		d = cd + ld;
		ans += (double)d / (double)cd;
		ld = cd;
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}
