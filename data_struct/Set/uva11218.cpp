/**
 * KTV UVA - 11218
 * https://vjudge.net/problem/UVA-11218
 *
 * 使用9位二进制数表示每一种组合。3个不重叠的组合其编号交集正好占满所有位值。
 *
 * @File:   uva11218.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-02
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 500;
int bit_set[N];    // 每个组合的编号
int score[N];      // 每个组合的得分

int main(void)
{
	int k, t;

	t = 1;
	while (cin >> k && k != 0) {
		int a, b, c, s;
		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c >> s;
			bit_set[i] = (1 << (a - 1)) | (1 << (b - 1)) | (1 << (c - 1));
			score[i] = s;
		}

		// 暴力枚举每一种可能的组合
		int ans = -1;
		for (int i = 0; i < k - 2; i++) {
			for (int j = i + 1; j < k - 1; j++) {
				for (int l = j + 1; l < k; l++) {
					if ((bit_set[i] | bit_set[j] | bit_set[l]) == ((1 << 9) -1))
						ans = max(ans, score[i] + score[j] + score[l]);
				}
			}
		}
		cout << "Case " << t++ << ": " << ans << "\n";
	}
	return 0;
}