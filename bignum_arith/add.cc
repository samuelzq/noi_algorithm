#include <cstring>
#include <iostream>

using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define c2i(x)    ((x) - '0')
inline void pad_zero(string &a, string &b)
{
	if (a.length() < b.length())
		a.insert(a.end(), b.length() - a.length(), '0');
	else
		b.insert(b.end(), a.length() - b.length(), '0');
}

int main()
{
	string s1, s2;

	std::ios::sync_with_stdio(false);

	while (cin >> s1 >> s2) {
		string a, b;
		int al, bl, len;
		a.assign(s1.rbegin(), s1.rend());
		b.assign(s2.rbegin(), s2.rend());
		al = a.length();
		bl = b.length();
		len = max(al, bl);
		pad_zero(a, b);

		int *c = new int[len + 1]();
		for (int i = 0; i < len; i++) {
			c[i] += c2i(a[i]) + c2i(b[i]);
			if (c[i] >= 10)	{
				c[i + 1] += c[i] / 10;
				c[i] %= 10;
			}
		}

		if (c[len])
			len++;
		else {
			while ((!c[len - 1]) && len > 1)
				len--;
		}
		for (int i = len; i > 0; i--)
			cout << c[i - 1];
		cout << endl;
		delete c;
	}
	return 0;
}