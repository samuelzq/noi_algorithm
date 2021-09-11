#include <iostream>

using namespace std;

long long aa[100005] = {0, };
long long qq[100005] = {0, };

int main(void)
{
	int n, q;
	long long sum = 0;

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t >> qq[i];
		sum += t;
		aa[i] = sum;
	}

	for (int i = 0; i < q; i++) {
		int l = 0, r = n - 1;
		int mid, ans;
		long long t;
		cin >> t;

		// 使用二分法查找否则会超时
		ans = 0;
		while (l <= r) {
			mid = (r + l) / 2;
			if (t == aa[mid]) {
				ans = mid;
				break;
			} else if (t < aa[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (ans)
			cout << qq[ans] << '\n';
		else if (r == -1)
			cout << qq[0] << '\n';
		else
			cout << qq[l] << '\n';
	}
	return 0;
}
