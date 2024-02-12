// 세그먼트 트리

#include <iostream>
#define MOD 1000000007

using namespace std;

int n, m, k;
long long arr[1000001];
long long tree[4000000];

long long init(long long node, long long st, long long end) {
	if (st == end) return tree[node] = arr[st];

	long long mid = (st + end) / 2;

	return tree[node] = init(node * 2, st, mid) * init(node * 2 + 1, mid + 1, end) % MOD;
}

long long update(long long node, long long st, long long end, long long idx, long long num) {
	if (idx < st || idx > end) return tree[node];

	if (st == end) return tree[node] = num;

	long long mid = (st + end) / 2;
	return tree[node] = update(node * 2, st, mid, idx, num) * update(node * 2 + 1, mid + 1, end, idx, num) % MOD;
}

long long sum(long long l, long long r, long long node, long long st, long long end) {
	if (l <= st && end <= r) return tree[node];

	if (end < l || r < st) return 1;

	long long mid = (st + end) / 2;
	return sum(l, r, node * 2, st, mid) * sum(l, r, node * 2 + 1, mid + 1, end) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		} else {
			cout << sum(b, c, 1, 1, n) << "\n";
		}
	}
}