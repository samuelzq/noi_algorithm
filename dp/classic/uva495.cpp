/**
 * Fibonacci Freeze UVA - 495
 * https://vjudge.net/problem/UVA-495
 *
 * 基本的Fibonacci数列求和，注意大数的位宽
 *
 * @File:   uva495.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-13
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1000000000;
const int L = 125;
int fib[5010][L];

void add(int a[], int b[], int c[])
{
	int s, t, i;

	t = 0;
	for (i = 0; i < L - 1; i++) {
		s = a[i] + b[i] + t;
		t = s / N;
		s = s % N;
		c[i] = s;
	}
	if (t)
		c[i] = t;
	if (t) {
		printf("Overflow\n");
		exit(0);
	}

}

void out(int a[])
{
	int i;
	i = L - 1;
	while (i && !a[i])
		i--;
	printf("%d", a[i--]);
	for (; i >= 0; i--)
		printf("%09d", a[i]);
	printf("\n");
}

void init(void)
{
	fib[0][0] = 0;
	fib[1][0] = 1;
	for (int i = 2; i < 5001; i++)
		add(fib[i - 1], fib[i - 2], fib[i]);
}

int main(void)
{
	int t;

	init();
	while (scanf("%d", &t) != EOF) {
		printf("The Fibonacci number for %d is ", t);
		out(fib[t]);
	}
	return 0;
}
