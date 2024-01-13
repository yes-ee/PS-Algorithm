#include <iostream>
#include <queue>
using namespace std;

int graph[101];
int count[101];
int n, m;
queue<int> q;

int bfs() {
	while (!q.empty()) {
		int x = q.front();

		if (x == 100)
			return count[100];
		q.pop();
		
		for (int i = 1; i < 7; i++) {
			int nx = x + i;
			if (nx < 101 && count[nx] == 0) {
				if (graph[nx]) {
					nx = graph[nx];
					if (count[nx] != 0)
						continue;
				}
				q.push(nx);
				count[nx] = count[x] + 1;
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		graph[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x] = y;
	}

	q.push(1);

	cout << bfs();

	return 0;
}