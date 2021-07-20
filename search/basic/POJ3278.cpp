#include <iostream>
#include <queue>

using namespace std;
const int N = 2e5+10;
bool v[N] = {0};
int  t[N] = {0};

int n, k;

bool ok(int x, int t)
{
	if (x * 2 == k || x - 1 == k || x + 1 == k) {
		cout << t + 1;
		return true;
	} else
		return false;
}

void bfs(int x)
{
	queue<int> mq;
	if (!mq.empty())
		mq.pop();

	mq.push(x);
	v[x] = 1;
	t[x] = 0;
	while (mq.size()) {
		int x, d = mq.front();
		mq.pop();
		if (d == k) {
			cout << t[d];
			return;
		}
		x = d + 1;
		if (x >= 0 && x <= 100000 && !v[x]) {
			v[x] = 1;
			t[x] = t[d] + 1;
			mq.push(x);
		}
		x = d - 1;
		if (x >= 0 && x <= 100000 && !v[x]) {
			v[x] = 1;
			t[x] = t[d] + 1;
			mq.push(x);
		}
		x = d * 2;
		if (x >= 0 && x <= 100000 && !v[x]) {
			v[x] = 1;
			t[x] = t[d] + 1;
			mq.push(x);
		}
	}
}

int main(void)
{
	cin >> n >> k;
	bfs(n);
	return 0;
}
