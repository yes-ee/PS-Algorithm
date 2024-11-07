#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int phi(int num) {
	int ans = num;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			ans -= ans / i;
			while (num % i == 0) num /= i;
		}
	}

	if (num > 1) ans -= ans / num;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n==1) {
		cout << "1";
		return 0;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) { // 약수
			v.push_back(i);
			v.push_back(n / i);
		}
	}

	v.push_back(n);

	sort(v.begin(), v.end());

	for (auto num : v) {
		if (phi(num) == n / num) {
			cout << num;
			return 0;
		}
	}

	cout << "-1";

	return 0;
}