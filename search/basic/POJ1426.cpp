#include <iostream>
#include <queue>

using namespace std;
#define LL long long
LL n;

void bfs(LL m)
{
	queue<LL> mq;

	while (mq.size())
		mq.pop();

	mq.push(m);
	while (mq.size()) {
		LL d = mq.front();
		mq.pop();
		if (d % n == 0) {
			cout << d << '\n';
			return;
		}
		mq.push(d * 10);
		mq.push(d * 10 + 1);
	}
}

int main(void)
{
	while (cin >> n && n != 0) {
		bfs(1);
	}
	return 0;
}
