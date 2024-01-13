#include <iostream>
#include <queue>
#define MAX_SIZE 20001
#define c1 1
#define c2 2
using namespace std;

int k, v, e;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];
queue<int> q;

void bfs(void) {
	int color = c1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (visited[node] == c1)
			color = c2;
		else if (visited[node] == c2)
			color = c1;

		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (!visited[next]) {
				visited[next] = color;
				q.push(next);
			}
		}
	}
}

int isBiGraph() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (visited[i] == visited[next])
				return 0;
		}
	}
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> v >> e;

		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int j = 1; j <= v; j++) {
			if (!visited[j]) {
				visited[j] = 1;
				q.push(j);
				bfs();
			}
		}

		if (isBiGraph())
			cout << "YES\n";
		else
			cout << "NO\n";

		for (int i = 1; i <= v; i++) {
			graph[i].clear();
			visited[i] = 0;
		}
	}

	return 0;
}