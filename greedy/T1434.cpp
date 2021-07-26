#include <iostream>

using namespace std;

int main(void)
{
	long long  n, k, s, a, b, c;

	cin >> n >> k >> s;
	if (k > s || s > (n - 1) * k ) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	a = s / (n - 1); // 一次移动n-1
	b = s % (n - 1); // 剩余每次移动1步
	// 确保搬家的次数满足要求, b+a-k <= n - 2
	while (b + a < k) {
		a--;
		b += n - 1;
	}

	// 在1～n之间移动，循环a次
	for (int i = 0; i < a; i++) {
		if (i % 2)
			c = 1;
		else
			c = n;
		cout << c << ' ';
	}

	// a+b-k=n-2。移动一大步
	if (b + a != k) {
		if (c == n)
			c = n - (a + b - k) - 1;
		else
			c = 1 + (a + b - k) + 1;
		cout << c << ' ';
	}

	// 左右移动，循环k-a-1(b-1)
	for (int i = 1; i < k - a; i++) {
		if (c == 1)
			c++;
		else
			c--;
		cout << c << ' ';
	}

	// 补上1步
	if (a + b == k)
		cout << ++c;
	return 0;
}
