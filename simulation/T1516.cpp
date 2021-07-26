#include <iostream>

using namespace std;

int main(void)
{
	int d, v, ans, i;

	while (cin >> d >> v) {
		ans = (d + v - 1) / v;
		for (i = 1; d > 0; i++) {
			d -= i*v;
			ans++;
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}
