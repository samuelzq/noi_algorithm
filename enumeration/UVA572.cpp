// 使用广度优先算法，检测周围8个位置是否有1。如果有1便将其清除，
// 直到关联的1全部被清除为止。
// 为加快搜索速度，预先统计输入中1的总数和每行中1的总数。
#include <bits/stdc++.h>

using namespace std;

const int N = 102;
char oil[N][N];    // 图像数据
int tx[N];        // 每一行中有效像素的总数
int cnt = 0;      // 图像数据中有效像素的总数
int dd[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};
queue<pair<int, int>> mq;

void bfs(int x, int y)
{
	if (oil[x][y] != '@')
		return;

	oil[x][y] = '-';
	mq.push(pair<int, int>(x, y));
	while (!mq.empty()) {
		pair<int, int> pix = mq.front();
		mq.pop();
		for (int i = 0; i < 8; i++) {
			int nx, ny;
			nx = pix.first + dd[i][0];
			ny = pix.second + dd[i][1];
			if (oil[nx][ny] == '@') {
				oil[nx][ny] = '-';
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
	int x, y, ans;

	while (scanf("%d %d", &x, &y) != EOF && x && y) {
		char c;
		getchar();
		for (int i = 1; i <= x; i++) {
			int s = 0;
			for (int j = 1; j <= y; j++) {
				c = getchar();
				oil[i][j] = c;
				if (c == '@')
					s++;
			}
			tx[i] = s;
			cnt += s;
			getchar();
		}

		// 扫描每一个像素点以及与之相关联的像素
		ans = 0;
		for (int i = 1; i <= x && cnt; i++) {   // 总像素会递减，减少不必要的循环
			for (int j = 1; j <= y && tx[i]; j++) {  // 每行的统计同时也会减一
				if (oil[i][j] == '@') {
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
}