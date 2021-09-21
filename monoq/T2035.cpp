// 开三个队列，
// 第一个存没有被切过的蚯蚓，
// 第二个存被切出来的长度为floor（px）的蚯蚓，
// 第三个存长度为x-floor（px）的蚯蚓。
// 之后在每次取值的时候取三个队列的最大值即可。
// 注意始终要维护一个全局变量（随时间递增的）以记录蚯蚓一共长了多少，因为我们不能每次都给所有蚯蚓加长度。
// 然后每次在取最大值的时候需要加上这个偏移量，因为你不能对负数向下取整……之后把计算之后的长度值减去偏移量再压入队列。

#include <bits/stdc++.h>

using namespace std;

const int M = 100005;
const long long INF = 10000000000000000;

long long a[M],x,y,z,maxn,pos;
queue<long long> q[5];

long long read(void)
{
	long long ans = 0,op = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')	{
		if(ch == '-') op = -1;
		ch = getchar();
	}

	while(ch >= '0' && ch <= '9') {
		ans *= 10;
		ans += ch - '0';
		ch = getchar();
	}
	return ans * op;
}

bool cmp(long long x,long long y)
{
    return x > y;
}

int main()
{
	long long n, m, Q, u, v, t, add;
    n = read(),m = read(),Q = read(),u = read(),v = read(),t = read();
	add = 0;

	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n, cmp);

	for (int i = 1; i <= n; i++)
		q[1].push(a[i]);//按从大到小压入队列

	for (int i = 1; i <= m; i++) {
        maxn = -INF;
		for (int j = 1; j <= 3; j++) {
            if (q[j].empty())
				continue;
            if (q[j].front() > maxn) {
				maxn = q[j].front();
				pos = j;
			}
        }//寻找最大元素
        q[pos].pop();//把元素删了（蚯蚓切了）
        long long now = maxn + add;
        if (!(i % t))
			printf("%lld ", now);//符合要求就输出
        long long cur1 = now * u / v,cur2 = now - cur1;
        add += Q;
		// 计算结束后压入队列
		// 由于q1的内容已经排序，所以此处数据按大小顺序入q2和q3
        q[2].push(cur1 - add);
		q[3].push(cur2 - add);
    }
    putchar('\n');
	for (int i = 1; i <= n + m; i++) {
        maxn = -INF;
		pos = 0;
        for (int j = 1; j <= 3; j++) {
            if(q[j].empty())
				continue;
            if (q[j].front() > maxn) {
				maxn = q[j].front();
				pos = j;
			}
        }
        if (!(i % t))
			printf("%lld ", maxn + add);
        q[pos].pop();//和上面操作基本一样
    }
    return 0;
}