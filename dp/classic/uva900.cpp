/**
 * Brick Wall Patterns UVA - 900
 * https://vjudge.net/problem/UVA-900
 *
 * n块的结果等于：n-2块每一种右侧横着两块，n-1块每一种右侧竖着一块
 *
 * @File:   uva900.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-13
 *
 **/
#include <bits/stdc++.h>

using namespace std;

long long bricks[51];

void init(void)
{
	bricks[0] = bricks[1] = 1;
	for (int i = 2; i < 51; i++) {
		bricks[i] = bricks[i - 2] + bricks[i - 1];
	}
}

int main(void)
{
	int t;
	init();
	while (scanf("%d", &t) != EOF && t)
		printf("%lld\n", bricks[t]);
	return 0;
}
