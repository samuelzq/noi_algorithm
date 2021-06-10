#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, i = 0;
	char c;
	string str;

	cin >> str;
	n = str.length();
	cout << n;

	c = str[0];
	if (c == '1')
		cout << ' ' << 0;
	while (--n) {
		for (string::iterator it = str.begin(); it < str.end(); it++) {
			if (*it == c)
				i++;
			else {
				cout << ' ' << i;
				i = 1;
				c = *it;
			}
		}
		cin >> str;
	};
	for (string::iterator it = str.begin(); it < str.end(); it++) {
		if (*it == c)
			i++;
		else {
			cout << ' ' << i;
			i = 1;
			c = *it;
		}
	}
	cout << ' ' << i;
	return 0;
}
