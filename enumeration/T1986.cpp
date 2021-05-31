#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 9989899  // 满足题意最小的回文素数
bool isnp[MAXN]; // is not prime: 不是素数

void init(int n)
{
	for (int i = 2; i * i <= n; i++)
 		if (!isnp[i])
			for (int j = i * i; j <= n; j += i)
				isnp[j] = 1;
}

void satisfy(int i)
{
	int a = i;
	int b = 0;
	while (a > 0) {
		b = b * 10 + a % 10;
		a = a / 10;
	}

	if (b == i)
		cout << i << '\n';
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	n = min(n, MAXN);
	init(n);
	for (int i = m; i <= n; i++) {
		if (!isnp[i])
			satisfy(i);
	}
	return 0;
}
