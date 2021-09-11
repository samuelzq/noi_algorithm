#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j++) {
			int k, t;
			t = (i*i + j*j);
			if (t > n*n)
				break;

			k = sqrt(t);
			if (k*k == t)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
