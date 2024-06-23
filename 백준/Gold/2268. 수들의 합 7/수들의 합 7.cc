// segtree

#include <iostream>

using namespace std;
using ll = long long;

int arr[1000001];
ll segTree[4000000];
int n, m;
int a, i, j;

ll sum(int node, int st, int end, int l, int r) {
	if (l <= st && end <= r) return segTree[node];

	if (r < st || end < l) return 0;

	int mid = (st + end) / 2;

	return sum(node * 2, st, mid, l, r) + sum(node * 2 + 1, mid + 1, end, l, r);
}

void update(int node, int st, int end, int idx, ll diff) {
	if (st <= idx && idx <= end) segTree[node] += diff;
	else return;

	if (st == end) return;

	int mid = (st + end) / 2;

	update(node * 2, st, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	while (m--) {
		cin >> a >> i >> j;

		if (a == 0) {
			if (i > j) swap(i, j);
			cout << sum(1, 1, n, i, j) << "\n";
		}
		else {
			update(1, 1, n, i, j - arr[i]);
			arr[i] = j;
		}
	}

	return 0;
}