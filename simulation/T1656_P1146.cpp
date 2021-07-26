// 每次翻n-1个硬币，相当于每次翻一枚，所以一共需要n次。
//
// 题目中明确说明n为偶数，那么也就是说如果每个硬币翻n-1次，
// 就等同与每个硬币翻了一次，所以翻硬币的方案就是：
//     选中每一枚硬币，翻一下除了这枚硬币之外的其他硬币。
#include <iostream>

using namespace std;

int b[101] = {0, };
int main(void)
{
	int n;

	cin >> n;
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j)
				b[j] ^= 1;
			cout << b[j];
		}
		cout << '\n';
	}
	return 0;
}
