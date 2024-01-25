#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int m, n, s;
long long sum;

long long fpow(int cnt) {
	if (cnt == 1) return n;

	long long tmp = fpow(cnt / 2);
	if (cnt % 2) return tmp * tmp % MOD * n % MOD;
	else return tmp * tmp % MOD;
}

int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> n >> s;

		long long g = __gcd(n, s);
		n /= g;
		s /= g;

		// n 의 역원 구하기
		// b ^-1 = b^x-2 % MOD
		long long in = fpow(MOD - 2);
		sum += s * in % MOD;
		sum %= MOD;
	}
	cout << sum << "\n";

	return 0;
}