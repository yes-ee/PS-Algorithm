// SCC

#include <bits/stdc++.h>

using namespace std;

int v, e;
int p[10001];
int finished[10001];
int id;
vector<vector<int>> scc;
vector<int> adj[10001];
stack<int> st;

int dfs(int x) {
	p[x] = ++id; // 방문 순서
	st.push(x);	

	int parent = p[x];

	for (auto i : adj[x]) {
		// 방문한 적 없는 노드
		if (!p[i]) parent = min(parent, dfs(i));

		// 방문한 적 있지만, 아직 scc에 포함되지 않은 노드
		else if (!finished[i]) parent = min(parent, p[i]);
	}

	// scc 중 제일 작은 노드가 자기 자신이면
	if (p[x] == parent) {
		// scc 생성
		// 내가 나올 때까지 pop
		vector<int> tmp;
		while (1) {
			int t = st.top();
			st.pop();

			tmp.push_back(t);
			finished[t] = 1;

			if (t == x) break;
		}
		sort(tmp.begin(), tmp.end());

		scc.push_back(tmp);
	}

	return parent;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> v >> e;

	// input
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (!p[i]) dfs(i);
	}

	sort(scc.begin(), scc.end());

	cout << scc.size() << '\n';
	for (auto i : scc) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << "-1\n";
	}

	return 0;
}