#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int t, n, m, cnt;
queue<pii> q;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--) {
		while(!q.empty())
			q.pop();
		while(!pq.empty())
			pq.pop();

		cnt = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int imp;

			cin >> imp;
	
			pq.push(imp);

			if (i == m)
				q.push({imp, 1});
			else
				q.push({imp, 0});
		}

		while (1) {
			int imp = q.front().first;
			int sel = q.front().second;
			q.pop();

			if (imp == pq.top()) {
				cnt++;
				pq.pop();
				if (sel) {
					cout << cnt << "\n";
					break;
				}
			}
			q.push({imp, sel});
		}
	}
}