// topology sort

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> q;
vector<int> v[32001];
int in_degree[32001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		in_degree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			pq.push(i);
		}
	}

	for (int i = 0; i < n; i++) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for (int j = 0; j < v[cur].size(); j++) {
			int nxt = v[cur][j];
			in_degree[nxt]--;
			if (in_degree[nxt] == 0) pq.push(nxt);
		}
	}

	return 0;
}