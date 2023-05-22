#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> v[MAX];
bool visited[MAX];
int cnt;

void bfs(int n) {
	queue<int> q;
	visited[n] = 1;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}