#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct {
	int w, idx;
} W;

W w[1003] = {0, };

bool cmp(W w1, W w2)
{
	return w1.w < w2.w;
}

int main(void)
{
	int n;
	double ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i].w;
		w[i].idx = i + 1;
	}

	sort(w, w + n, cmp);
	for (int i = 0; i < n; i++)
		cout << w[i].idx << ' ';
	cout << '\n';
	for (int i = 0; i < n - 1; i++)
		ans += w[i].w * (n - 1 - i);
	cout << fixed << setprecision(2) << ans / n;
	return 0;
}
