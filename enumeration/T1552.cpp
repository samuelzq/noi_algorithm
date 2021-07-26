// 如果能攻击，位置不外乎是同一行，同一列，同一对角线。
// 设矩阵为n*m，那么，前面2者的可能性就是(m+n-2)*n*m;
// 剩下则需要循环计算对角线上可能的情况。

#include <iostream>

using namespace std;

int main(void)
{
	long long n, m;
	long long ans = 0;

	while (cin >> n >> m && (n+m != 0)){
		long long temp = 0;

		// 确保行数小于列数
		if (n < m) {
			temp = m;
			m = n;
			n = temp;
		}

		// 同一行、同一列上的情况。
		ans = m * n * (m + n -2);

		// 先统计不完整对角线上的情况
		for (int i = 2; i <= m; i++)
			ans += 4 * (m - i + 1) * (m - i);

		// 统计完全对角线上的情况
		for (int i = 1; i <= n - m + 1; i++)
			ans += 2 * m * (m - 1);
		cout << ans << '\n';
	}

	cout << endl;
	return 0;
}
