// 反向枚举
// 枚举出所有的回文日期，然后判断是否在给定日期范围内
// 无需考虑闰年，日期是92200229，9220年是闰年。

#include <iostream>
using namespace std;
int s[13] = {0, 31, 29, 31, 30, 31,
		 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
	int i, j;
	int n, m, a, b, c, sum, ans = 0;

	cin >> n >> m;
	for (i = 1; i <= 12; i++) { //枚举月和日
		for (j = 1; j <= s[i]; j++) {
			c = (j % 10) * 1000 +
				(j / 10) * 100 +
				(i % 10) * 10 +
				(i / 10);
			sum = c * 10000 + i * 100 + j;//算出整个日期

			if (sum < n || sum > m)
				continue;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

