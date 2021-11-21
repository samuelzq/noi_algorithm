// 使用广度优先算法，检测周围8个位置是否有1。如果有1便将其清除，
// 直到关联的1全部被清除为止。
// 为加快搜索速度，预先统计输入中1的总数和每行中1的总数。
#include <bits/stdc++.h>

using namespace std;

const int N = 27;
int war[N][N];    // 图像数据
int tx[N];        // 每一行中有效像素的总数
int cnt = 0;      // 图像数据中有效像素的总数
int dd[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};
queue<pair<int, int>> mq;

void bfs(int x, int y)
{
	if (war[x][y] != 1)
		return;

	war[x][y] = 2;
	mq.push(pair<int, int>(x, y));
	while (!mq.empty()) {
		pair<int, int> pix = mq.front();
		mq.pop();
		for (int i = 0; i < 8; i++) {
			int nx, ny;
			nx = pix.first + dd[i][0];
			ny = pix.second + dd[i][1];
			if (war[nx][ny] == 1) {
				war[nx][ny] = 2;
				mq.push(pair<int, int>(nx, ny));
			}
		}
		// 清除一个像素
		cnt--;
		tx[pix.first]--;
	}
}

int main(void)
{
	int n, ans, kase;

	kase = 1;
	while (scanf("%d", &n) != EOF) {
		char c;
		getchar();
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int j = 1; j <= n; j++) {
				c = getchar();
				war[i][j] = c - '0';
				s = s + (c - '0');
			}
			tx[i] = s;
			cnt += s;
			getchar();
		}

		// 扫描每一个像素点以及与之相关联的像素
		ans = 0;
		for (int i = 1; i <= n && cnt; i++) {   // 总像素会递减，减少不必要的循环
			for (int j = 1; j <= n && tx[i]; j++) {  // 每行的统计同时也会减一
				if (war[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", kase++, ans);
	}
}