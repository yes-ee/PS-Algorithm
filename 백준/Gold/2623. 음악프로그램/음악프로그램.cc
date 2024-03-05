#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
queue<int> q;
vector<int> v[1001];
int in_degree[1001];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a;
		if (a)
			cin >> b;
		for (int j = 1; j < a; j++) {
			cin >> c;
			v[b].push_back(c);
			in_degree[c]++;
			b = c;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) q.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			cout << "0";
			return 0;
		}

		int cur = q.front();
		q.pop();
		ans.push_back(cur);

		for (int j = 0; j < v[cur].size(); j++) {
			int nxt = v[cur][j];
			in_degree[nxt]--;
			if (in_degree[nxt] == 0)	q.push(nxt);
		}
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << "\n";

	return 0;
}