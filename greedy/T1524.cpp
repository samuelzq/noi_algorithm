#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	double d, ans;

	ans = 0.0;

	cin >> d;

	for (int i = 0; i < 12; i++) {
		double r, rmb;
		cin >> r;
		rmb = d * r;
		if (ans < rmb)
			ans = rmb;
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}
