// dfs

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int n, m;
int grp;
int arr[1000][1000];
int visited[1000][1000]; // save group number
int grpc[1000000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x) {
	// check next area
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] || arr[ny][nx]) continue;

		visited[ny][nx] = grp;
		grpc[grp]++;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n >> m;

	// input
	for (int i = 0; i< n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	// count for all by bfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] || visited[i][j]) continue;
			grp++;
			visited[i][j] = grp;
			grpc[grp]++;
			dfs(i, j);
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j]) {
				cout << "0";
				continue;
			}

			cnt = 1;
			set<int> s;

			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n || arr[ny][nx])
					continue;

				if (s.find(visited[ny][nx]) != s.end()) continue;

				cnt += grpc[visited[ny][nx]];
				s.insert(visited[ny][nx]);
			}

			cout << cnt % 10;
		}
		cout << "\n";
	}

	return 0;
}