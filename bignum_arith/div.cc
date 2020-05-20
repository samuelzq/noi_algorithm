#include <iostream>
using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define c2i(x)    ((x) - '0')

inline bool greater_eq(int a[], string &b, int last_dg, int len)
{
	// devidend is longer than devisor
	if (a[last_dg + len] != 0)
		return true;

	// compare each bit
	for (int i = len - 1; i >= 0; --i) {
		if (a[last_dg + i] > c2i(b[len - i - 1]))
			return true;
		if (a[last_dg + i] < c2i(b[len - i - 1]))
			return false;
	}
	// eq
	return true;
}

int main()
{
	string a, b;

	std::ios::sync_with_stdio(false);

	while (cin >> a >> b) {
		int *r, *q;

		if ((a.length() < b.length()) ||
		    (a.length() == b.length() && a < b)) {
			cout << "Q:0 R:" << b << '\n';
			continue;
		} else if (a == b) {
			cout << "Q:1 R:0" << '\n';
			continue;
		}

		r = new int[a.length() + 1]();
		q = new int[a.length() - b.length() + 1]();

		for (int i = 0; i < a.length(); i++)
			r[i] = c2i(a[a.length() - 1 - i]);
		for (int i = a.length() - b.length(); i >= 0; i--) {
			// get each bit of Quotient
			while (greater_eq(r, b, i, b.length())) {
				// substraction here
				for (int j = 0; j < b.length(); ++j) {
					r[i + j] -= c2i(b[b.length() - j - 1]);
					if (r[i + j] < 0) {
						r[i + j + 1] -= 1;
						r[i + j] += 10;
					}
				}
				q[i] += 1;
			}
		}
		int lq = a.length() - b.length() + 1;
		int lr = b.length() + 1;
		while ((!q[lq - 1]) && lq > 1)
				lq--;
		while ((!r[lr - 1]) && lr > 1)
				lr--;
		cout << "Q:";
		for (int i = lq; i > 0; i--)
			cout << q[i - 1];
		cout << " R:";
		for (int i = lr; i > 0; i--)
			cout << r[i - 1];
		cout << '\n';
		delete[] r;
		delete[] q;
	}
	return 0;
}