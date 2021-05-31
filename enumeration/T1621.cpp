#include <iostream>

using namespace std;

const int wn[] = {123, 147, 456, 258, 789, 369, 159, 357};
int sbit[10] = {0,};
int hbit[10] = {0,};

int main(void)
{
	int l = 0, t;
	long long n;

	cin >> n;

	while (n) {
		int d = n % 10;

		if (l % 2 == 0)
			sbit[d] = 1;
		else
			hbit[d] = 1;
		n /= 10;
		l++;
	}

	// 长度偶数，sbit中记录的是算头君的落子位置
	for (int i = 0; i < 8; i++) {
		if (sbit[i] == 0)
			continue;
		for (int j = i + 1; j < 9; j++) {
			if (sbit[j] == 0)
				continue;
			for (int k = j + 1; k < 10; k++) {
				if (sbit[k] == 0)
					continue;
				t = i * 100 + j * 10 + k;

				for (int p = 0; p < 8; p ++) {
					if (t == wn[p]) {
						if (l % 2 == 0)
							goto s_win;
						else
							goto h_win;
					}
				}
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		if (hbit[i] == 0)
			continue;
		for (int j = i + 1; j < 9; j++) {
			if (hbit[j] == 0)
				continue;
			for (int k = j + 1; k < 10; k++) {
				if (hbit[k] == 0)
					continue;
				t = i * 100 + j * 10 + k;

				for (int p = 0; p < 8; p ++) {
					if (t == wn[p]) {
						if (l % 2 == 0)
							goto h_win;
						else
							goto s_win;
					}
				}
			}
		}
	}
	cout << "drew." << endl;
	return 0;
s_win:
	cout << "suantou wins." << endl;
	return 0;
h_win:
	cout << "huaye wins." << endl;
	return 0;
}
