#include <iostream>

using namespace std;
int A[60];
int B[60];

int main(void)
{
	int q, n, b, ans = 0;
	float a;

	cin >> q;

	while (q--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a >> b;
			A[i] = (int)(a*10);
			B[i] = b;
		}

		ans = 0;
		for (int i = 1; i <= n - 2; i++) {
			for (int j = i + 1; j <= n - 1; j++) {
				for (int k = j + 1; k <= n; k++) {
					int qum, sum;
					qum = A[i] + A[j] + A[k];

					if (qum % 50 != 0)
						continue;

					sum = B[i] + B[j] + B[k];
					if (sum > ans)
						ans = sum;
				}
			}
		}

		if (ans != 0) {
			cout << ans << '\n';
			continue;
		}

		for (int j = 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				int qum;
				int sum;
				qum = A[j] + A[k];

				if (qum % 50 != 0)
					continue;

				sum = B[j] + B[k];
				if (sum > ans)
					ans = sum;
			}
		}

		if (ans != 0) {
			cout << ans << '\n';
			continue;
		}

		for (int k = 1; k <= n; k++) {
			int qum, sum;
			qum = A[k];

			if (qum % 50 != 0)
				continue;

			sum = B[k];
			if (sum > ans)
				ans = sum;
		}

		cout << ans << '\n';
	}
	return 0;
}
