// 扫描线
#include <bits/stdc++.h>

using namespace std;

struct Circle{
	double x;
	double y;
	double r;
};

struct Range{
	int min;
	int max;
};

bool cmp(Range a, Range b) {
	return a.min < b.min || (a.min == b.min && a.max < b.max);
}

// 获取某一圆在指定扫描线上占据的范围
// 注：扫描线平行于X轴，沿Y轴移动
Range getxrange(Circle c, int y, int size)
{
	Range r;
	if (y + 1 < c.y && c.y - c.r <= y + 1) {
		// 圆心位于扫描线下方
		double dy = c.y - (y + 1);
		double dd = sqrt(c.r * c.r - dy * dy);

		r.min = max(0, (int)(c.x - dd));
		r.max = min(size - 1, (int)(c.x + dd));
		return r;
	} else if (y > c.y && c.y + c.r >= y) {
		// 圆心位于扫描线上方
		double dy = y - c.y;
		double dd = sqrt(c.r * c.r - dy * dy);

		r.min = max(0, (int)(c.x - dd));
		r.max = min(size - 1, (int)(c.x + dd));
		return r;
	} else if (c.y >= y && c.y <= y + 1) {
		// 圆心位于扫描线上
		r.min = max(0, (int)(c.x - c.r));
		r.max = min(size - 1, (int)(c.x + c.r));
		return r;
	} else {
		// 该圆于扫描线无交集
		r.min = -1;
		r.max = -1;
		return r;
	}
}

int main(void)
{
	int N;
	while (scanf("%d", &N) != EOF) {
		while (N--) {
			int size, n;
			scanf("%d%d", &size, &n);

			vector<Circle> circles;
			for (int i = 0; i < n ; i++) {
				Circle c;
				scanf("%lf%lf%lf", &(c.x), &(c.y), &(c.r));
				circles.push_back(c);
			}

			int ans = 0;
			for (int i = 0; i < size; i++) {
				// 延Y轴扫描，看每个圆在该扫描线上覆盖的范围
				vector<Range> ranges;
				for (int j = 0 ; j < n ; ++j) {
					Range range = getxrange(circles[j], i, size);
					if (range.min != -1 && range.max != -1)
						ranges.push_back(range);
				}

				// 对重复的空间进行压缩
				if (ranges.size() > 0) {
					sort(ranges.begin(), ranges.end(), cmp);
					Range range = ranges[0];
					for (int j = 1; j < ranges.size(); j++) {
						if (range.max >= ranges[j].min) {
							range.max = max(range.max, ranges[j].max);
						} else {
							ans += range.max - range.min + 1;
							range = ranges[j];
						}
					}
					ans += range.max - range.min + 1;
				}
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}