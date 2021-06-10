#include <iostream>

using namespace std;

int bb[1005];

int main(void)
{
	int n;
	long long a, b;

	cin >> n >> a;
	if (n == 1) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		long long d;
		cin >> b;
		if (b > a)
			d = b - a;
		else
			d = a - b;
		if (d > n - 1) {
			while (i++ < n - 1)
				cin >> b;
			cout << "NO";
			return 0;
		} else {
			bb[d] = 1;
			a = b;
		}
	}

	for (int i = 1; i < n; i++) {
		if (bb[i] == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
