// bfs
#include <iostream>
#include <queue>

using namespace std;
using pii=pair<int, int>;

int s;
int visited[2024];
queue<pair<pii, int>> q; // nxt, time, cnt

int bfs() {
	q.push({{1, 1}, 1});
	visited[1] =  1;

	int nxt, tm, cnt, pre = 1;

	while (1) {
		nxt = q.front().first.first;
		tm = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		
		// copy
		if (nxt != cnt)
			q.push({{cnt, tm + 1}, cnt});
		pre = cnt;

		// paste
		if (cnt + nxt == s) {
			return tm + 1;
		} else {
			if (cnt + nxt < 2024 && (visited[cnt + nxt] != nxt)) {
				q.push({{nxt, tm + 1}, cnt + nxt});
				visited[cnt + nxt] = nxt;
			}
		}

		// delete
		if (cnt == 1) continue;
		if (cnt - 1 == s) {
			return tm + 1;
		} else {
			if (cnt + nxt < 2024 && (visited[cnt - 1] != nxt))	 {
				q.push({{nxt, tm + 1}, cnt - 1});
				visited[cnt - 1] = nxt;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	cout << bfs();

	return 0;
}