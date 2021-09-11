#include <iostream>

using namespace std;

int main()
{
	int k, m;
	cin >> k;
	m = k;
	while (1) {
		int i, t, num;
		num = 0;  //人的编码从0~2k-1，取余会出现为0的情况
		m++;
		for (i = 0; i < k; i++) {
			t = (num + m - 1) % (2 * k - i);   //最大编号为2k-1，需要取2k的余，否则2k-1==0
			if (t < k)
				break;
			num = t;
		}
		if (i == k)
			break;        //n个坏人已经全部被杀死 
	}
	cout << m << endl;
	return 0;
}
