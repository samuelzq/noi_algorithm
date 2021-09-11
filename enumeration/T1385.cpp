#include <iostream>

using namespace std;

int main(void)
{
	float x;
	int c, ans = 3;


	cin >> x;
	c = 10 * x;       // 浮点数除法和判断操作存在误差

	if (c <= 5)
		goto exit;

	c -= 5;
	ans += c / 2;

exit:
	cout << ans << endl;
	return 0;
}
