#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
char d[64] = {0};

int main(void)
{
	int a, b, l, i;
	string n;
	long long c, s;

	cin >> a >> n >> b;

	c = 0;
	transform(n.begin(), n.end(), n.begin(), ::tolower);
	for (string::iterator rit = n.begin(); rit != n.end(); ++rit) {
		c *= a;
		if (*rit >= '0' && *rit <= '9')
			c += *rit - '0';
		else
			c += *rit - 'a' + 10;
	}

	i = 0;
	while (c) {
		int e = c % b;

		if (e >= 0 && e <= 9)
			d[i] = e + '0';
		else
			d[i] = e - 10 + 'A';
		i++;
		c /= b;
	}

	while (i) {
		cout << d[--i];
	}
	return 0;
}
