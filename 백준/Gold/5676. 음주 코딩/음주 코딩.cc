#include <iostream>

using namespace std;

int n, k;
int arr[100001];
int seg[400001];
int b, c;
char a;

int init(int node, int st, int end) {
	if (st == end) {
		if (arr[st]) return seg[node] = arr[st] > 0 ? 1 : -1;
		else return seg[node] = 0;
	}

	int mid = (st + end) / 2;

	return seg[node] = init(node * 2, st, mid) * init(node * 2 + 1, mid + 1, end);
}

int upd(int node, int st, int end, int idx, int val) {
	if (idx < st || idx > end) return seg[node];

	if (st == end) {
		return seg[node] = val;
	}

	int mid = (st + end) / 2;

	return seg[node] = upd(node * 2, st, mid, idx, val) * upd(node * 2 + 1, mid + 1, end, idx, val);
}

int mul(int node, int st, int end, int l, int r) {
	if (l <= st && end <= r) return seg[node];

	if (r < st || end < l) return 1;

	int mid = (st + end) / 2;
	return mul(node * 2, st, mid, l, r) * mul(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> k) {
		// cin >> n >> k;
		
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		init(1, 1, n);

		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c;

			if (a == 'C') {
				if (c) c = c > 0 ? 1 : -1;
				upd(1, 1, n, b, c);
				arr[b] = c;
			} else {
				int num = mul(1, 1, n, b, c);
				if (num) cout << (num > 0 ? '+' : '-');
				else cout << 0;
			}
		}

		cout << "\n";

		// if (cin.eof()) break;
	}

	return 0;
}