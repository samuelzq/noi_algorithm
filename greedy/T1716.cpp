#include <iostream>
#include <algorithm>

using namespace std;
int a[25005], b[25005];

int main(void)
{
	int n, x, y;
	int sum = 0;
	cin >> n >> x >> y;
	for(int i=0; i<n; i++)
		cin >> a[i] >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0; i<n; i++) {
		if(a[i] < b[i])
			sum += (b[i]-a[i]) * x;
		else
			sum += (a[i]-b[i]) * y; 
	}
	cout << sum;
	return 0;
}
