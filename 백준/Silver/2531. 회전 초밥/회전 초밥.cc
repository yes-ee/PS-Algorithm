#include <iostream>

using namespace std;

int n, d, k, c;
int sel[3001];
int arr[30000];
int ans, cnt;

void coupon() {
	if (!sel[c])
		ans = max(cnt + 1, ans);
	else
		ans = max(cnt, ans);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int st = 0;
	int end = 0;
	int num;
	// init
	while (end < k) {
		num = arr[end];
		if (!sel[num]) cnt++;
		sel[num]++;
		end++;
	}

	coupon();

	for (int i = 1; i < n; i++) {
		// start idx plus
		num = arr[st];
		sel[num]--;
		if (!sel[num]) cnt--;
		st++;

		// end idx plus
		if (end > n - 1) end %= n;
		num = arr[end];
		if (!sel[num]) cnt++;
		sel[num]++;
		end++;

		// check coupon
		coupon();
	}

	cout << ans;

	return 0;
}