#include <iostream>

using namespace std;

long long dis[1000100] = {0, };

int main(void)
{
	int n, m;
	int a, b, ans;
	long long d, t;
	bool f = false;

	cin >> n >> m;

	d = t = 0;
	while (n--) {
		cin >> a >> b;
		while (b--) {
			d += a;
			dis[t++] = d;
		}
	}

	d = t = 0;
	ans = 0;
	cin >> a >> b;
	if (a > dis[0])
		f = false;
	else
		f = true;
	while (b--) {
		d += a;
		if (f == false) {
			if (dis[t] > d) {
				f = true;
				ans++;
			}
		} else {
			if (dis[t] < d) {
				f = false;
				ans++;
			}
		}
		t++;
	}

	m--;
	while (m--) {
		cin >> a >> b;
		while (b--) {
			d += a;
			if (f == false) {
				if (dis[t] > d) {
					f = true;
					ans++;
				}
			} else {
				if (dis[t] < d) {
					f = false;
					ans++;
				}
			}
			t++;
		}
	}
	cout << ans;
	return 0;
}
