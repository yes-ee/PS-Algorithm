#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k;
ll sum;
ll arr[5001];
int cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int st = 0;
	int end = n - 1;

	while (st < end) {
		sum = arr[st] + arr[end];

		if (sum <= k) {
			cnt++;
			st++;
		}
		end--;
	}

	cout << cnt;

	return 0;
}