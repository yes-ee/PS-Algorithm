#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;
long long d[501];
vector<pair<int, pair<int, int>>> edge;

bool bell(int start) {
	d[start] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a = edge[j].first;
			int b = edge[j].second.first;
			int c = edge[j].second.second;

			if (d[a] == INF)
				continue;

			if (d[b] > d[a] + c) {
				d[b] = d[a] + c;

				if (i == n-1)
					return true;
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge.push_back({a, {b, c}});
	}

	for (int i = 1; i < 501; i++)
		d[i] = INF;

	bool ret = bell(1);

	if (ret) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		if (d[i] == INF)
			cout << "-1\n";
		else
			cout << d[i] << "\n";
	}

	return 0;
}