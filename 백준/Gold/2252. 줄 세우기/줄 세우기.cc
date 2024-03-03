// 위상 정렬
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> inDegree;
vector<int> graph[32001];
queue<int> q;

void topology_sort() {
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i];
			inDegree[nxt]--;
			if (inDegree[nxt] == 0) q.push(nxt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		inDegree.push_back(0);
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}

	topology_sort();

	return 0;
}