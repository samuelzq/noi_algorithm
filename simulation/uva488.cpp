/**
 * https://vjudge.net/problem/UVA-488
 *
 * @File:   uva488.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2023-09-01
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	int a, f;
	
	//freopen("UVA488.out", "w", stdout);
	cin >> n;
	
	while (n-- > 0) {
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
			if (n)
				cout << "\n";
			else if (f)
				cout << "\n";
		}
	}

	//fclose(stdout);
	return 0;
}