#include <bits/stdc++.h>

using namespace std;

int collatz(int a, int b)
{
	int x, y, steps;

	if (a > b) {
		x = b;
		y = a;
	} else {
		x = a;
		y = b;
	}
	if (x < y / 2)
		x = y / 2;

	steps = 0;
	for (int i = x; i <= y; i++) {
		int s = 0, n;
		n = i;
		do {
			if (n & 1)
				n = n * 3 + 1;
			else
				n /= 2;
			s++;
		} while (n > 1);
		steps = max(steps, s);
	}
	return steps;
}

int main(void)
{
	int a, b;
	while (cin >> a >> b) {
		cout << a << ' ' << b << ' ' << collatz(a, b) + 1 << '\n';
	}
	return 0;
}