#include <iostream>
#include <algorithm>

using namespace std;

int h[20004] = {0, };

bool cmp(int x, int y)
{
	return x > y;
}

int main(void)
{
	int n, ans;
	long long b, s;

	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(h, h + n, cmp);
	ans = 0;
	s = 0;
	while (s < b) {
		s += h[ans++];
	}
	cout << ans;
	return 0;
}
