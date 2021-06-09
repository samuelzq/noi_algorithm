#include <iostream>

using namespace std;

int l[10005] = {0, };

int main(void)
{
	int n, t;
	double a, b;

	cin >> n;

	while (n--) {
		int i, j;
		cin >> a >> t;
		for (i = 1; i <= t; i++) {
			b = a * i;
			j = (int)b;
			l[j] ^= 1;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (l[i]) {
			cout << i;
			return 0;
		}
	}
	return -1;
}
