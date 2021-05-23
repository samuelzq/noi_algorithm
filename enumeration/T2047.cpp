#include <iostream>
#include <cmath>

using namespace std;

const int maxn = 1e5+5;
long long a[maxn];

int main(void)
{
	long long n, minn, x;
	long long m, p1 , s1, s2;
	long long sum1=0;
	long long sum2=0;

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin>>a[i];

	cin >> m >> p1 >> s1 >> s2;
	a[p1] += s1;

	for (int i = 1; i <= m - 1; i++)
		sum1 += a[i] * (m - i);
	
	for (int i = m + 1; i <= n; i++)
		sum2 += a[i] * (i - m);

	minn = abs(sum1 - sum2);
	x = m; //即便是小于也有可能派出去使得双方悬殊变大,刚开始派到中立派
	if (sum1 < sum2) {//增加sum1;  
		for(int i = 1; i <= m - 1; i++){
			long long temp = sum1 + s2 * abs(i - m);
			if (abs(temp - sum2) < minn) {
				minn = abs(temp - sum2);
				x=i;
			}
		}
	} else if (sum1 > sum2) {//增加sum2
		for (int i = m + 1; i <= n; i++){
			long long temp = sum2 + s2 * abs(i - m);
			if (abs(temp - sum1) < minn) {
				minn = abs(temp - sum1);
				x=i;
			}
		}
	} else
		x=m;

	cout<<x<<endl;
	return 0;
}
