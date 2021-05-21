#include <iostream>

using namespace std;

int main(void)
{
	int n, m, a, b, c, d, t, ans = 0;

	cin >> n >> m >> a >> b >> c;

	ans = n * a + m * b;

	if (n < m) {
		d = m - n;
		t = 2 * n * c + d * b;
		if (t > ans)
			ans = t;
	} else {
		d = n - m;
		t = 2 * m * c + d * a;
		if (t > ans)
			ans = t;
	}
	cout << ans << endl;
	return 0;
}
