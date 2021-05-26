#include <iostream>

int cc[26] = {0, };

using namespace std;

int main(void)
{
	int n, k, sn, ans, p;
	string str;

	cin >> n >> k;
	cin >> str;

	// parse string
	sn = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '*')
			cc[str[i] - 'a']++;
	}

	sn = n - k;
	p = 1;
	for (int i = sn; i > 0; i--)
		p *= i;
	for (int i = 0; i < 26; i++) {
		for (int j = cc[i]; j > 0; j--)
			p /= j;
	}
	if (k == 0) {
		ans = p;
		goto exit;
	}
	ans = 0;
	for (int i = 0; i < 26; i++) {
		int p1 = (sn + 1 - cc[i]) * p;
		ans += p1;
		if (k == 2) {
			cc[i]++;
			for (int j = 0; j < 26; j++)
				ans += (sn + 2 - cc[i]) * p1;
			cc[i]--;
		}
	}
exit:
	cout << ans;

	return 0;
}
