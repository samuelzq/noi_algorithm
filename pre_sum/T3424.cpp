#include <iostream>

using namespace std;

int aa[1003] = {0, };

int main(void)
{
	int n, k, sum;

	cin >> n >> k;

	sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum += t;
		aa[i] = sum;
	}

	sum = 0;
	for (int i = 0; i < n - 1; i++) {
		if ((aa[i] % k) == 0)
			sum++;
		for (int j = i + 1; j < n; j++) {
			if ((aa[j] - aa[i]) % k == 0)
				sum++;
		}
	}
	if (aa[n - 1] % k == 0)
		sum++;
	cout << sum;
	return 0;
}
