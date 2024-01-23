// union find

#include <iostream>
#include <vector>

using namespace std;

int n, m, t, cnt;
int parent[51];
int h[51];
int know[51];
vector<int> v[50];

void init() {
	for (int i = 0; i<= n; i++)
		parent[i] = i;
}

int find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (h[a] < h[b]) swap(a, b);

	parent[b] = a;

	if (h[a] == h[b]) h[a]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;

	init();

	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		know[a] = 1;
	}

	for (int i = 0; i < m; i++) {
		int num, a, b;
		cin >> num >> a;
		v[i].push_back(a);
		for (int j = 1; j < num; j++) {
			cin >> b;
			v[i].push_back(b);
			merge(a, b);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (know[i]) {
			know[find(i)] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		int flag = 0;
		for (int c: v[i]) {
			if (know[find(c)]) {
				flag = 1;
				break;
			}
		}
		if (!flag) cnt++;
	}

	cout << cnt;

	return 0;
}