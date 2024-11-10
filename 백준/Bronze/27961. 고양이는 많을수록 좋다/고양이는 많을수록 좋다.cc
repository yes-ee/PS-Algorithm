#include <iostream>

using namespace std;
using ll = long long;

ll n;

int main() {
	cin >> n;

	if (n == 1 || n == 0) {
		cout << n;
		return 0;
	}

	ll cur = 1;
	ll cnt = 1;

	while (1) {
		ll nx = cur << 1;
		if (nx < n) {
			cur = nx;
			cnt++;
		} else {
			cnt++;
			break;
		}
	}

	cout << cnt;

	return 0;
}