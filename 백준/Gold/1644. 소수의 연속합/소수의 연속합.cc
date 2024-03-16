#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int prime[4000001];
vector<int> v;
int n, s, e, sum, cnt;

void getprime() {
	for (int i = 1; i <= n; i++) {
		prime[i] = i;
	}

	for (int i = 2; i<= sqrt(n); i++) {
		if (prime[i] == 0) continue;

		for (int j = i * 2; j <= n; j += i) {
			prime[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (prime[i])
			v.push_back(i);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	getprime();

	v.push_back(0);

	while (e <= v.size()) {
		if (sum < n) {
			sum += v[e++];
		} else if (sum > n) {
			sum -= v[s++];
		} else {
			sum -= v[s++];
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}
