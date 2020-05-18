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
		bool negative = false;
		al = s1.length();
		bl = s2.length();

		if (al > bl) {
			a.assign(s1.rbegin(), s1.rend());
			b.assign(s2.rbegin(), s2.rend());
		} else if ((al == bl) && (s1 >= s2)) {
			a.assign(s1.rbegin(), s1.rend());
			b.assign(s2.rbegin(), s2.rend());
		} else {
			negative = true;
			a.assign(s2.rbegin(), s2.rend());
			b.assign(s1.rbegin(), s1.rend());
		}
		len = max(al, bl);
		pad_zero(a, b);

		int *c = new int[len + 1]();
		for (int i = 0; i < len; i++) {
#if 0
			if (a[i] == 9) {
				if (a[i + 1])
					a[i + 1]--;
				else
					a[i + 1] = 9;
			}
			c[i] = c2i(a[i]) - c2i(b[i]);
			if (c[i] < 0)	{
				c[i] += 10;
				if (a[i + 1])
					a[i + 1]--;
				else
					a[i + 1] = 9;
			}
#else
			c[i] += c2i(a[i]) - c2i(b[i]);
			if (c[i] < 0)	{
				c[i] += 10;
				a[i + 1]--;
			}
#endif
		}

		while (c[len - 1] == 0 && len > 1)
			len--;
		if (negative)
			cout << '-';
		for (int i = len; i > 0; i--)
			cout << c[i - 1];
		cout << endl;
		delete[] c;
	}
	return 0;
}