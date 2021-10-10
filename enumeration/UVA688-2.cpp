// sweeping line算法
// 1、首先将所有矩形的左右两条边坐标从小到大排列，得到xPoint[0..n]
// 2、然后求在xPoint[i]到xPoint[i + 1]之间的矩形，中间可能有相交的，可能没有，涉及到合并的问题
// 3、将求得的小矩形面积一个一个的叠加

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 110;
const double EPS = 1e-6;

// 每个信号塔所覆盖的矩形范围
struct Rect
{
	double x1;
	double x2;
	double y1;
	double y2;
};

// 每条扫描线扫到的有效区域
struct Line
{
	double y1, y2;
	bool operator < (const Line &other) const
	{
		if (fabs(y1 - other.y1) > EPS) {
			return y1 < other.y1;
		}

		return y2 < other.y2;
	}
};

Rect rect[N];
int n;
int cas = 1;

bool input()
{
	scanf("%d", &n);
	if (n == 0) return false;

	for (int i = 0; i < n; i++) {
		double x, y, r;
		scanf("%lf%lf%lf", &x, &y, &r);
		rect[i].x1 = x - r;
		rect[i].x2 = x + r;
		rect[i].y1 = y - r;
		rect[i].y2 = y + r;
	}

	return true;
}

// 输出每个扫描区间内部的所有不重叠矩形的高
vector<Line> checky(double x1, double x2)
{
	vector<Line> ans;

	// 首先将区间内的所有Y坐标入栈并排序
	for (int i = 0; i < n; i++) {
		if (rect[i].x1 - x1 < EPS && rect[i].x2 - x2 > -EPS) {
			Line tmp;
			tmp.y1 = rect[i].y1;
			tmp.y2 = rect[i].y2;
			ans.push_back(tmp);
		}
	}

	sort(ans.begin(), ans.end());

	double start = 0, end = 0;
	if (!ans.empty()) {
		start = ans[0].y1;
		end = ans[0].y2;
	}

	// 去除重叠和空白的区间
	vector<Line> result;

	for (size_t i = 1; i < ans.size(); i++) {
		if (ans[i].y1 - end < EPS) {
			// 合并重叠区间
			end = max(end, ans[i].y2);
		} else {
			// 跳过空白区间
			Line tmp;
			tmp.y1 = start;
			tmp.y2 = end;
			result.push_back(tmp);
			start = ans[i].y1;
			end = ans[i].y2;
		}
	}

	Line tmp;
	tmp.y1 = start;
	tmp.y2 = end;
	result.push_back(tmp);

	return result;
}

void solve()
{
	vector<double> vxPoint;

	// 将X坐标排序去重，生成将扫描区间
	for (int i = 0; i < n; i++) {
		vxPoint.push_back(rect[i].x1);
		vxPoint.push_back(rect[i].x2);
	}

	sort(vxPoint.begin(), vxPoint.end());

	vector<double>::iterator end = unique(vxPoint.begin(), vxPoint.end());
	vxPoint.erase(end, vxPoint.end());

	// 遍历每一个扫描区间
	double area = 0;
	for (size_t i = 0; i + 1 < vxPoint.size(); i++) {
		double x1 = vxPoint[i], x2 = vxPoint[i + 1];
		vector<Line> vyLine = checky(x1, x2);

		for (size_t j = 0; j < vyLine.size(); j++) {
			double y1 = vyLine[j].y1, y2 = vyLine[j].y2;
			area += (y2 - y1) * (x2 - x1);
		}
	}

	printf("%d %.2f\n", cas++, area);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d:\\OJ\\uva_in.txt", "r", stdin);
#endif

	while (input()) {
		solve();
	}

	return 0;
}