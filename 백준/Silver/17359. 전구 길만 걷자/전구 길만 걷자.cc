#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;
int ans=1e9;
int visited[10];

void dfs(int cnt, int chg, int pre) {
	if (cnt==n) {
		ans = min(ans, chg);
		return;
	}

	for (int i = 0;i<n;i++) {
		if(visited[i]) continue;

		int sm=0;
		if (cnt && v[pre][v[pre].size()-1] != v[i][0]) sm=1;	
		visited[i] = 1;
		dfs(cnt+1, chg+sm,i);
		visited[i] =0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string s;
	for (int i =0;i<n;i++) {
		cin >> s;
		v.push_back(s);
	}

	dfs(0, 0,-1);


	for (auto i : v) {
		int cur=i[0];
		for (char c : i) {
			if (cur != c) {
				ans++;
				cur=c;
			}
		}
	}

	cout<<ans;
	return 0;
}