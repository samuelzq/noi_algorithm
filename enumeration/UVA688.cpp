// 切割矩形
// 将图中每个矩形切割成更小的矩形，之后再迭代每个小矩形。
// 如果该小矩形被某个大矩形包含则计算它的面积。
// 迭代每个小矩形需要O(n^2)的时间，判断该小矩形是否被大矩形覆盖
// 需要O(n)的的时间，因此总体时间复杂度O(n^3)。

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 105;
double rect[N][3] = {0};
double x[2*N], y[2*N] = {0};

int main()
{
	int n, seq = 1;
	while (scanf( "%d", &n ) != EOF && n != 0) {
		for ( int i = 0 ; i < n ; ++i ){
			scanf( "%lf%lf%lf", &rect[i][0], &rect[i][1], &rect[i][2] );
			x[i*2] = rect[i][0] - rect[i][2];
			x[i*2+1] = rect[i][0] + rect[i][2];
			y[i*2] = rect[i][1] - rect[i][2];
			y[i*2+1] = rect[i][1] + rect[i][2];
		}

		sort(x, x+2*n);
		sort(y, y+2*n);

		double sum = 0;
		for (int i = 0 ; i < 2*n-1 ; ++i) {
			for (int j = 0 ; j < 2*n-1; ++j) {
				for (int k = 0 ; k < n; ++k) {
					if (rect[k][0] - rect[k][2] <= x[i] && rect[k][0] + rect[k][2] >= x[i+1] &&
						rect[k][1] - rect[k][2] <= y[j] && rect[k][1] + rect[k][2] >= y[j+1] ){
						sum += (x[i+1]-x[i]) * (y[j+1]-y[j]);
						break;
					}
				}
			}
		}
		printf("%d %.2lf\n", seq++, sum);
	}
	return 0;
}