#include <iostream>
#define INF 2e9;

using namespace std;
using ll=long long;

int n, m;
ll arr[100001];
ll tree[400000];

ll init(ll node, ll st, ll end) {
	if (st == end) return tree[node] = arr[st];

	ll mid = (st + end) / 2;

	return tree[node] = min(init(node * 2, st, mid), init(node * 2 + 1, mid + 1, end));
}

ll update(ll node, ll st, ll end, ll idx, ll diff) {
	if (st > idx || idx > end) return tree[node];

	if (st == end) return tree[node] = diff;

	ll mid = (st + end) / 2;

	return tree[node] = min(update(node * 2, st, mid, idx, diff), update(node * 2 + 1, mid + 1, end, idx, diff));
}

ll sum(ll l, ll r, ll node, ll st, ll end) {
	if (l <= st && end <= r) return tree[node];

	if (r < st || end < l) return INF;

	ll mid = (st + end) / 2;
	return min(sum(l, r, node * 2, st, mid), sum(l, r, node * 2 + 1, mid + 1, end));
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	init(1, 1, n);

	cin >> m;
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(1, 1, n, b, c);
		else
			cout << sum(b, c, 1, 1, n) << "\n";
	}

	return 0;
}