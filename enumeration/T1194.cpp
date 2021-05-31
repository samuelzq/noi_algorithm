#include <iostream>

using namespace std;

const int P = 23; // 体力周期
const int E = 28; // 情绪周期
const int I = 33; // 智商周期
int main(void)
{
	unsigned int p, e, i, d, det;

	cin >> p >> e >> i >> d;
	i = d - i;
	e = d - e;
	p = d - p;
	det = 0;
	while ((i % I) != 0 || (e % E) != 0 || (p % P) != 0) {
		i++;
		e++;
		p++;
		det++;
	}
	cout << det;
	return 0;
}
