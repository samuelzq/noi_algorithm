#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int w, l;
} REC;

REC rec[1003] = {0, };
int f[1003];

bool cmp(REC r1, REC r2)
{
	if (r1.w == r2.w)
		return r1.l > r2.l;
	else
		return r1.w < r2.w;
}

int main(void)
{
	int s, n, ans;
	cin >> s;
	while (s--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int w, d;
			cin >> w >> d;
			if (w > d) {
				rec[i].l = w;
				rec[i].w = d;
			} else {
				rec[i].l = d;
				rec[i].w = w;
			}
		}
		sort(rec, rec + n, cmp);
		for (int i = 0; i < n; i++)
			f[i] = 1;
		ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (rec[i].l > rec[j].l && rec[i].w > rec[j].w)
					f[i] = ((f[i] > f[j] + 1) ? f[i] : (f[j] + 1));
			}
			ans = ans > f[i] ? ans : f[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
