#include <iostream>

using namespace std;

int num[20];

int main(void)
{
	int c, n = 0;
	int ans = 0;

	while (cin >> c && c != 0) {
		num[n] = c;
		n++;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i] == 2*num[j] || num[i]*2 == num[j])
				ans++;
		}
	}
	cout << ans;
	return 0;
}
