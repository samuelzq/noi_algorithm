#include <iostream>
#include <cstring>

using namespace std;

int idx[10004] = {0, };

int main(void)
{
	int n;
	long long ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		idx[i] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (idx[i] > idx[j]) {
				int t = idx[i];
				idx[i] = idx[j];
				idx[j] = t;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
