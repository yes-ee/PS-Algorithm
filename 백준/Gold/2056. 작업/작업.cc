// topological sort

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, r;
int arr[10001];
int ans[10001];
queue<int> q;
vector<int> v[10001];
int in_degree[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> arr[i] >> b;

		while (b--) {
			int c;
			cin >> c;
			v[c].push_back(i);
			in_degree[i]++;
		}
	}

	for (int i = 1; i<= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			ans[i] = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		int a = q.front();
		q.pop();

		for (int c : v[a]) {
			ans[c] = max(ans[c], ans[a] + arr[c]);
			in_degree[c]--;
			if (in_degree[c] == 0) {
				q.push(c);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		r = max(r, ans[i]);
	}

	cout << r;
	
	return 0;
}