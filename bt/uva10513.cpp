/**
 * https://vjudge.net/problem/UVA-10513
 *
 * 首先将所有不符合要求的排列筛出。
 * 然后计算输入的pattern所有可能的排列数目。
 * 最后计算输入pattern中可能的不符合要求的排列数目。
 *
 * @File:   uva10513.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int n, nxt[18], num[16], tbl[16][127];
char str[16][33000][17], lst[17], s[20], *ptr;

// 找出所有的不符合要求的排列。
void dfs(int depth)
{
	int i, j, k;
	if (depth == n) {
		ptr = str[n][num[n]++];
		for (i = 0; i < n; i++)
			ptr[i] = lst[i] + 64;
		return;
	}

	// 使用链表比used map效率会更高
	for (i = 0; j = nxt[i]; i = j) {
		if (!(depth && abs(lst[depth - 1] - j) == 2) &&
			!(depth > 1 && abs(lst[depth - 2] - j) == 1)) {
			for (k = 0; k < depth; k++) {
				if (depth - k == abs(lst[k] - j))
					break;
			}
			if (k == depth) {
				lst[depth] = j;
				nxt[i] = nxt[j];
				dfs(depth + 1);
				nxt[i] = j;
			}
		}
	}
}

int main()
{
	int cas, i, j;
	long long count;
	cas = 0;
	for (i = 0; i < 16; i++)
		nxt[i] = i + 1;

	strcpy(str[1][num[1]++], "A");
	// 时间优化，长度2~9所有的排列都满足要求
	for (i = 10; i < 16; i++) {
		n = i;
		lst[n] = 0;
		nxt[n] = 0;
		dfs(0);
		nxt[n] = n + 1;
	}
	while (scanf("%d", &n) == 1) {
		if (!n)
			break;
		memset(tbl, 0, sizeof(tbl));
		for (i = 0, count = 1; i < n; i++) {
			scanf("%s", s);
			if (s[0] == '?') {
				tbl[i][0] = 1;
				count *= n;
			} else {
				for (j = 0; s[j]; j++)
					tbl[i][s[j]] = 1;
				count *= j;
			}
		}

		// num[i]记录不同长度下不符合要求的排列的数量
		for (i = 0; i < num[n]; i++) {
			for (j = 0; j < n; j++) {
				// str[n][i]是长度为n的排列中第i个不符合条件的组
				// 合。如果第j个输入是？，则该位置肯定会出现一次
				// 不符合的选择。如果第j个输入是有效字符，则依次
				// 检验每个字符是否都不应该出现在该位置。
				if (!tbl[j][0] && !tbl[j][str[n][i][j]])
					break;
			}
			// 当前的输入可以凑成str[n][i]
			count -= (j == n);
		}
		printf("Case %d: %lld\n", ++cas, count);
	}
	return 0;
}
