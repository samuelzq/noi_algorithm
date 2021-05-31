#include <iostream>

using namespace std;
int sum = 0;

int main(void)
{
	int n, a, b, c;

	/*
	 * 15a+9b+c=3n  (1)
	 * a+b+c=n      (2)
	 * 由（1）和（2）可得
	 * 7a+4b=n      (3)
	 * 问题转化为求（3）可能解的组数。
	 * 4和7最小公倍数为28，所以a每减小4，就应有一组解；若没有，则方程无解。
	 * 需要注意的是，根据定理：当n大于4*7-4-7（17）时，必有解。
	 * 所以小于17的情况就直接枚举。
	 */

	cin >> n;

	if (n == 1 || n == 2 || n == 3 || n == 5 ||
	    n == 6 || n == 9 || n == 10|| n == 13 ||
	    n == 17) {
		cout << "No Answer.";
		return 0;
	}

	a = n / 7;       //  a 最大可能的值
	while ((n - 7*a) % 4 != 0)
		a--;

	cout << a / 4 + 1 << endl;
	return 0;
}
