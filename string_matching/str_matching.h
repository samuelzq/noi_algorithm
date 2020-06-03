#ifndef __H_STR_MATCHING
#define __H_STR_MATCHING

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>

int brute_force_str_matching(string p, string t)
{
	int i = 0;

	while (i <= t.length() - p.length()) {
		int j = 0;
		// try to match all chs in the pattern
		while (t[i] == p[j] && j < p.length()) {
			i++;
			j++;
		}
		if (j == p.length()) // found a match
			return i - p.length();
		// no match found, r-shift P one position
		i = i - j + 1;
	}
	// no match found
	return -1;
}

int hancart_bfs(string p, string t)
{
	int e, d;

	if (p[0] == p[1]) {
		e = 1;
		d = 2;
	} else {
		e = 2;
		d = 1;
	}

	int i = 0;
	int tl = t.length(), pl = p.length();
	while (i <= tl - pl) {
		if (t[i + 1] != p[1])
			i += d;
		else {
			j = 1;
			while (j < pl && t[i + j] == p[j])
				j++;
			if (j == pl && p[0] == t[i])
				return i;
			i += e;
		}
	}
	return -1;
}


static int *find_nexts(string pattern)
{
	int *next = new int[pattern.length()]();

	next[0] = -1;
	int i = 0, j = -1, len = pattern.length();

	while (i < len) {
		while (j == -1 || (i < len && p[i] == p[j])) {
			i++;
			j++;
			if (p[i] != p[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		j = next[j];
	}

	return next;
}

int kmp_matching(string p, string t)
{
	int *next = find_next(p);
	int i = 0, j = 0;
	int tl = t.length(), pl = p.length();
	int match = -1;
	while (i <= (tl - pl)) {
		while (j == -1 || (j < pl && t[i] == p[i])) {
			i++;
			j++;
		}
		if (j == pl) {
			match = i - pl;
			goto exit;
		}
		j = next[j];
	}
exit:
	delete[] next;
	return match;
}
#endif
static int *find_next(string pattern)
{
	int *next = new int[pattern.length()]();

	next[0] = -1;
	int i = 0, j = -1, len = pattern.length();

	while (i < len) {
		while (j == -1 || (i < len && p[i] == p[j])) {
			i++;
			j++;
			next[i] = j;
		}
		j = next[j];
	}

	return next;
}

// Knuth-Morris-Pratt algorithm
int kmp_matching(string p, string t)
{
	int *next = find_next(p);
	int i = 0, j = 0;
	int tl = t.length(), pl = p.length();
	int match = -1;
	while (i <= (tl - pl)) {
		while (j == -1 || (j < pl && t[i] == p[i])) {
			i++;
			j++;
		}
		if (j == pl) {
			match = i - pl;
			goto exit;
		}
		j = next[j];
	}
exit:
	delete[] next;
	return match;
}

#define BAD_CHR_TABLE      256

// Preprocess for bad character
void bm_init_bc(string p, int &occ[BAD_CHR_TABLE])
{
	// initialize the occurence table,
	// '-1' means a bad character for the pattern
	for (char a = 0; a < BAD_CHR_TABLE; a++)
		occ[a] = -1;

	for (int i = 0; i < p.length(); i++) {
		a = p[i];
		occ[a] = i;
	}
}

// Preprocess for good suffix
void bm_init_gs(string p, int border[], int shift[])
{
	int m = p.length();
	int i = m, j = m + 1;
	border[i] = j;

	while (i > 0) {
		while (j <= m && p[i - 1] != p[j - 1]) {
			// a strong good suffix is found, pattern should 
			// shift right from i to j
			if (shift[j] == 0) // the 1st strong good suffix
				shift[j] = j - i;

			// try the next border
			j = border[j];
		}
		// enlarge the border
		i--;
		j--;
		border[i] = j;
	}
}

// Preprocess fpr good suffix case2
void bm_init_gs_case2(int border[], int shift[], int m)
{
	int j = border[0];

	for (int i = 0; i <= m; i++) {
		// fill empty entry in shift[] with border[0]
		if (shift[i] == 0)
			shift[i] = j;

		// suffix becomes shorter, use next border
		if (i == j)
			j = border[j];
	}
}

#define MAX(x,y)  ((x) > (y) ? (x) : (y))
// Boyer-Moore algorithm
int bm_matching(string p, string t)
{
	const int c = 256;
	int *occ = new int[c](-1);
	int pl = p.length(), tl = t.length();
	int j, s = 0;
	int *border, *shift;
	border = new int[pl + 1]();
	shift  = new int[pl + 1]();

	bm_init_bc(p, occ);
	bm_init_gs(p, border, shift);
	bm_init_gs_case2(border, shift, pl);

	for (int i = 0; i <= tl - pl;) {
		j = pl - 1;
		while (j >= 0 && p[j] == t[i + j])
			j--;

		if (j < 0) {
			std::cout << "Pattern occurs at %d" << s << '\n';
			i += shift[0];
		} else
			i += MAX(shift[j + 1], j - occ[t[i + j]]);
	}
exit:
	delete[] occ;
	delete[] border;
	delete[] shift;
	return 0;
}


// a bit-oriented approach
void dynamic_shift_matching(string p, string t)
{
	const int cell_len = sizeof(int);
	int m = p.length(), n = t.length();
	int cell_num = (m % cell_len) ? (m / cell_len) : (m / cell_len + 1);
	int last_bit = 1, match = 1;
	int *chr_in_p = new int[cell_num * 256]();
	int *state = new int[cell_num]();

	for (int i = 1; i < m - cell_len * (cell_num - 1) - 1; i++)
		match << 1; // only need to check the highest cell

	// Initialize the pattern character position table
	for (int k = 0; k < cell_num; k++) {
		for (int i = k * cell_len, j = 1; i < (k + 1) * cell_len && i < m;) {
			chr_in_p[p[i] + k] |= j;
			j = j << 1;
			i++
		}
	}

	for (int i = 0; i < m; i++) {
		int c = i % cell_len, k = i / cell_len;
		for (int k = 0; k < cell_num; k++) {
			for (int j = k * cell_len, l = 1; j < m; j++) {
				chr_in_p[p[i] * cell_numm + k] |= j;
				j = j << 1;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int first_bit = 0;
		for (int j = cell_num; j > 0; j--) {
			first_bit = ((state[j - 1] & last_bit) == 0) ? 0 : 1;
			state[j] = ((state[j] << 1) | first_bit) & chr_in_p[t[i] + j];
		}
		state[0] = ((state[0] << 1) | 1) & chr_in_p[t[i]];

		if ((match & state[cell_num - 1]) != 0)
			std::cout << "A match at " << i - m + 1;
	}
}
#endif
