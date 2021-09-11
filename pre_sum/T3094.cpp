#include <iostream>

using namespace std;

int Mmax[100005] = {0, };
int Mmin[100005] = {0, };

int main(void)
{
	int n, q, mina, maxa;

	cin >> n >> q;
	mina = 0x7fffffff;
	maxa = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a > maxa)
			maxa = a;
		if (a < mina)
			mina = a;
		Mmax[i] = maxa;
		Mmin[i] = mina;
	}

	for (int i = 0; i < q; i++) {
		int q;
		cin >> q;
		cout << Mmax[q] - Mmin[q] << '\n';
	}
	return 0;
}
