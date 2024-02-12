// 세그먼트 트리
// 특정 구간의 쿼리(최소, 최대) 처리

#include <iostream>
#define INF 1234567890

using namespace std;

int n, m;
int arr[100001];
int min_seg[400000];
int max_seg[400000];

int min_init(int node, int st, int end) {
	if (st == end) return min_seg[node] = arr[st];

	int mid = (st + end) / 2;

	return min_seg[node] = min(min_init(node * 2, st, mid), min_init(node * 2 + 1, mid + 1, end));
}

int max_init(int node, int st, int end)
{
	if (st == end)
		return max_seg[node] = arr[st];

	int mid = (st + end) / 2;

	return max_seg[node] = max(max_init(node * 2, st, mid), max_init(node * 2 + 1, mid + 1, end));
}

int min_num(int l, int r, int node, int st, int end) {
	if (l <= st && end <= r) return min_seg[node];

	if (end < l || r < st) return INF;

	int mid = (st + end) / 2;
	return min(min_num(l, r, node * 2, st, mid), min_num(l, r, node * 2 + 1, mid + 1, end));
}

int max_num(int l, int r, int node, int st, int end)
{
	if (l <= st && end <= r)
		return max_seg[node];

	if (end < l || r < st)
		return 0;

	int mid = (st + end) / 2;
	return max(max_num(l, r, node * 2, st, mid), max_num(l, r, node * 2 + 1, mid + 1, end));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	min_init(1, 1, n);
	max_init(1, 1, n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << min_num(a, b, 1, 1, n) << " " << max_num(a, b, 1, 1, n) << "\n";
	}

	return 0;
}