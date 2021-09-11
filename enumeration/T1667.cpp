#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, ans = 0;

	cin >> n;

	for (int a = 0; a * a <= n; a++) {
		for (int b = 0; a*a + b*b <= n; b++) {
			for (int c = 0; a*a + b*b + c*c <= n; c++) {
				int d, s;
				s = n - a*a - b*b - c*c;
				d = sqrt(s);

				if (d*d == s)
					ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
