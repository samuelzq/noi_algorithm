#include<iostream>
#include<algorithm>

using namespace std;
int n,m,d;
int v[40001][5]={0};
int num[15001]={0};
int data[40001];

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> data[i];
		num[data[i]]++;
	}
	for (int w = 1; w * 9 < n; w++)
	{
		int sum = 0;
		int a, b, c, d;
		for (d = w * 9 + 2; d <= n; d++)
		{
			a = d - 9 * w - 1;
			b = d - 7 * w - 1;
			c = d - w;
			sum += num[b] * num[a];
			v[c][3] += num[d] * sum;
 			v[d][4] += num[c] * sum;
		}
		sum = 0;
		for (a = n - w * 9 - 1; a >= 1; a--) {
			b = a + 2 * w;
			c = a + w * 8 + 1;
			d = a + w * 9 + 1;
			sum += num[c] * num[d];
			v[a][1] += num[b] * sum;
			v[b][2] += num[a] * sum;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << v[data[i]][1] << ' ' << v[data[i]][2] << ' ' << v[data[i]][3] << ' ' << v[data[i]][4] << '\n';
	return 0;
}
