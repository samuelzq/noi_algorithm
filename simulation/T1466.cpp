#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int n;
	double ans;
	cin >> n;

	ans = 0;
	for (int i = 1; i <= n; i++) {
		double sum = 1;
		for (int j = 1; j <= i; j++) {
			sum *= j;
		}
		ans += 1 / sum;
	}
	cout << "sum=" << fixed << setprecision(5) << ans;
	return 0;
}
