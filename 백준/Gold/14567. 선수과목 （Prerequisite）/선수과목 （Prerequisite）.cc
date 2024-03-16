#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int t[1001], in[1001];
vector<int> v[1001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		t[i]= 1;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i<= n; i++) {
		if (in[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int c : v[x]) {
			t[c] = max(t[c], t[x] + 1);
			in[c]--;
			if (in[c] == 0) {
				q.push(c);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}