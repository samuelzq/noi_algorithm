#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int N,M;
int tile[20][20];
int turn[20][20];  //翻转情况
int ans[20][20];
int direct[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int solve(void)
{
	int ret = 0;
	int flag = 0;
	int New[20][20];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			New[i][j] = tile[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i != 1 && New[i-1][j] == 1)
				turn[i][j] = 1;

			if (turn[i][j] == 1) {
				ret++;
				New[i][j] ^= 1;
				for (int k = 0; k < 4; k++) {
					int tempx = i + direct[k][0];
					int tempy = j + direct[k][1];
					New[tempx][tempy] ^= 1;     // 翻转
				}
			}
		}
	}

	for (int i = 1; i <= M; i++)
		if (New[N][i] != 0) {
			flag = 1;
			break;
		}

	if (!flag)
		return ret;
	else
		return -1;
}

void copy_toans(void)
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			ans[i][j] = turn[i][j];
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> tile[i][j];

	int t = 0;
	int ans_min = 0xfffffff;
	for (int i = 0; i < (1 << M); i++){    //二进制枚举
		memset(turn, 0, sizeof(turn));
		for (int j = 0; j < M; j++)
			if (i & (1 << j))
				turn[1][j + 1] = 1;

		int temp = solve();
		if (solve() !=-1){
			t = 1;
			if (temp < ans_min){
				copy_toans();
				ans_min = temp;
			}
		}
	}
	if(t){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++)
				cout << ans[i][j] << ' ';
			cout << '\n';
		}
	}
	else
		cout << "IMPOSSIBLE\n";
	return 0;
}
