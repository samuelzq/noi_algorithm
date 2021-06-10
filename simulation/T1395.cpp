// 如果奇数不同，则无解
// 统计两个不同字符的距离

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int i, j, n, ans;
	string str1, str2;

	cin >> str1 >> str2;
	i = j = 0;
	n = 0;
	ans = 0;
	for (string::iterator it1 = str1.begin(), it2 = str2.begin();
			it1 < str1.end() && it2 < str2.end();
			it1++, it2++) {
		n++;
		if (*it1 != *it2) {
			if (i == 0) {
				i = n;
			} else {
				j = n;
				ans += j - i;
				j = i = 0;
			}
		}
	}
	if (i)
		cout << "No Answer.";
	else
		cout << ans;
	return 0;
}
