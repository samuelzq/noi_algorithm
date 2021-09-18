#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
unsigned int num[10000];
unsigned int isprime[10000] = {0};

int n1, n2, k;
void solve(void);
int bfs(void);

void is_prime(int n)
{
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) {
			for (int j = i * i; j <= n; j += i)
				isprime[j] = 1;
		}
	}//打表
}

int bfs(void)
{
	typedef pair<int, int> Pair;
	memset(num, -1, sizeof(num));
	queue<Pair> q;
	num[n1] = 0;
	q.push(Pair(n1, 0));
	while (!q.empty()) {
		Pair p = q.front();
		q.pop();
		if (p.first == n2)
			continue;
		for (int i = 0; i <= 9; i++) {
			int newNum = p.first;
			int pace = p.second;

			int num1 = (newNum / 10) * 10 + i; // 仅改变个位 1234
			if (num[num1] > pace + 1 && !isprime[num1]) {
				q.push(make_pair(num1, pace + 1));
				num[num1] = pace + 1;
			}

			int num2 = (newNum % 10 + newNum /  100 * 100 + i * 10); // 仅改变十位
			if (num[num2] > pace + 1 && !isprime[num2]) {
				q.push(make_pair(num2, pace + 1));
				num[num2] = pace + 1;
			}

			int num3 = (newNum % 100 + newNum / 1000 * 1000 + i * 100); // 仅改变百位
			if (num[num3] > pace + 1 && !isprime[num3]) {
				q.push(make_pair(num3, pace + 1));
				num[num3] = pace + 1;
			}

			if (i != 0) {
				int num4 = (newNum % 1000 + i * 1000);
				if (num[num4] > pace + 1 && !isprime[num4]) {
					q.push(make_pair(num4, pace + 1));
					num[num4] = pace + 1;
				}
			} // 仅改变千位,并阻止前导0出现
		}
    }
    return num[n2];
}

void solve(void)
{
	int pace = bfs();

	if (pace == 10000)
		cout << "Impossible\n";
	else
		cout << pace << '\n';
}

int main(void)
{
	is_prime(10000);
	cin >> k;
	while (k--) {
		cin >> n1 >> n2;
		solve();
	}
	return 0;
}
