#include <cstdlib>
#include <cstdio>

using namespace std;
int main(void)
{
	int h1, m1, s1;
	int h2, m2, s2, t;

	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);

	t = (h1 - h2) * 60 * 60 + (m1 - m2) * 60 + (s1 - s2);
	printf("%d", t);
	return 0;
}
