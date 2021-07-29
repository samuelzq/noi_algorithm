#include <iostream>
#include <cstring>

using namespace std;

int const N=21;
int const WB=15001;
int const MID=7500;
int loc[N];
int wgh[N];
int state[N][WB];

int main(void)
{
	int i, j, k, C, G, pw;
	memset(state,0,sizeof(state));

	cin >> C >> G;
	for (i = 0; i < C; i++)
		cin >> loc[i];
	for (i = 0; i < G; i++)
		cin >> wgh[i];
	for (i = 0; i < C; i++)
		state[0][MID + wgh[0] * loc[i]] = 1;

	for (i = 1; i < G; i++) {
		for(j = 0; j < C; j++) {
			for (k = 0; k <= WB; k++) {
				if ((pw = k - wgh[i] * loc[j]) < 0)
					continue;
				if (state[i - 1][pw])
					state[i][k] += state[i - 1][pw];
			}
		}
	}
	cout << state[G - 1][MID] << endl;
	return 0;
}
