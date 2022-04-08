/**
 * Forests UVA - 12650
 * https://vjudge.net/problem/UVA-12650
 *
 * 使用位图记录每一个生还者。
 *
 * @File:   uva12650.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-02
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 10002;

int rev[N / sizeof(int)];

int get_pos(int element)
{
    return element >> 5;
}

int get_bit(int element)
{
    return 1 << (element & 31);
}

int main(void)
{
	int n, r;

	while(scanf("%d %d", &n, &r) != EOF) {
		int p;
		memset(rev, 0, sizeof(rev));
		for (int i = 0; i < r; i++) {
			scanf("%d", &p);
			rev[get_pos(p)] |= get_bit(p);
		}

		p = 0;
		for (int i = 1; i <= n; i++) {
			if (!(rev[get_pos(i)] & get_bit(i))) {
				printf("%d ", i);
				p++;
			}
		}
		if (p == 0)
			printf("*\n");
		else
			printf("\n");
	}
	return 0;
}
