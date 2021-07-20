#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
struct node {
	int a, b, step;
	string opt;
	node(int a, int b, string opt, int step): a(a), b(b), opt(opt), step(step){}
};

int a, b, c, vis[105][105];

string bfs(void)
{
	queue<node> q;
	
	q.push(node(0, 0, "", 0));
	vis[0][0] = 1; //表示a为0 b也为0
	while (q.size()) {
		node t = q.front();
		q.pop();
		if (t.a == c || t.b == c) {
			cout << t.step << endl;
			return t.opt;
		}
		//3种操作
		//第一种操作Fill
		if (!vis[a][t.b]) {
			//将a装满
			vis[a][t.b] = 1;
			q.push(node(a, t.b, t.opt + "FILL(1)\n", t.step + 1));
		}
		if (!vis[t.a][b]) {
			//将b装满
			vis[t.a][b] = 1;
			q.push(node(t.a, b, t.opt + "FILL(2)\n", t.step + 1));
		}
		//第二种操作将a空 或者将b空
		if (t.a != 0 && !vis[0][t.b]) {
			vis[0][t.b] = 1;
			q.push(node(0, t.b, t.opt + "DROP(1)\n", t.step + 1));
		}
		if (t.b != 0 && !vis[t.a][0]) {
			vis[t.a][0] = 1;
			q.push(node(t.a, 0, t.opt + "DROP(2)\n", t.step + 1));
		}
		//第三种操作 将i to j
		if (t.a != 0 && t.b != b) {
			int cha = b - t.b;
			if (cha >= t.a) {
				//将a全部导入b
				if (!vis[0][t.b + t.a]) {
					vis[0][t.b + t.a] = 1;
					q.push(node(0, t.b + t.a, t.opt + "POUR(1,2)\n", t.step + 1));
				}
			} else {
				if (!vis[t.a - cha][b]) {
					vis[t.a - cha][b] = 1;
					q.push(node(t.a - cha, b, t.opt + "POUR(1,2)\n", t.step + 1));
				}
			}
		}
		if (t.b != 0 && t.a != a) {
			int cha = a - t.a;
			if (cha >= t.b) {
				// 将b全部导入a
				if (!vis[t.a + t.b][0]) {
					vis[t.a + t.b][0] = 1;
					q.push(node(t.a + t.b, 0, t.opt + "POUR(2,1)\n", t.step + 1));
				}
			} else {
				if (!vis[a][t.b - cha]) {
					vis[a][t.b - cha] = 1;
					q.push(node(a, t.b - cha, t.opt + "POUR(2,1)\n", t.step + 1));
				}
			}
		}
	}
	return "impossible";
}

int main(void)
{
	scanf("%d%d%d", &a, &b, &c);
	cout << bfs();
	return 0; 
}
