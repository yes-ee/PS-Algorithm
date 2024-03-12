// topological sort

#include <iostream>
#include <vector>
#include <queue>

int t, n, m;
int arr[501];
int in_degree[501];

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v[n + 1];
		vector<int> ans;
		for (int i = 0; i <= n; i++) {
			arr[i] = 0;
			in_degree[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			arr[a] = 1;

			// 순위 낮은 팀 다 +1
			for (int j = 1; j <= n; j++) {
				if (arr[j] == 0) {
					v[a].push_back(j);
					in_degree[j]++;
				}
			}
		}

		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b, flag = 0;
			cin >> a >> b;
			for (int j = 0; j < v[a].size(); j++) {
				if (v[a][j] == b) {
					v[a].erase(v[a].begin() + j);
					v[b].push_back(a);
					in_degree[b]--;
					in_degree[a]++;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				for (int j = 0; j < v[b].size(); j++)
				{
					if (v[b][j] == a)
					{
						v[b].erase(v[b].begin() + j);
						v[a].push_back(b);
						in_degree[a]--;
						in_degree[b]++;
						break;
					}
				}
			}
		}

		queue<int> q;
		int flag = 0;

		for (int i = 1; i <= n; i++) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}

		for (int i = 0; i < n; i++) {
			if (q.empty()) {
				cout << "IMPOSSIBLE";
				flag = 1;
				break;
			}

			if (q.size() != 1) {
				cout << "?";
				flag = 1;
				break;
			}

			int x = q.front();
			q.pop();

			ans.push_back(x);

			for (int c: v[x]) {
				in_degree[c]--;
				if (in_degree[c] == 0)
					q.push(c);
			}
		}

		if (!flag) {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}