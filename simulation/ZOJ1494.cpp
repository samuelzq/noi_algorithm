
#include <iostream>

using namespace std;

int main(void)
{
	int n = 0, u = 0, d = 0;
	while (cin >> n >> u >> d && n != 0) {
		int time = 0, dist = 0;
		while (true) {
			dist += u;
			time++;
			if (dist >= n)
				break;
			dist -= d;
			time++;
		}
		cout << time << '\n';
	}
	return 0;
}
