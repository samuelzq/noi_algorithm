#include <iostream>

using namespace std;

//long long a[100005] = {0, };

int main(void)
{
	long long n, m, sum, a0, a1;

	cin >> n >> m;
	cin >> a0;

	sum = 0;
	if (a0 > m) {
		sum += a0 - m;
		a0 = m;
	}

	for (int i = 1; i < n; i++) {
		cin >> a1;
		if (a1 + a0 > m) {
			int d = a1 + a0 - m;
			sum += d;
			a1 = m - a0;
		}
		a0 = a1;
	}
	cout << sum;
	return 0;
}
