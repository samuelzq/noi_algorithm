// 依次统计每个人需要交换的次数

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cout << n * (n - 1) / 2;
	return 0;
}
