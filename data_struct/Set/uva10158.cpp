/**
 * Circuit Nets UVA - 10158
 * https://vjudge.net/problem/UVA-10158
 *
 * 并查集。需要两个集合来描述朋友关系和敌对关系。
 * 朋友的朋友是朋友；敌人的敌人是朋友；朋友的敌人是敌人；敌人的朋友是敌人。
 * 也可能既不是朋友，也不是敌人。
 * 如果两人可以成为朋友，则分别合并朋友集和敌人集。
 * 如果两人可以成为敌人，则将朋友集和敌人集分别合并。
 *
 * @File:   uva10158.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-07
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 10007;
int friends[2 * N];  // 将敌人集跟在朋友集之后，这样便可以避免不同集合中出现同样的根序号

void initialize()
{
	for (int x = 0; x < 2*N; x++) {
		friends[x] = x;
	}
}

int find(int x)
{
	return x == friends[x] ? x : (friends[x] = find(friends[x]));
	//return x == p[x] ? x : find(p[x]);
}

int main(void)
{
	int n;
	int c, x, y;
	cin >> n;
	initialize();

	while (cin >> c >> x >> y) {
		if (!c && !x && !y)
			break;
		int fx, fy, ex, ey;
		// 查看两人所属的朋友集
		fx = find(x);
		fy = find(y);

		// 查看两人的敌人集
		ex = find(x + N);
		ey = find(y + N);

		if (c == 1) {
			if ((fx == ey) || (ex == fy))
				cout << "-1\n";
			else {
				friends[fx] = fy;
				friends[ex] = ey;
			}
		} else if (c == 2) {
			if ((fx == fy) || (ex == ey))
				cout << "-1\n";
			else {
				friends[ex] = fy;
				friends[fx] = ey;
			}
		} else if (c == 3) {
			if (fy == fx || ey == ex)
				cout << "1\n";
			else
				cout << "0\n";
		} else if (c == 4) {
			if (ey == fx || fy == ex)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}