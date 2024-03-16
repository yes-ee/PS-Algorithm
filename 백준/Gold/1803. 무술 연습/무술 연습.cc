#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
queue<int> q;
int op[100001];
int res[100001];
int in[100001];
int visited[100001];

void topology() {
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (visited[op[x]])
			continue;

		visited[op[x]] = 1;
		res[op[x]] = 0;

		int nx = op[op[x]];
		in[nx]--;
		if (in[nx] == 0) {
			q.push(nx);
			visited[nx] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	int len = m + n;

	for (int i = 1; i <= len; i++) {
		res[i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		op[i] = a + m;
		in[a + m]++;
	}

	for (int i = m + 1; i <= len; i++) {
		int a;
		cin >> a;
		op[i] = a;
		in[a]++;
	}

	for (int i = 1; i <= len; i++) {
		if (in[i] == 0) {
			q.push(i);
			visited[i] = 1;
		}
	}

	topology();

	for (int i = 1; i <= len; i++) {
		if (!visited[i]) {  // 사이클
			visited[i] = 1;
			in[i]--;
			if (in[i] == 0) {
				q.push(i);
				topology();
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << res[i];
	}
	cout << "\n";
	for (int i = m + 1; i <= len; i++) {
		cout << res[i];
	}

	return 0;
}