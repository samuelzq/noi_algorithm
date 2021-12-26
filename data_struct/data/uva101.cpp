/**
 * The Blocks Problem UVA - 101
 * https://vjudge.net/problem/UVA-101
 *
 * 使用n个deque模拟。需要实时记录每个block当前的位置。
 *
 * @File:   uva12100.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-26
 *
 **/

#include <bits/stdc++.h>

using namespace std;
enum ops {
	move_onto = 1,
	move_over,
	pile_onto,
	pile_over,
	quit
};
const int N = 25;
vector<deque<int>> blocks;
int block_p[N];
char cmd[256];

enum ops get_ops(char *opstr, int &a, int &b)
{
	if (strlen(opstr) > 4) {
		char op1[5], op2[5];
		sscanf(opstr, "%s %d %s %d", op1, &a, op2, &b);
		if (!strncmp("move", op1, 4)) {
			if (!strncmp("onto", op2, 4))
				return move_onto;
			else
				return move_over;
		} else {
			if (!strncmp("onto", op2, 4))
				return pile_onto;
			else
				return pile_over;
		}
	} else {
		return quit;
	}
}

void output(int n)
{
	for (int i = 0; i < n; i++) {
		deque<int> tmp = blocks[i];
		cout << i << ":";
		while (!tmp.empty()) {
			cout << ' ' << tmp.front();
			tmp.pop_front();
		}
		cout << '\n';
	}
}

void op_move_onto(int a, int b)
{
	if (block_p[a] != block_p[b]) {
		deque<int> *tmp = &blocks[block_p[a]];

		while (!tmp->empty() && tmp->back() != a) {
			int t = tmp->back();
			tmp->pop_back();
			blocks[t].push_back(t);
			block_p[t] = t;
		}
		tmp->pop_back();
		tmp = &blocks[block_p[b]];
		while (!tmp->empty() && tmp->back() != b) {
			int t = tmp->back();
			tmp->pop_back();
			blocks[t].push_back(t);
			block_p[t] = t;
		}
		tmp->push_back(a);
		block_p[a] = block_p[b];
	}
}

void op_move_over(int a, int b)
{
	if (block_p[a] != block_p[b]) {
		deque<int> *tmp = &blocks[block_p[a]];

		while (!tmp->empty() && tmp->back() != a) {
			int t = tmp->back();
			tmp->pop_back();
			blocks[t].push_back(t);
			block_p[t] = t;
		}
		tmp->pop_back();
		tmp = &blocks[block_p[b]];
		tmp->push_back(a);
		block_p[a] = block_p[b];
	}
}

void op_pile_onto(int a, int b)
{
	if (block_p[a] != block_p[b]) {
		deque<int> *tmp = &blocks[block_p[b]];

		while (!tmp->empty() && tmp->back() != b) {
			int t = tmp->back();
			tmp->pop_back();
			blocks[t].push_back(t);
			block_p[t] = t;
		}
		stack<int> c;
		tmp = &blocks[block_p[a]];
		while (!tmp->empty() && tmp->back() != a) {
			int t = tmp->back();
			tmp->pop_back();
			c.push(t);
			block_p[t] = block_p[b];
		}
		int t = tmp->back();
		tmp->pop_back();
		c.push(t);

		tmp = &blocks[block_p[b]];
		while (!c.empty()) {
			tmp->push_back(c.top());
			c.pop();
		}
		block_p[a] = block_p[b];
	}
}

void op_pile_over(int a, int b)
{
	if (block_p[a] != block_p[b]) {
		stack<int> c;
		deque<int>  *tmp = &blocks[block_p[a]];
		while (!tmp->empty() && tmp->back() != a) {
			int t = tmp->back();
			tmp->pop_back();
			c.push(t);
			block_p[t] = block_p[b];
		}
		int t = tmp->back();
		tmp->pop_back();
		c.push(t);

		tmp = &blocks[block_p[b]];
		while (!c.empty()) {
			tmp->push_back(c.top());
			c.pop();
		}
		block_p[a] = block_p[b];
	}
}

int main(void)
{
	int n;

	gets(cmd);
	sscanf(cmd, "%d\n", &n);
	for (int i = 0; i < n; i++) {
		deque<int> tmp;
		block_p[i] = i;
		tmp.push_back(i);
		blocks.push_back(tmp);
	}
	while (1) {
		int a, b;
		enum ops op;
		gets(cmd);
		op = get_ops(cmd, a, b);

		if (op == quit)
			break;
		else if (op == move_onto)
			op_move_onto(a, b);
		else if (op == move_over)
			op_move_over(a, b);
		else if (op == pile_onto)
			op_pile_onto(a, b);
		else if (op == pile_over)
			op_pile_over(a, b);
	}
	output(n);
	return 0;
}