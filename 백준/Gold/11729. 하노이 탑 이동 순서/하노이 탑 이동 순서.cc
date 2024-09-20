#include <bits/stdc++.h>

using namespace std;

int n;

void re(int num, int st, int end, int mid) {

	if (num == 1) {
		cout << st << " " << end << "\n";
		return;
	}

	re(num - 1, st, mid, end);
	cout << st << " " << end << "\n";
	re(num - 1, mid, end, st);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int cnt = 1;

	for (int i = 1; i < n; i++) {
		cnt = cnt * 2 + 1;
	}

	cout << cnt << "\n";

	re(n, 1, 3, 2);

	return 0;
}