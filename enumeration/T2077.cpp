// 需要考虑重复的情况，如：
// 5
// 1 2 2 2 4
// 正确的输出应该是1

#include <iostream>
#include <algorithm>

using namespace std;

int d[10005];
int b[10005] = {0};       // 避免重复

int main(void)
{
	int n, ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d, d + n);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (b[k] == 0 && d[k] == d[j] + d[i]) {
					b[k] = 1;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
