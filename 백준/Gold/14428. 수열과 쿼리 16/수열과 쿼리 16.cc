// 세그먼트 트리

#include <iostream>
#include <algorithm>
#define INF 2e9

using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

ll n, m;
ll arr[100001];
pll tree[400000];

pll init(ll node, ll st, ll end) {
	if (st == end) return tree[node] = make_pair(st, arr[st]);

	ll mid = (st + end) / 2;

	pll node1 = init(node * 2, st, mid);
	pll node2 = init(node * 2 + 1, mid + 1, end);

	return tree[node] = (node1.second > node2.second ? node2 : node1);
}

pll update(ll node, ll st, ll end, ll idx, ll num) {
	if (idx < st || idx > end) return tree[node];

	if (st == end) return tree[node] = {idx, num};

	ll mid = (st + end) / 2;

	pll node1 = update(node * 2, st, mid, idx, num);
	pll node2 = update(node * 2 + 1, mid + 1, end, idx, num);

	return tree[node] = (node1.second > node2.second ? node2 : node1);
}

pll sum(ll l, ll r, ll node, ll st, ll end) {
	if (l <= st && end <= r) return tree[node];

	if (end < l || r < st) return {-1, INF};

	ll mid = (st + end) / 2;

	pll node1 = sum(l, r, node * 2, st, mid);
	pll node2 = sum(l, r, node * 2 + 1, mid + 1, end);

	return (node1.second > node2.second ? node2 : node1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(1, 1, n, b, c);
		} else {
			cout << sum(b, c, 1, 1, n).first << "\n";
		}
	}

	return 0;
}