#include <iostream>

using namespace std;

int a[100005] = {0, };

int main(void)
{
	int n, sum;
	cin >> n;

	sum = 0;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		sum += b;
		a[i] = sum;
	}

	sum = 0;
	for (int i = n % 2 ? n - 1 : n; i >= 2; i -= 2) {
		for (int j = n - 1; j - i + 1 >= 0; j--) {
			if ((a[j] - a[j - i]) * 2 == i) {
				cout << i;
				return 0;
			}
		}
	}
	cout << sum;
	return 0;
}
