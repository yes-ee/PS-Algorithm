// 자기 자신 제외 가장 큰 약수 찾기

#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

int main() {
	cin >> n;

	ans = 1;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans = n / i;
			break;
		}
	}

	cout << n - ans;

	return 0;
}