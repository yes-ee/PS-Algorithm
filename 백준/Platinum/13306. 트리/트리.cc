// union find

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int n, q;
vector<int> t;	// 트리 정보(부모 노드 저장)
vector<pair<int, int>> query;
int p[200001];
vector<string> ans;

int find(int u) {
	if (p[u] == u) return u;

	return find(p[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;

	p[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}

	t.push_back(0);
	t.push_back(1);
	for (int i = 0; i < n - 1; i++) {
		int a;
		cin >> a;
		t.push_back(a);
	}

	for (int i = 0; i < q + n - 1; i++) {
		int a, b, c = -1;
		cin >> a;
		if (a == 0) 
			cin >> b;
		else
			cin >> b >> c;

		query.push_back({b, c});
	}

	for (int i = q + n - 2; i >= 0; i--) {
		if (query[i].second == -1) {	// merge
			merge(t[query[i].first], query[i].first);
		} else {
			if (find(query[i].first) == find(query[i].second))
				ans.push_back("YES");
			else
				ans.push_back("NO");
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << "\n";
	}

	return 0;
}