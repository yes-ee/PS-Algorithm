// topological sort

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii=pair<int, int>;

int n, m, cnt;
vector<pii> v[10001];
vector<pii> rv[10001];
long long t[10001];
int visited[10001];
int in_degree[10001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		rv[b].push_back({a, c});
		in_degree[b]++;
	}

	int s, e;
	cin >> s >> e;

	q.push(s);

	// 최대 시간 구하기 - 위상정렬
	for (int i = 0; i < n; i++) {
		int x = q.front();
		q.pop();

		for (pii c: v[x]) {
			if (t[c.first] < t[x] + c.second)
				t[c.first] = t[x] + c.second;	// 해당 도시까지 오는 데 걸리는 최대 시간 저장
			in_degree[c.first]--;
			if (in_degree[c.first] == 0) {
				q.push(c.first);
			}
		}
	}

	// 이용하는 경로 개수 구하기
	q.push(e);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (pii c: rv[x]) {
			if (t[x] - c.second == t[c.first]) { // 최대 경로이면
				cnt++;
				if (visited[c.first])
					continue;
				else {
					visited[c.first] = 1;
					q.push(c.first);
				}
			}
		}
	}
	cout << t[e] << "\n";
	cout << cnt;

	return 0;
}