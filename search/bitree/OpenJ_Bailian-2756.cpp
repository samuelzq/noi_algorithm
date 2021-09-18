#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int x, y;
	int ans;

	cin >> x >> y;
	// 不断将较大的数折半，直到两数相等
	while (x != y) {
		if (x > y) {
			ans = y;
			y = x;
			x = ans;
		}
		y /= 2;
	}
	cout << x;
	return 0;
}