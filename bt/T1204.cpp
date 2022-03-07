/**
 * https://nanti.jisuanke.com/t/T1204
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1204
 *
 * @File:   T1204.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;

char num[7];
bool visit[7];
char ans[7];
int len = 0;

void perm(int k)
{
	if (k == len)
		printf("%s\n", ans);

	for (int i = 0; i < len; i++){
		if (!visit[i]) {
			visit[i] = true;
			ans[k] = num[i];
			perm(k + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	scanf("%s", num);
	len = strlen(num);
	memset(ans,0,sizeof(ans));
	memset(visit,0,sizeof(visit));
	perm(0);
	return 0;
}
