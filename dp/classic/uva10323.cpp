/**
 * Factorial! You Must be Kidding!!! UVA - 10323
 * https://vjudge.net/problem/UVA-10323
 *
 * 问题的关键是输入可能有负数。根据定义：factorial(n) = n*(n−1)*factorial(n−2)
 * f(-1)=f(0)/0=∞；f(-2)=f(0)/0/-1=-∞；因此负的奇数的结果是overflow，负的偶数的结
 * 果是underflow。
 *
 * @File:   uva10323.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-12
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const long long MAXL = 6227020800;
const long long MINL = 10000;
long long f[100];
int underflow, overflow = 0;

void fact(void)
{
	long long t;
	f[0] = f[1] = 1;
	for (int i = 2; i < 100; i++) {
		t = f[i - 1] * i;
		if (t < MINL)
			underflow = i;
		if (overflow == 0 && t > MAXL) {
			overflow = i;
			break;
		}
		f[i] = t;
	}
}

int main(void)
{
	int t;
	fact();
	while (scanf("%d", &t) != EOF) {
		if (t < 0) {
			if (t % 2)
				printf("Overflow!\n");
			else
				printf("Underflow!\n");
		} else {
			if (t <= underflow)
				printf("Underflow!\n");
			else if (t >= overflow)
				printf("Overflow!\n");
			else
				printf("%lld\n", f[t]);
		}
	}
	return 0;
}
