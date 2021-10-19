#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
#if 0
int f[N];
int a[N];

int main(void)
{
	int n, k, p, i, j;

	scanf("%d %d", &n, &k);

	k++;
	j = 0;
	i = 0;
	for (int i = 0; i < n; i++) {
		f[n]=i+1;
		int j=n-1;
		for(; j >= 0 && f[n] != k && f[j + 1]; j--)
			f[j] = (f[j + 1] + j + 1 - k) % (j + 1);
		a[max(n - j - 1, 1)] = i + 1;
		cout<<"第"<<i+1<<"个人，第  "<<' '<<max(n-j-1,1)<<" 次 出队列"<<endl;
	}

	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
#else
#include <iostream>

using namespace std;
bool que[N]; // 保存此编号是否在队中
int up[N]; // 此编号人员的上一个人员的编号
int down[N]; // 此编号人员的下一个人员的编号

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	m++;

	// 初始化
	for (int i = 1; i <= n; i++) {
		que[i] = true;
		up[i] = i - 1;
		down[i] = i + 1;
	}
	up[1] = n; // 跳到队尾
	down[n] = 1; // 跳到队首

	int cnt = 0; // 当前报号
	int pos = 1; // 当前位置
	int inQue = n; // 在队中的人数
	while (inQue > 0) {
		if (++cnt == m) {
			if (inQue == n)
				printf("%d", pos);
			else
				printf(" %d", pos);
			inQue--;
			cnt = 0;
			up[down[pos]] = up[pos]; // 更新此编号的上一个人员
			down[up[pos]] = down[pos]; // 更新此编号的下一个人员
		}

		pos = down[pos]; // 跳到下一个位置
	}
	printf("\n");

	return 0;
}
#endif
