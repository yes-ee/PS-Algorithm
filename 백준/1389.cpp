// // bfs

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool visited[100];
// int cnt[100];
// vector<int> graph[100];
// queue<int> q;
// int n, m;
// int res = 9999;
// int sum;
// int ans;

// int check_friend(int a, int b) {
// 	auto it = find(graph[a].begin(), graph[a].end(), b);
// 	if (it != graph[a].end())
// 		return 1;
// 	return 0;
// }

// void init(int i) {
// 	for (int i = 0; i < n; i++) {
// 		visited[i] = false;
// 		cnt[i] = 0;
// 	}
// 	sum = 0;
// }

// int bfs(int s) {
// 	while (!q.empty()) {
// 		int x = q.front();
// 		q.pop();

// 		for (int i = 0; i < graph[x].size(); i++) {
// 			int nx = graph[x][i];
// 			if (visited[nx] == true)
// 				continue;
// 			visited[nx] = true;
// 			q.push(nx);
// 			cnt[nx] = cnt[x] + 1;
// 		}
// 	}

// 	for (int i = 0; i < n; i++) {
// 		sum += cnt[i];
// 	}

// 	return sum;
// }

// int main() {
// 	cin >> n >> m;
// 	for (int i = 0; i < m; i++) {
// 		int a, b;
// 		cin >> a >> b;
// 		a--;
// 		b--;
// 		if (check_friend(a, b))
// 			continue;
// 		graph[a].push_back(b);
// 		graph[b].push_back(a);
// 	}

// 	for (int i = 0; i < n; i++) {
// 		init(i);
// 		q.push(i);
// 		visited[i] = true;
// 		int num = bfs(i);
// 		if (num < res) {
// 			res = num;
// 			ans = i + 1;
// 		}
// 	}

// 	cout << ans;
// 	return 0;
// }

// floyd-warshall

#include <iostream>
#include <algorithm>

using namespace std;

int cnt[100];
int graph[100][100];
int n, m;
int num, ans;
int res = 9999;
int sum;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			graph[i][j] = 9999;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += graph[i][j];
		}
		if (sum < res) {
			res = sum;
			ans = i + 1;
		}
	}

	cout << ans;
	return 0;
}