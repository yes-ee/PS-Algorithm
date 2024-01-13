#include <bits/stdc++.h>
#define MAX 200001

using namespace std;
typedef pair<int, double> P;

int h[MAX];
double visited[MAX];
vector<int> v[MAX];
queue<P> q;
double ans;
double mh;	//새로 튀긴 높이

void bfs(double k) {
	while (!q.empty()) {
		int x = q.front().first;
		double ph = q.front().second;	//나한테 오기 직전 튀긴 높이
		// cout << x << " " << ph << "\n";
		q.pop();
		if (x == k) {
			ans = 1;
			return;
		}

		double mh = (h[x] + ph) / 2.0;	//나한테 튀었을 때 다음 높이
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];

			if (visited[nx] < mh) {
				if (mh >= h[nx]) {
					visited[nx] = mh;
					// double ph = (mh + h[nx]) / 2;
					q.push({nx, mh});
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		h[i] = a;
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		// for (int j = 1; j <= n; j++)
		// 	cout << visited[j] << " ";
		// cout << endl;
		if (ans) {
			// cout << "ans ";
			break;
		}
		while (!q.empty())
			q.pop();

		if (i == k)
			continue;
		if (visited[i] > h[i]) {
			// cout << "2" << visited[i] << "\n";
			continue;
		}

		q.push({i, h[i]});
		bfs(k);
	}
	// cout << endl;

	cout << ans;
	return 0;
}