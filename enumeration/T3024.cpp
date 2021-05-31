#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
	int n, l;
	int i, j, g;
	string str;

	cin >> n;
	cin >> str;

	// 遍历所有窗口
	for (g = 1; g < n - 1; g++) {
		bool f = true;
		l = n - 1;
		// 依据窗口大小遍历所有子串
		for (i = 0; i < l; i++) {
			for (j = i + 1; j <= n - g; j++) {
				if (!memcmp(&str[i], &str[j], g)) {
					f = false;
					break;
				}
			}

			// 当前窗口大小不能够满足要求，检查下一个大小
			if (f != true)
				break;
		}
		if (f == true) {
			break;
		}
	}
	cout << g;
	return 0;
}
