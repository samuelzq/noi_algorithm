#include <iostream>
#include <iomanip>

using namespace std;

const int maxn    = 9999;
const int maxsize = 10024;

int ans[maxsize] = {0, };
int a[maxsize] = {1, };

int bmultiply(int a[], int b, int len)
{
	int up, te, tee, i;
	up = 0;
	for (i = 0; i < len; i++) {
		te = b * a[i] + up;
		up = te / (maxn + 1);
		a[i] = te - up * (maxn + 1);
	}
	if (up) {
		a[i] = up;
		return len + 1;
	} else {
		return len;
	}
}

int madd(int a[], int la, int b[], int lb)
{
	int up, te, tee, i, l;
	l = la > lb ? la : lb;
	up = 0;
	for (i = 0; i < l; i++) {
		te = a[i] + b[i] + up;
		up = te / (maxn + 1);
		a[i] = te - up * (maxn + 1);
	}
	if (up) {
		a[i] = up;
		return l + 1;
	} else {
		return l;
	}
}

int main(void)
{
	int n, la, lb;

	cin >> n;

	la = 1;
	lb = 1;
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		lb = bmultiply(a, i, lb);
		la = madd(ans, la, a, lb);
	}

	cout << ans[la - 1];
	for (int i = la - 2; i >=0; i--)
		cout << setw(4) << setfill('0') << ans[i];
	return 0;
}
