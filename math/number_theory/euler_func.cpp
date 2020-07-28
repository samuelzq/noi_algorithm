// 欧拉函数是小於或等於n的正整數中與n互質的數的數目
// 例如{\displaystyle \varphi (8)=4}\varphi (8)=4，因為1,3,5,7均和8互質

#include <iostream>
#include <cmath>

int euler_phi(int n)
{
	int m = int(sqrt(n + 0.5));
	int ans = n;

	for (int i = 2; i <= m; i++) {
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}

	// n 是质数
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}
