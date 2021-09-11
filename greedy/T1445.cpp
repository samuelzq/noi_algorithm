#include <iostream>
#include <algorithm>

using namespace std;

int s[103];

int main(void)
{
	int n, ans;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	sort(s, s + n);

	ans = 0;
	for (int i = 0; i < n; i += 2) {
		ans += s[i + 1] - s[i];
	}
	cout << ans;
	return 0;
}
