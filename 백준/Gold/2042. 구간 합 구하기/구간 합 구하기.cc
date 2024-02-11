// 세그먼트 트리 
// 업데이트, 구간합 구하기

#include <iostream>

using namespace std;

int n, m, k;
long long arr[1000001];
long long seg[4000000];

long long init(int node, int st, int end) {
	if (st == end) return seg[node] = arr[st];

	int mid = (st + end) / 2;

	return seg[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int st, int end, int idx, long long diff) {
	if (st <= idx && idx <= end) seg[node] += diff;	// 구간 내
	else return;	// 구간 밖

	if (st == end) return;

	int mid = (st + end) / 2;
	update(node * 2, st, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

long long sum(int l, int r, int node, int st, int end) {
	// 구간 내 완전히 포함
	if (l <= st && end <= r) return seg[node];

	// 구간이 하나도 안 겹침
	if (end < l || r < st) return 0;

	// 구간이 일부 겹침
	int mid = (st + end) / 2;
	return sum(l, r, node * 2, st, mid) + sum(l, r, node * 2 + 1, mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) { // 업데이트
			update(1, 1, n, b, c - arr[b]);
			arr[b] = c;
		} else {	// 구간합
			cout << sum(b, c, 1, 1, n) << "\n";
		}
	}

	return 0;
}