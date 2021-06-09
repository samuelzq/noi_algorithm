#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	bool p = true;
	int i, l;
	long long a, b, ans = 0;
	string str;

	cin >> str;
	l = str.length();
	b = 0;
	for (i = 0; i < l; i++) {
		if (str[i] == '+') {
			if (p == true)
				ans += b;
			else
				ans -= b;
			p = true;
			b = 0;
		} else if (str[i] == '-') {
			if (p == true)
				ans += b;
			else
				ans -= b;
			p = false;
			b = 0;
		}else {
			b = b * 10 + (str[i] - '0');
		}
	}
	if (p == true)
		ans += b;
	else
		ans -= b;
	cout << ans;
	return 0;
}
