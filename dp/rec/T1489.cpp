#include <iostream>

using namespace std;

const int N = 2e6+6;
int l[N] = {0};

int main(void)
{
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			l[j] ^= 1;
		} 
	}
	for (int i = 1; i <= n; i++)
		cout << l[i];
	return 0;
}