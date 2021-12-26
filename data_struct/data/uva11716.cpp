#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;
	char c;

	cin >> t;
	cin.get(c);
	while (t--) {
		int s, l;
		string cy;
		getline(cin, cy);
		l = cy.length();
		s = sqrt(l);
		if (s * s != l) {
			cout << "INVALID\n";
			continue;
		}
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				cout << cy[j * s + i];
		cout << '\n';
	}
	return 0;
}