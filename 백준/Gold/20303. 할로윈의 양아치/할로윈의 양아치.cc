// union find

#include <iostream>
#include <vector>

using namespace std;
using pii=pair<int, int>;

int n, m, k; 
long long ans;
int p[30001];
long long cnt[30001];
int child[30001];
vector<pii> v;
long long dp[30001][3001];

int find(int a) {
	if (p[a] == a) return a;

	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	p[b] = a;

	cnt[a] += cnt[b];
	child[a] += child[b];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		child[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		cin >> cnt[i];
	}

	for (int i =0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}


	for (int i = 1; i <= n; i++) {
		int par = find(i);
		if (par != i) continue;

		if (child[par] >= k) continue;

		v.push_back({child[par], cnt[par]});
	}

	int g = v.size();

	for (int i = 1; i <= g; i++) {
		for (int j = 1; j <= k - 1; j++) {
			int curnum = v[i - 1].first;
			int curval = v[i - 1].second;
			if (j < curnum) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curnum] + curval);
			}
		}
	}


	cout << dp[g][k - 1];

	return 0;
}