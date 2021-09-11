#include <iostream>
#include <algorithm>
#include <cmath>

int d[1000005];

int fcd(int a, int b)
{
	int t, i;

	if (a < b) {
		t = b;
		b = a;
		a = t;
	}

	t = b;
	while (t) {
		t = a % b;
		a = b;
		b = t;
	}
	
	t = sqrt(a) + 1;

	for (i = 2; i < t; i++) {
		if (b % i == 0)
			break;
	}

	if (i == t)
		return 1;
	else {
		t = a / i;
		if (t > i)
			return t;
		else
			return i;
	}
}

using namespace std;

int main(void)
{
	int n, i, j, f, ans = 0;

	cin >> n;

	for (i = 0; i < n; i++)
		cin >> d[i];
	sort(d, d + n);

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			f = fcd(d[i], d[j]);
			if (f > ans)
				ans = f;
		}
	}
	cout << ans;
	return 0;
}
