#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int i, j, max, l;

	cin >> n;

	max = l = 0;
	for (i = 2; i * i < n; i++) {
		int temp = n, idx = i;
		l = 0;

		if (n % i != 0)
			continue;

		while (temp % idx == 0) {
			temp /= idx;
			idx++;
			l++;
		}
		if (max < l) {
			max = l;
			j = idx - 1;
		}
	}

	if (max == 0) {
		cout << 1 << '\n' << n << endl;
	} else {
		cout << max << '\n';
		cout << j - max + 1;
		for (i = j - max + 2; i <= j; i++)
			cout << '*' << i;

		cout << endl;
	}
	return 0;
}
