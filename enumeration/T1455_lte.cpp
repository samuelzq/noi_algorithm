#include <iostream>
#include <cmath>

using namespace std;
int b[9];                 // 位值
int main(void)
{
	int n, l, temp, ans;

	cin >> n;

	temp = n;
	l = 0;
	while (temp) {
		b[l] = temp % 10;
		l++;       // 计算位长
		temp /= 10;
	}

	// 首先统计l位整数回文数的个数
	ans = 0;
	for(int i = 1; i <= l; i++) {
		temp = (i - 1)/2;
		ans += 9 * pow(10, temp);
	}

	// 去除大于n的个数
	temp = pow(10, l);
	for (int i = n + 1; i < temp; i++) {
		int k, t = i;
		l = 0;
		while (t) {
			b[l] = t % 10;
			l++;
			t /= 10;
		}
		for (k = 0; k < l / 2; k++) {
			if (b[k] != b[l - k - 1])
				break;
		}

		if (k == l / 2)
			ans--;
	}


	cout << ans << endl;
	return 0;
}
