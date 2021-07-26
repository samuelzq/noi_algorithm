#include <iostream>

using namespace std;

int num[105];

int main(void)
{
	bool f = false;
	int n, ans;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	ans = 0;
	for (int i = 1; i <= n; i++) {
		int c = num[i];
		for (int j = 1; j < n && f == false; j++) {
			for (int k = j+1; k <= n && f == false; k++) {
				if (num[j] + num[k] == c)
					f = true;
			}
		}
		if (f == true)
			ans++;
		f = false;
	}
	cout << ans;
	return 0;
}
