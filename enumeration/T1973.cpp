#include <iostream>
#include <algorithm>

using namespace std;
int a[5];

int main(void)
{
	int tag = 0, last = 56789;

	cin >> a[1] >> a[2] >> a[3] >>a[4];

	sort(a+1,a+4);//先对输入的数排序 

	do{
		int d = a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
		if (a[1] == 0 || last == d)
			continue;
		last = d;
		if (tag)
			cout << ' ';
		else
			tag = 1;
		cout << d;
	} while (next_permutation(a + 1, a + 5));
	return 0;
}
