#include <iostream>
#include <cmath>

using namespace std;
int b[9];                 // 位值
int main(void)
{
	int n, l, mt, temp, ans;
	int j, k, m;

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

	mt = 0;
	for (int i = 1; i <= l; i++)
		mt = mt * 10 + 9;

	temp = mt;
	if (l % 2 != 0) {
		m = l / 2;
		m = pow(10, m);

		for (int i = 0; i < 9 && temp > n; i++) {
			ans--;
			temp -= m;
		}
	}
	if (l % 2 == 0) {
		j = l / 2;
		k = j - 1;
	} else {
		j = l / 2 + 1;
		k = l / 2 - 1;
	}

	for (int j = 0; j < l / 2; j++) {
		temp = mt;
		m = pow(10, j) + pow(10, k);

		for (int i = 0; i < 9 && temp > n; i++) {
			ans--;
			temp -= m;
		}
		j++;
		k--;
	}

	// 去除大于n的个数

	cout << ans << endl;
	return 0;
}
