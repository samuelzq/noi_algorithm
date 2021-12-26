#include <cstdio>
#include <cstring>

const int N = 22;
char gmap[2][N][N];
char spl[] = "********************";
int adj[8][2] = {
	{-1, -1}, {-1, 0}, {0, -1}, {1, -1},
	{1, 1}, {1, 0}, {0, 1}, {-1, 1}
};

void go(int x, int y, char map1[N][N], char map2[N][N])
{
	int n = 0;

	for (int i = 0; i < 8; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (map2[xx][yy] == 'O')
			n += 1;
	}

	if (map2[x][y] == 'O') {
		if (n >= 4 || n <= 1)
			map1[x][y] = ' ';
		else
			map1[x][y] = 'O';
	} else {
		if (n == 3)
			map1[x][y] = 'O';
		else
			map1[x][y] = ' ';
	}
}

int main(void)
{
	int k;
	char buf[256];
	scanf("%d", &k);
	getchar();
	gets(buf);

	while (k--) {
		int y;
		gets(buf);
		sscanf(buf, "%d", &y);
		memset(gmap, ' ', sizeof(gmap));
		while (gets(buf) && buf[0]) {
			int x, y;
			sscanf(buf, "%d%d", &x, &y);
			gmap[0][x-1][y-1] = 'O';
		}

		for (int i = 0; i < y; i++) {
			printf("%s\n", spl);
			for (int j = 0; j < 20; j++) {
				for (int k = 0; k < 20; k++) {
					printf("%c", gmap[i & 1][j][k]);
					go(j, k, gmap[(i + 1) & 1], gmap[i & 1]);
				}
				printf("\n");
			}
		}
		printf("%s\n", spl);
		if (k>=1)
			printf("\n");
	}
}