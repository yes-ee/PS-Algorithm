#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll m, n;
ll len[64];
string arr[2] = {"Messi", "Messi Gimossi"};

void recur(ll n, ll idx) {
	// n == 0
	if (n == 0) {
		cout << arr[0][idx - 1];
		return;
	}
	// n == 1
	else if (n == 1) {
		if (idx == len[0] + 1)
			cout << "Messi Messi Gimossi";
		else
			cout << arr[1][idx - 1];
		return;
	}

	// idx in messi(n-1)
	if (idx <= len[n - 1]) {
		recur(n - 1, idx);
	}
	// idx in space
	else if (idx == len[n - 1] + 1) {
		cout << "Messi Messi Gimossi";
	}
	// idx in messi(n-2)
	else {
		recur(n - 2, idx - len[n - 1] - 1);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;

	len[0] = 5;
	len[1] = 13;
	for (int i = 2; i < 64; i++) {
		len[i] = len[i - 1] + len[i - 2] + 1;
	}

	for (int i = 0; i < 64; i++) {
		if (len[i] >= m) {
			n = i;
			break;
		}
	}

	recur(n, m);

	return 0;
}