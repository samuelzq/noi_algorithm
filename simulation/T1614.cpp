#include <iostream>

using namespace std;

int main(void)
{
	int ans;
	double x, s = 2.0;

	cin >> x;
	ans = 0;
	while (x > 0.0) {
		ans++;
		x -= s;
		s *= 0.98;
	}
	cout << ans;
	return 0;
}
