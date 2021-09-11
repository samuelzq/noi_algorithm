#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int a;
	int digt;
} DIGIT;

DIGIT ddd[10];

bool cmp(DIGIT d1, DIGIT d2)
{
	if (d1.a == d2.a)
		return d1.digt > d2.digt;
	return d1.a < d2.a;
}

int main(void)
{
	int v, n, r;

	cin >> v;

	for (int i = 0; i < 9; i++) {
		cin >> ddd[i].a;
		ddd[i].digt = i + 1;
	}

	sort(&ddd[0], &ddd[9], cmp);
	if (v == 0 || v < ddd[0].a)
		goto fail;

	r = v % ddd[0].a;
	if (!r) {
		while (v) {
			cout << ddd[0].digt;
			v -= ddd[0].a;
		}
		return 0;
	}

	n = v / ddd[0].a;
	do {
		n--;
		r += ddd[0].a;
		for (int i = 1; i < 9; i++) {
			if (r % ddd[i].a == 0 && r / ddd[i].a == i) {
				while (r) {
					cout << ddd[i].digt;
					r -= ddd[i].a;
				}
				for (int j = 0; j < n; j++)
					cout << ddd[0].digt;
				return 0;
			}
		}
	} while(r < v);
	for (int j = 0; j < v / ddd[0].a; j++)
		cout << ddd[0].digt;
	return 0;
fail:
	cout << -1;
	return 0;
}
