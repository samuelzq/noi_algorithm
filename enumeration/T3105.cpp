#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, ans, idx;
	string s;
	string str;

	cin >> t;

	while (t--) {
		int c, l = 0;
		cin >> str;
		s = str;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		ans = 1;
		idx = 0;

		c = l = 0;
		for (int i = 0; i < str.length() - 1; i++) {
			if (s[i + 1] == s[i] + 1 || s[i + 1] == s[i] - 1 ||
					(s[i] == 'a' && s[i + 1] == 'z') || (s[i] == 'z' && s[i + 1] == 'a'))
				c++;
			else
				l = ++c;

			if (c - l + 1 > ans) {
				ans = c - l + 1;
				idx = l;
			}
		}
		for (int i = idx; i < idx + ans; i++)
			cout << str[i];
		cout << '\n';
	}
	return 0;
}
