#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;

	while (cin >> str) {
		int ans = 0;
		int l = str.length();

		for (string::iterator it = str.begin(); it < str.end(); it++) {
			if (*it == 'B') {
				cout << ans << '\n';
				break;
			} else if (*it == '(') {
				ans++;
			} else {
				ans--;
			}
		}
	}
	return 0;
}
