// bfs
#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
queue<int> q;
int visited[1000001];

void bfs() {
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == g) {
			cout << visited[x] - 1;
			return;
		}

		int nx = x + u;
		if (nx <= f && !visited[nx])
		{
			q.push(nx);
			visited[nx] = visited[x] + 1;
		}

		nx = x - d;
		if (nx >= 1 && !visited[nx])
		{
			q.push(nx);
			visited[nx] = visited[x] + 1;
		}
	}

	cout << "use the stairs";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;

	bfs();
}