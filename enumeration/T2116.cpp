#include <iostream>
#include <cmath>

using namespace std;

int n, k, a[25], ans=0;

bool check(int x)
{
	int t = sqrt((double)x) + 0.5;
	for (int i = 2; i <= t; i++)
		if (x % i == 0)
			return false;
	return true;
}

void slove(int x, int t, int sum)
{
	if (t > k || x > n)
		return;                   //如果选的数的个数大于k，或者x越界（x要多一位）
	if (t == k && check(sum) == true) {//如果已经选了k个数，且和是素数
		ans++;
		return ;
	}

	slove(x + 1, t + 1, sum + a[x]); //选择这个数
	slove(x + 1, t, sum);            //不选这个数
}

int main(void)
{
	ans=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin>>a[i];
	slove(0, 0, 0);
	cout << ans;
}
