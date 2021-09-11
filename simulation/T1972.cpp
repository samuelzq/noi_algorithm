// 将环尽量平分后计算颠倒的次数

#include <iostream>

using namespace std;

int main(void)
{
	int n, ans, t, m;
	cin >> n;

	m = n / 2;
	t = n - m;
	cout << (m * (m - 1) + t * (t - 1)) / 2;
	return 0;
}
