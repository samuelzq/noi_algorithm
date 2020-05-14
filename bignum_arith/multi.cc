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

void single_precision_m(string a, int b, int *c)
{
	for (int i = 0; i < a.length(); i++) {
		c[i] += c2i(a[i]) * b;

		if (c[i] >= 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

void doulbe_precision_m(string a, string b, int *c)
{
	int i = 0;

	while (i < b.length()) {
		for (int j = 0; j < a.length(); j++)
			c[j + i] += c2i(a[j]) * c2i(b[i]);

		if (c[i] >= 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		i++;
	}
}

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2) {
		string a, b;
		a.assign(s1.rbegin(), s1.rend());
		b.assign(s2.rbegin(), s2.rend());
		int len = max(a.length(), b.length()) * 2;
		int *c = new int[len]();
		pad_zero(a, b);
		doulbe_precision_m(a, b, c);
		while ((!c[len - 1]) && len > 1)
				len--;

		for (int i = len; i > 0; i--)
			cout << c[i - 1];
		cout << endl;
		delete c;
	}
}