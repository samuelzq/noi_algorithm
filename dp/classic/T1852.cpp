#include <bits/stdc++.h>

using namespace std;
const int N = 10005;
struct thing{
	int id;        //
	int len;       //
	int th[110];   //所需要的准备工作
} st[N];
int ans, t[N];

int main(void)
{
	int n, tot=1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int j,t,x;
		cin >> st[i].id >> st[i].len >> st[i].th[tot];
		while (st[i].th[tot] != 0)
			cin >> st[i].th[++tot];
		tot=1;
	}

	//以下为核心代码
	for (int i = 1; i <= n; i++) {
		if (st[i].th[1]==0)
			t[i]=st[i].len;
		else
			break;
	}

	for (int i = 1; i <= n; i++) {
		if(!t[i]) {
			int j=0;
			while (st[i].th[++j]!=0)
				t[i] = max(t[i], t[st[i].th[j]] + st[i].len);
		}
	}
	//以上为核心代码

	for (int i = 1; i <= n; i++)
		ans=max(ans,t[i]);
	cout<<ans;
	return 0;
}

