#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
bool visited[101][1 << 15];
int k;
int jew[101];
int ans;
vector<pii> v[101]; // 그래프 - end, max cnt

int getSum(int cur) {
	int cnt = 0;
	while (cur) {
		if (cur & 1) {
			cnt++;
		}
		cur = cur >> 1;
	}

	return cnt;
}

void bfs() {
	queue<pii> q;
	q.push({ 1, 0 });

	// 1번에 보석 있으면
	if (jew[1] != -1) {
		q.push({ 1, 1 << jew[1] });
		ans = 1;
	}

	while (!q.empty()) {
		int st = q.front().first; // node
		int cur = q.front().second; // cur state
		int cnt = getSum(cur);
		q.pop();

		if (st == 1)
			ans = max(cnt, ans);

		for (auto i : v[st]) {
			int nx = i.first;
			int val = i.second;

			// 다리 무게 확인
			if (cnt > val)
				continue;

			// 보석 안 주움
			if (!visited[nx][cur]) {
				visited[nx][cur] = true;
				q.push({ nx, cur });
			}
			// 보석 주움
			int ns = cur | (1 << jew[nx]);
			if (jew[nx] != -1 && (!visited[nx][ns])) {
				visited[nx][ns] = true;
				q.push({ nx, ns });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;

	int a, b, c;

	for (int i = 0; i <= n; i++) jew[i] = -1;

	for (int i = 0; i < k; i++) {
		cin >> a;
		jew[a] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c});
		v[b].push_back({ a, c });
	}

	bfs();

	cout << ans;

	return 0;
}