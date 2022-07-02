#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
struct rec {
	int w, l;
//	rec(int w, int l) : w(w), l(l) {}
} REC[N];
int dp[N];

bool cmp(struct rec r1, struct rec r2)
{
	if (r1.w == r2.w)
		return r1.l > r2.l;
	else
		return r1.w < r2.w;
}

int main(void)
{
	int n, res;

	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		for (int i = 0; i < t; i++) {
			int w, l;
			cin >> w >> l;
			if (w > l) {
				REC[i].l = w;
				REC[i].w = l;
			} else {
				REC[i].l = l;
				REC[i].w = w;
			}
			dp[i] = 1;
		}
		sort(REC, REC + t, cmp);
		for (int i = 1; i < t; i++) {
			for (int j = 0; j < i; j++) {
				if (REC[i].l > REC[j].l) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		res = 0;
		for (int i = 0; i < t; i++) {
			res = max(res, dp[i]);
		}
		cout << res << '\n';

	}
	return 0;
}
