// union find
// 연결하는 두 점의 루트가 같으면 사이클

#include <iostream>

using namespace std;

int n, m, flag;
int parent[1000000];
int h[1000000];

void init() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		flag = 1;
		return;
	}

	if (h[a] < h[b]) swap(a, b);

	parent[b] = a;

	if (h[a] == h[b]) h[a]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	init();
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (flag) continue;

		merge(a, b);

		if (flag) {
			cout << i + 1;
		}
	}

	if (!flag)
		cout << "0";

	return 0;
}