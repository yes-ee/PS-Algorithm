#include <bits/stdc++.h>
#define INF 123456789

using namespace std;
using pii=pair<int, int>;

int n;
int a, b;
int cnt[10001];
int graph[10001];

void bfs() {
	queue<pii> q;
	q.push({a, 0});

	while (!q.empty()) {
		int lo = q.front().first;
		int cn = q.front().second;
		q.pop();

		int num = graph[lo];
		int tmp = lo - num;
		while (tmp > 0) {
			if (cnt[tmp] == INF) {
				q.push({tmp, cn + 1});
				cnt[tmp] = cn + 1;
			}
			tmp -= num;
		}

		tmp = lo + num;
		while (tmp <= n) {
			if (cnt[tmp] == INF) {
				q.push({tmp, cn + 1});
				cnt[tmp] = cn + 1;
			}
			tmp += num;
		}

		if (cnt[b] != INF) return;
	}


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0;i<10001;i++) cnt[i] = INF;

	cin >> n;
	for (int i=1;i<=n;i++) cin >>graph[i];
	cin >> a >> b;

	bfs();

	if (cnt[b] != INF) cout << cnt[b];
	else cout << -1;
	return 0;
}