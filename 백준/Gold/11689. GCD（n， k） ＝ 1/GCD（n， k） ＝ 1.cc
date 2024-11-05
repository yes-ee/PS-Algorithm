#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
ll ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	ans = n;

	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) { // 소인수
			ans = ans - ans / i; // 배수 개수만큼 빼기
			while (n % i == 0) {
				n /= i;
			}
		}
	}

	if (n > 1) { // 소인수 남아있으면
		ans = ans - ans / n;
	}

	cout << ans;

	return 0;
}