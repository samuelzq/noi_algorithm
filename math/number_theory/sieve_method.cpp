#incluce <iostream>

const int N = 1000000;
bool is_prime[N];
unsigned int prime[N];

int Eratosthenes(int n)
{
	int p = 0;

	for (int i = 0; i <= n; ++i)
		is_prime[i] = true;

	// 0 and 1 are not primes
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			prime[p++] = i;
			// 因为从 2 到 i - 1 的倍数我们之前筛过了，直接从 i
			// 的倍数开始，提高了运行速度
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;  // 是i的倍数的均不是素数
		}
	}
	return p;
}

int eulerSieve(int n)
{
	int p = 0;

	for (int i = 0; i <= n; ++i)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (is_prime[i] == true)  // 素数
			prime[p++] = i;
		for (j = 0; j < p; j++) {
			if (i * prime[j] > n) // 当要标记的合数超出范围时跳出
				break;
			// 筛除已经记录的素数的倍数
			is_prime[i * prime[j]] = false;
			// 当i是prime[j]的整数倍时，记 m = i / prime[j]，那么
			// i * prime[j+1] 就可以变为 (m * prime[j+1]) * prime[j]，
			// 这说明 i * prime[j+1] 是 prime[j] 的整数倍，不需要再进
			// 行标记(在之后会被 prime[j] * 某个比i大的数标记)，对于
			// prime[j+2] 及之后的素数同理，直接跳出循环，这样就避免
			// 了重复标记。
			if (i % prime[j] == 0)
				break;
		}
	}
	return p;
}

unsigned int phi[N];
int get_euler(int n)
{
	int cnt = 0;

	phi[1] = 1; //1的欧拉函数为1

	for (int i = 0; i <= n; ++i)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= n; i ++) {
		if (is_prime[i] == true) {
			prime[cnt++] = i;
			//如果i是质数，那么ϕ(i)=i-1。1 ~ i−1均与i互质，共i−1个。
			phi[i] = i - 1;
		}

		for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
			is_prime[prime[j] * i] = false;

			//i不是质数，prime[j]是i的最小质因子
			if (i % prime[j] == 0) {
				phi[prime[j] * i] = prime[j] * phi[i];
				break;
			} else { //i不是质数，prime[j]不是i的质因子
				phi[prime[j] * i] = (prime[j] - 1) * phi[i];
			}
		}
	}

	int res = 0;
	for(int i = 1; i <= n; i ++)
		res += phi[i];

	return res;
}

// 解莫比乌斯函数
// 1）莫比乌斯函数μ(n)的定义域是N；
// 2）μ(1)=1；
// 3）当n存在平方因子时，μ(n)=0；
// 4）当n是素数或奇数个不同素数之积时，μ(n)=-1；
// 5）当n是偶数个不同素数之积时，μ(n)=1。
//
// 这个做起来比欧拉函数容易，在过程上，若n为素数则μ(n)=-1;
// 若n % prime[j] = 0，则μ(n * prime[j]) = 0，显然prime[j]就是它的平方因子;
// 否则μ(n * prime[j]) = -μ(n), 因为多了一个质因子。
int mob[N];
void getmobius( )
{
	int cnt = 0;
	memset(is_prime, 0, sizeof(vis));
	memset(prime, 0, sizeof(prime));
	memset(mob, 0, sizeof(mob));
	mob[1] = 1;

	for (int i = 2; i < N; i++) {
		if(is_prime[i] == false) { //质数
			prime[cnt++] = i;
			mob[i] = -1; //质数为-1
		}

		for (int j = 0; j < cnt && i * prime[j] < M; j++) {
			is_prime[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				// i中有因子prime[j],
				// 所以i * prime[j]中有平方因子prime[j]
				mob[i * prime[j]] = 0;
				break;
			} else {
				mob[i*prime[j]] = -mob[i];
			}
		}
	}
}

// 筛法求前n个数的约数
int d[N]; // 前N个数约数个数
int num[N]; // i的最小质因子的个数(指数)

// 情况1：
// i是一个质数,那么d[i] = (1 + 1) = 2(约数为1和自己本身i)
// 只有一个质因子就是自身(i) ,所以num[i] = 1
//
// 情况2：
// i % prime[j] != 0，此时i中没有prime[j]这个质因子，但是
// i * prime[j]中含有此质因子。由于新增了一个质因子，所以
// d[i*prime[j]] = 2 * d[i]。由于是从小到大进行筛法，所以
// prime[j]是i * prime[j]的最小质因子。
//
// 情况3：
// i % prime[j] = 0。此时i中包含了最小质因子prime[j]。因此
// num[i*prime[j]] = num[i] + 1；
// d[i*prime[j]] = d[i]/(1+num[i])*(1+num[i*prime[j]])。
void getd(int n)
{
	int cnt = 0;
	memset(is_prime, 0, sizeof(is_prime));
	memset(prime, 0, sizeof(prime));
	memset(d, 0, sizeof(d));
	memset(num, 0, sizeof(num));
	d[1]=1;

	for (int i = 2; i < n; i++) {
		if (!is_prime[i]) {
			// 质数
			prime[cnt++] = i;
			d[i] = 2;
			num[i] = 1;
		}

		for (int j = 0; j < cnt && i * prime[j] < n; j++) {
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				// 情况3
				num[i * prime[j]] = num[i] + 1;
				d[i * prime[j]] = d[i] / (num[i] + 1) * (num[i * prime[j]] + 1);
				break;
			} else {
				// 情况2
				num[i * prime[j]] = 1;
				d[i * prime[j]] = d[i] * 2;
			}
		}
	}
}

// 筛约数和
// t[i] 表示i的2约数和
// e[i] 表示i的约数中，不能被i的最小素因子整除的约数和
int t[N],e[N];

// 情况A：
// i是质数，t[i]=i+1, e[i]=1
//
// 情况B：
// i不是质数，考虑到从小到大开始筛，所以i*pj的最小素因子是pj
//
// 此时又可分为两种情况：
// 1、如果i不是pj的倍数，那么i的所有约数中，必然没有pj的倍数
// 令S表示i的约数集，S’表示i的约数翻pj倍后的数的集合。
// 则S∩S’=∅，S和S’中无重复元素。
// 所以t[i*pj] = S+S' = t[i]+t[i]*pj = t[i]*(pj+1)
// S’中的所有元素都能整除pj，所以e[i*pj] = t[i]。
//
// 2、如果i是pj的倍数，那么S和S’必有交集T
// T = S中pj的倍数
// 所以i*pj的约数和要去除交集T
// 那么t[i*pj] = S + S' - T = S' + S - T = t[i]*pj + e[i]
// 因为pj既是i的最小素因子，又是i*pj的最小素因子
// 所以e[i*pj]=e[i]
int get_pre(int n)
{
	int cnt = 0;

	for(int i = 2; i <= n; ++i) {
		if (is_prime[i] == true) {
			// 情况A
			prime[cnt++] = i;
			t[i] = i + 1;
			e[i] = 1;
		}

		for (int j = 1; j <= cnt && i * prime[j] < n; ++j) {
			is_prime[prime[j] * i] = false;
			if (i % prime[j] == 0) {
				// 情况B2
				t[i * prime[j]] = t[i] * prime[j] + e[i];
				e[i * prime[j]] = e[i];
				break;
			}
			// 情况B1
			t[i * prime[j]] = t[i] * (prime[j] + 1);
			e[i * prime[j]] = t[i];
		}
	}
	return cnt;
}
