#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	int a, f;

	//freopen("UVA488.out", "w", stdout);
	cin >> n;

	while (n-- > 1) {
		cin >> a >> f;

		while (f--) {
			int i;
			for (i = 1; i <= a; i++) {
				for (int j = 0; j < i; j++)
					cout << i;
				cout << '\n';
			}

			for (i = a - 1; i > 0; i--) {
				for (int j = 0; j < i; j++)
					cout << i;
				cout << '\n';
			}
			cout << "\n";
		}
	}
	cin >> a >> f;
	while (f-- > 1) {
		int i;
		for (i = 1; i <= a; i++) {
			for (int j = 0; j < i; j++)
				cout << i;
			cout << '\n';
		}

		for (i = a - 1; i > 0; i--) {
			for (int j = 0; j < i; j++)
				cout << i;
			cout << '\n';
		}
		cout << "\n";
	}
	int i;
	for (i = 1; i <= a; i++) {
		for (int j = 0; j < i; j++)
			cout << i;
		cout << '\n';
	}

	for (i = a - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)
			cout << i;
		cout << '\n';
	};
	//fclose(stdout);
	return 0;
}