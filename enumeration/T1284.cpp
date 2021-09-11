#include <iostream>
using namespace std;
int sum;

///ms为店，ns为花，ws为酒
void dfs(int ms,int ns,int ws)
{
	if (ms == 0 && ns == 0) { // 店和花都遇完了
		if (ws == 0)      // 恰好酒也喝完了
			sum++;
		return;
	} else {
		if(ws == 0)       // 花和店未遇完，酒却喝光了，跳出
			return;
	}

	if (ms > 0) {
		dfs(ms-1, ns, ws*2); // 遇店加一倍
	}

	if (ns > 0) {
		dfs(ms, ns-1, ws-1); // 遇花喝一斗
	}
}

int main(void)
{
	int m, n, w;
	cin >> m >> n;
	sum=0;
	dfs(m,n,2);
	cout << sum << endl;
	return 0;
}
