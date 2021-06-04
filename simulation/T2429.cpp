#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int pid;
	int atime;
	int rtime;
	int endtime;
	int pri;
} PR;

PR stk[150000];
int depth = 0;

PR *pop_proc(void)
{
	if (!depth)
		return NULL;
	else
		depth--;
	return &stk[dep - 1];
}

int main(void)
{
	PR cp, wp, tp;

	while (cin >> cp.pid >> cp.atime >> cp.rtime >> cp.pri) {
		if (depth) {
			wp = stk[dep - 1];
			if (wp.pri >= cp.pri) {
				tp = wp;
				wp = cp;
				cp = tp;
			}
		}
	}
}
