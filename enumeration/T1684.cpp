#include <iostream>
#include <cstdlib>

using namespace std;

int f[15], b[15], n, minx = 0x7fffffff;

void dfs(int in, int vf, int vb)
{
	if (abs(vf - vb) < minx)
		minx = abs(vf - vb);
	if (in >= n)
		return;

	dfs(in + 1, vf * f[in], vb + b[in]);   // 选择输入递归
	dfs(in + 1, vf, vb);                   // 抛弃输入递归
	return;
}

int main(void)
{
	cin>>n;
	for (int i = 0; i < n; i++)
		cin >> f[i] >> b[i];

	for (int i = 0; i < n; i++)
		dfs(i+1, f[i], b[i]);  //  依次递归

	cout << minx;
	return 0;
}
