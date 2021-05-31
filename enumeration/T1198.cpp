#include <iostream>

using namespace std;

int num[605];

int gcd(int a, int b)
{
	int x, y, t;

	if (a > b) {
		x = a;
		y = b;
	} else {
		x = b;
		y = a;
	}

	t = 1;
	while (t) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}

int main(void)
{
	int n, ans;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (gcd(num[i], num[j]) == 1)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
