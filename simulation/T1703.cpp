#include <iostream>

using namespace std;

int main(void)
{
	int n, m, d, t1, t2, ans;

	cin >> n >> m;
	ans = m;
	cin >> t1;
	d = t1 + m;
	t2 = t1;
	for (int i = 1; i < n; i++) {
		cin >> t1;
		if (t1 - t2 > m)
			ans += m;
		else
			ans += t1 - t2;
		t2 = t1;
	}
	cout << ans;
	return 0;
}
