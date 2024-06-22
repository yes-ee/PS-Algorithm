#include <iostream>

using namespace std;
using ll = long long;

ll n, q;
ll x, y, a, b;
ll arr[100001];
ll segTree[400000];

ll init(ll node, ll st, ll end) {
	if (st == end) return segTree[node] = arr[st];

	ll mid = (st + end) / 2;

	return segTree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

ll sum(ll node, ll st, ll end, ll l, ll r) {
	if (l <= st && end <= r) return segTree[node];

	if (r < st || end < l) return 0;

	ll mid = (st + end) / 2;

	return sum(node * 2, st, mid, l, r) + sum(node * 2 + 1, mid + 1, end, l, r);
}

void update(ll node, ll st, ll end, ll idx, ll diff) {
	if (st <= idx && idx <= end) segTree[node] += diff;
	else return;

	if (st == end) return;

	ll mid = (st + end) / 2;

	update(node * 2, st, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	init(1, 1, n);

	while (q--) {
		cin >> x >> y >> a >> b;
	
		if (x > y) swap(x, y);
		cout << sum(1, 1, n, x, y) << "\n";

		update(1, 1, n, a, b - arr[a]);
		arr[a] = b;
	}

	return 0;
}