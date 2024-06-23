// segtree

#include <iostream>

using namespace std;
using ll = long long;

ll arr[1000001];
ll seg[4000000];
ll n, a, b, c;

void update(int node, int st, int end, int idx, ll diff) {
	if (st <= idx && idx <= end) seg[node] += diff;
	else return;

	if (st == end) return;

	int mid = (st + end) / 2;

	update(node * 2, st, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

int find(int node, int st, int end, int idx) {
	if (st == end) return st;

	int mid = (st + end) / 2;

	if (idx <= seg[node * 2]) {
		return find(node * 2, st, mid, idx);
	} else {
		return find(node * 2 + 1, mid + 1, end, idx - seg[node * 2]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	while (n--) {
		cin >> a >> b;
		if (a == 2) {
			cin >> c;

			update(1, 1, 1000000, b, c);
			arr[b] += c;
		} else {
			int ans = find(1, 1, 1000000, b);
			update(1, 1, 1000000, ans, -1);

			cout << ans << "\n";
		}
	}

	return 0;
}