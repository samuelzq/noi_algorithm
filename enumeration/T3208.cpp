#include <iostream>
#include <cmath>

using namespace std;

long long x, y;

int main(void)
{
	int n;
	long xc, yc, rc;
	int ans;

	cin >> n;
	cin >> xc >> yc >> rc;

	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (abs(x - xc) > rc || abs(y - yc) > rc)
			continue;
		if (((x - xc) * (x - xc) + (y - yc) * (y - yc)) <= rc * rc)
			ans++;
	}
	cout << ans;
	return 0;
}
