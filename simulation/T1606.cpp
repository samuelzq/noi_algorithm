#include <iostream>

using namespace std;

int ans = 1;
int main(void)
{
	int n, a, b, l;
	cin >> n;
	l = 0;
	cin >> a;
	b = a;
	l = 1;
	while (--n) {
		cin >> a;
		if (a - b == 1) {
			l++;
		} else {
			if (l > ans)
				ans = l;
			l = 1;
		}
		b = a;
	}
	if (l > ans)
		ans = l;
	cout << ans;
	return 0;
}
