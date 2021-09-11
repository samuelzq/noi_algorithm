#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int i,j,len,d,begin,maxx;
	string a;
	cin >> a;
	d = a.length();
	for(len=2; len<=d; len++)
	{
		maxx=d-len;
		for(begin=0; begin<=maxx; begin++)
		{
			j=begin+len-1;
			for(i=begin; i<j; i++,j--)
			{
				if(a[i]!=a[j])
					break;
			}
			if(i>=j)
			{
				j=begin+len-1;
				for(i=begin; i<=j; i++)
					cout << a[i];
				cout << "\n";
			}
		}
	}
	return 0;
}
