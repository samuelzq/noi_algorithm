#include <iostream>
#include <string>

using namespace std;

int status = 0;

int main(void)
{
	string str;
	int l1, l2, r1, r2, l, i, ans = 0;

	cin >> str;
	l = str.length();
	l1 = l2 = -1;
	for (i = 0; i < l; i++) {
		if (str[i] == '[') {
			l1 = i;
			break;
		}
	}
	if (l1 >= l - 3) {
		cout << -1;
		return 0;
	}
	for (; i < l - 2; i++) {
		if (str[i] == ':') {
			l2 = i;
			break;
		}
	}
	if (l2 == -1) {
		cout << -1;
		return 0;
	}

	ans = l1 + l2 - l1 - 1;

	r1 = r2 = -1;
	for (i = l - 1; i >= 0; i--) {
		if (str[i] == ']') {
			r1 = i;
			break;
		}
	}
	if (r1 < l1 + 3) {
		cout << -1;
		return 0;
	}

	for (; i >= 0; i--) {
		if (str[i] == ':') {
			r2 = i;
			break;
		}
	}
	if (l2 == r2) {
		cout << -1;
		return 0;
	}
	ans = ans + (l - r2 - 2);

	for (int i = l2 + 1; i < r2; i++) {
		if (str[i] != '|')
			ans++;
	}
	cout << ans;
	return 0;
}
