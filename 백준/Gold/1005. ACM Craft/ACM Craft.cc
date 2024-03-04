#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, k, w;
int time[1001];
int in[1001];
int mt[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> v[n + 1];
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
			in[i] = 0;
			mt[i] = 0;
		}
		
		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			in[b]++;
		}

		cin >> w;

		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.push(i);
				mt[i] = time[i];
			}
		}

		for (int i = 0; i < n; i++) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < v[cur].size(); j++) {
				int nxt = v[cur][j];
				mt[nxt] = max(mt[nxt], mt[cur]);
				in[nxt]--;
				if(in[nxt] == 0) {
					mt[nxt] += time[nxt];
					q.push(nxt);
				}
			}
		}

		cout << mt[w] << "\n";
	}
}