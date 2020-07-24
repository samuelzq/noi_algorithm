// recursive
int re_fexp(int a, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 1)
		return re_fexp(a, n - 1) * a;
	else {
		int temp = re_fexp(a, n / 2);
		return temp * temp;
	}
}


// iteration
//将对应二进制位为 1 的整系数幂乘起来
int it_fexp(int a, int n)
{
	int ans = 1;
	while (n) {
		if (n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}
